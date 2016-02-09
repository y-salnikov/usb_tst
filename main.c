#include <stdio.h>
#include <stdint.h>
#include "types.h"
#include "usb.h"
#include "compat.h"
#include "pthread.h"

pthread_t usb_poll_thread;

extern const char *firmware[];


void parse_data(void* buffer, uint32_t length)
{
	static uint64_t summ;
	static uint64_t counter;
	summ+=length;
	counter++;
	if(counter>=1024)
	{
		counter=0;
		printf("%lu bytes transfered\n",summ);
	}
}

int main(void)
{
	int iret;
	usb_transfer_context_type *utc;

	utc=usb_init(firmware, 0x0925,0x3881);

	if(utc==NULL) return 3;
	
	iret = pthread_create( &usb_poll_thread, NULL, usb_thread_function, (void*) utc);
	     if(iret)
	     {
	         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret);
	         return 3;
	     }
	while(1)
	{
		SLEEP(10);
		if(utc->usb_stop_flag!=0) return 0;
	}
	return 0;
}

