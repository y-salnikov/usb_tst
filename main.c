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
	static struct timeval tv,tv_old,tv2,tv2_old;
        double delta;
        double speed=0.0;
	summ+=length;
	counter++;
	if((tv2_old.tv_sec==0)&&(tv2_old.tv_usec==0)) gettimeofday(&tv2_old,NULL);
	if((tv.tv_sec==0)&&(tv.tv_usec==0)) gettimeofday(&tv,NULL);
	gettimeofday(&tv2,NULL);
	
	if( ((tv2.tv_sec-tv2_old.tv_sec)*1000000)+(tv2.tv_usec-tv2_old.tv_usec)>=1000000 )
	{
		gettimeofday(&tv2_old,NULL);	
		tv_old.tv_sec=tv.tv_sec;
		tv_old.tv_usec=tv.tv_usec;
		gettimeofday(&tv,NULL);
		delta=((tv.tv_sec-tv_old.tv_sec)*1000000)+(tv.tv_usec-tv_old.tv_usec);
		speed=((length*counter*1000000)/(delta));
	    
	    counter=0;
	    printf(" \033[0G\033[32;1m");
	    hr_print(summ);
	    printf("B \033[30;0mtransfered @ \033[35;1m");
	    hr_print((uint64_t)speed);
	    printf("B/s\033[30;0m  ");
	    fflush(stdout);
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
