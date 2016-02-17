/*
 * Microdia image capture program
 * Copyright (C) 2008 Daniel Drake <dsd@gentoo.org>
 * Copyright (c) 2008 Vasily Khoruzhick <anarsoul@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libusb.h>
#include <unistd.h>

#include "sn9c20x.h"
#include "ov965x.h"
#include "microdia_dev.h"

libusb_device_handle *handle;

static void __msg(FILE *stream, const char *msg, va_list args)
{
	vfprintf(stream, msg, args);
	fprintf(stream, "\n");
}

static void die(const char *msg, ...)
{
	va_list args;
	va_start(args, msg);
	__msg(stderr, msg, args);
	va_end(args);
	exit(1);
}

void msg(const char *msg, ...)
{
	va_list args;
	va_start(args, msg);
	__msg(stdout, msg, args);
	va_end(args);
}

static int aborted = 0;
static FILE *outfile;

static void capture_callback(struct libusb_transfer *transfer)
{
	int i;
	unsigned char header[] = {0xff, 0xff, 0x00, 0xc4, 0xc4, 0x96};
	//msg("capture_callback status %d", transfer->status);

	for (i = 0; i < 10; i++) {
		struct libusb_iso_packet_descriptor *desc =
			&transfer->iso_packet_desc[i];
		unsigned char *pbuf = transfer->buffer + (i * 3072);
		if (desc->status != 0) {
			msg("packet %d has status %d", i, desc->status);
			continue;
		}
		if (memcmp(transfer->buffer + (i * 3072), header, 6) == 0) {
			msg("Header found!\n");
		}
		fwrite(transfer->buffer + (i * 3072), 1, desc->actual_length, outfile);

	}
	if (!aborted)
		libusb_submit_transfer(transfer);
}

static struct libusb_transfer *alloc_capture_transfer(void)
{
	struct libusb_transfer *transfer = libusb_alloc_transfer(10);
	int i;

	if (!transfer)
		die("transfer alloc failure");
	transfer->dev_handle = handle;
	transfer->endpoint = 0x81;
	transfer->type = LIBUSB_TRANSFER_TYPE_ISOCHRONOUS;
	transfer->timeout = 5000;
	transfer->buffer = malloc(30720);
	transfer->length = 30720;
	transfer->callback = capture_callback;
	transfer->num_iso_packets = 10;
	
	for (i = 0; i < 10; i++) {
		struct libusb_iso_packet_descriptor *desc =
			&transfer->iso_packet_desc[i];
		desc->length = 3072;
	}
	return transfer;

}

static void start_capture_loop(void)
{
	struct libusb_transfer *transfer1, *transfer2;
	int r;

	transfer1 = alloc_capture_transfer();
	transfer2 = alloc_capture_transfer();
	msg("submit image transfers");
	r = libusb_submit_transfer(transfer1);
	if (r < 0)
		die("capture submit fail %d", r);
	r = libusb_submit_transfer(transfer2);
	if (r < 0)
		die("capture submit fail %d", r);
}


static void sighandler(int signum)
{
	msg("got signal %d", signum);
	aborted = 1;
}

static void do_capture(void)
{
	libusb_set_interface_alt_setting(handle, 0, 8);
	start_capture_loop();

	while (!aborted)
		if (libusb_handle_events() < 0)
			break;

	msg("shutting down");
	libusb_set_interface_alt_setting(handle, 0, 0);
}


int main(int argc, char *argv[])
{
	microdia_dev *devices[] = {&microdia_624f, &microdia_624e, &microdia_6242, &microdia_6270, NULL};
	microdia_dev *opened_device;
	int i, r;

	if (argc != 2) {
		die("Usage: %s output_filename", argv[0]);
	}

	outfile = fopen(argv[1], "w");
	if (!outfile) {
		die("Can't open file %s for writing", argv[1]);
	}
	
	libusb_init();

	for (i = 0; i < sizeof(devices) / sizeof(*devices); i++) {
		opened_device = devices[i];
		handle = libusb_open_device_with_vid_pid(opened_device->vid, opened_device->pid);
		if (handle) {
			msg("Opened device: %x:%x", opened_device->pid, opened_device->vid);
			break;
		}
	}
	if (!handle) {
		fclose(outfile);
		die("couldn't open device");
	}

	r = libusb_claim_interface(handle, 0);
	if (r < 0) {
		fclose(outfile);
		die("couldn't claim interface");
	}

	opened_device->init(NULL);
	opened_device->start_stream(NULL);

	struct sigaction sigact;
	sigact.sa_handler = sighandler;
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	sigaction(SIGINT, &sigact, NULL);
	sigaction(SIGTERM, &sigact, NULL);
	sigaction(SIGQUIT, &sigact, NULL);
	
	do_capture();
	opened_device->stop_stream(NULL);
exit:
	fclose(outfile);
	libusb_close(handle);
	libusb_exit();
	return 0;
}

