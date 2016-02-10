#include <stdio.h>
#include <stdint.h>
#include "types.h"
#include "usb.h"
#include "compat.h"
#include "pthread.h"
#include <time.h>

pthread_t usb_poll_thread;

extern const char *firmware[];

void hr_print(uint64_t value)
{
    const char *suffix=" KMGTP????????";
    double v;
    int i=0;
    v=value*1.0;
    while(v>1000.0)
    {
	v=v/1024.0;
	i++;
    }
    printf("%.2f %c",v,suffix[i]);
}


void parse_data(void* buffer, uint32_t length)
{
	static uint64_t summ;
	static uint64_t counter;
	static struct timeval tv,tv_old;
        double delta;
        uint64_t speed=0;
	summ+=length;
	counter++;
	if(counter>=1024)
	{
	    if ((tv_old.tv_sec+tv_old.tv_usec)!=0)
	    {
		tv_old.tv_sec=tv.tv_sec;
		tv_old.tv_usec=tv.tv_usec;
		gettimeofday(&tv,NULL);
		delta=((tv.tv_sec-tv_old.tv_sec)*1.0)+(tv.tv_usec-tv_old.tv_usec)/1000000.0;
		speed=(uint64_t)((length*1024)/delta);
	    }
	    else gettimeofday(&tv_old,NULL);
	    counter=0;
	    hr_print(summ);
	    printf("B transfered @ ");
	    hr_print(speed);
	    printf("B/s\n");
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
