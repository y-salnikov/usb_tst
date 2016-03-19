#include "libusb.h"

typedef struct usb_transfer_context_struct
{
	struct libusb_config_descriptor *conf;
	libusb_device_handle *device_h;
	libusb_device *device;
	uint8_t active_transfers;
	unsigned char endpoint;
	uint8_t usb_transfer_cb_served;
	uint8_t usb_stop_flag;
	uint8_t *control_buffer;
	int	vid;
	int pid;
	int USB_BUF_SIZE;
	int N_OF_TRANSFERS;
	int usb_timeout;
	uint8_t *tmp_buffer;
	uint8_t delay;
	
}usb_transfer_context_type;


