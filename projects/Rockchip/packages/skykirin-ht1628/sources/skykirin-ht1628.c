#include "skykirin-ht1628.h"


void set_disp_on(int fd)
{
	if( ioctl(fd,HT1628_DISP_ON,NULL)){
		printf("ht1628 display on error\n");
	}else{
		printf("ht1628 HT1628_DISP_ON on sucess\n");
	}
}

void set_disp_off(int fd)
{
	if( ioctl(fd,HT1628_DISP_OFF,NULL)){
		printf("ht1628 display off\n");
	}else{
		printf("ht1628 HT1628_DISP_OFF off sucess\n");
	}
		
}


void set_disp_wlan3_on(int fd)
{
	if( ioctl(fd,HT1628_DISP_WIFI_ON_L3,NULL)){
		printf("ht1628 wlan3 on\n");
	}else{
		printf("ht1628 HT1628_DISP_WIFI_ON_L3 off sucess\n");
	}
}
void set_disp_wlan4_on(int fd)
{
	if( ioctl(fd,HT1628_DISP_WIFI_ON_L4,NULL)){
		printf("ht1628 wlan4 on\n");
	}else{
		printf("ht1628 HT1628_DISP_WIFI_ON_L4 off sucess\n");
	}
}
void set_disp_lan_on(int fd)
{
	if( ioctl(fd,HT1628_DISP_SET_LAN_ON,NULL)){
		printf("ht1628 lan on\n");
	}else{
		printf("ht1628 HT1628_DISP_SET_LAN_ON off sucess\n");
	}
}
void set_disp_lan_off(int fd)
{
	if( ioctl(fd,HT1628_DISP_SET_LAN_OFF,NULL)){
		printf("ht1628 lan off\n");
	}else{
		printf("ht1628 HT1628_DISP_SET_LAN_OFF off sucess\n");
	}
}
void set_disp_dot_on(int fd)
{
	if( ioctl(fd,HT1628_DISP_DOT_ON,NULL)){
		printf("ht1628 DOT on\n");
	}else{
		printf("ht1628 HT1628_DISP_DOT_ON off sucess\n");
	}
}


void set_disp_wifi_on_half(int fd)
{
	if( ioctl(fd,HT1628_DISP_WIFI_ON_HALF,NULL)){
		printf("ht1628 HT1628_DISP_WIFI_ON_HALF on\n");
	}else{
		printf("ht1628 HT1628_DISP_WIFI_ON_HALF on sucess\n");
	}
}
void set_disp_wifi_on_full(int fd)
{
	if( ioctl(fd,HT1628_DISP_WIFI_ON_FULL,NULL)){
		printf("ht1628 HT1628_DISP_WIFI_ON_FULL on\n");
	}else{
		printf("ht1628 HT1628_DISP_WIFI_ON_FULL off sucess\n");
	}
}
void set_disp_wifi_off(int fd)
{
	if( ioctl(fd,HT1628_DISP_WIFI_OFF,NULL)){
		printf("ht1628 HT1628_DISP_WIFI_OFF on\n");
	}else{
		printf("ht1628 HT1628_DISP_WIFI_OFF off sucess\n");
	}
}



void set_display_time(int fd,char* buf)
{
	
	if(ioctl(fd,HT1628_DISP_SET_TIME,buf)){
		printf("set buff error");
	}else{
		printf("set buff success %s ",buf);
	}
}


void start_time_daemon(int fd){
	
	int need_update=0;
	struct tm *current_time;
	time_t rawtime;
	char *disp_buff;
	disp_buff = malloc(4*sizeof(unsigned short));
    int hour,min;
    set_disp_dot_on(fd);
    //set_disp_lan_on(fd);
    
	while(1){
		        time(&rawtime);
			current_time = localtime(&rawtime);	
			hour = current_time->tm_hour;
			min = current_time->tm_min;
			sprintf(disp_buff,"%2d%2d",hour,min);
			ioctl(fd,HT1628_DISP_SET_TIME,disp_buff);

		sleep(60);
	}
	
	
	
	
}


int main(int argc,char* argv[])
{
	char* filename = "/dev/skykirin-ht1628";
	int fd;
	char* buf;
	enum {
		doton,
		lanon,
		lanoff,
		wlan3on,
		wlan4on,
		whalf,
		wfull,
		woff,
		dispon,
		dispoff,
		buff,
		daemon
	}options;

	if (argc == 1){
		options = doton;
	}else if (argc == 2){
		if (strcmp(argv[1],"-don") == 0){
			options = dispon;
		}else if (strcmp(argv[1],"-doff") == 0){
			options = dispoff;
		}else if (strcmp(argv[1],"-lon") == 0){
			options = lanon;
		}else if (strcmp(argv[1],"-loff") == 0){
			options = lanoff;
		}else if (strcmp(argv[1],"-w3") == 0){
			options = wlan3on;
		}else if (strcmp(argv[1],"-w4") == 0){
			options = wlan4on;
		}else if (strcmp(argv[1],"-whalf") == 0){
			options = whalf;
		}else if (strcmp(argv[1],"-wfull") == 0){
			options = wfull;
	    }else if (strcmp(argv[1],"-woff") == 0){
			options = woff;
		}else if (strcmp(argv[1],"-dot") == 0){
			options = doton;
	    }else if (strcmp(argv[1],"-d") == 0){
			options = daemon;

		}else {
			printf("parameter error\n");
			return 1;
		}
	}else if (argc ==3 ){
		  if (strcmp(argv[1],"-buff") == 0){
			options = buff;
			buf = argv[2];
		}
	}else {
		printf("usage: skykirin-ht1628 [-don][-doff][-lon][-loff][-w1][-w2]][-w3][-w4][-dot][-whalf][-wfull][-woff] \n");
		return 1;
		}
	fd = open(filename,O_RDWR);
	switch (options) {
			case dispon:
				set_disp_on(fd);
				break;
			case dispoff:
				set_disp_off(fd);
				break;
			case doton:
				set_disp_dot_on(fd);
				break;
			case lanon:
				set_disp_lan_on(fd);
				break;
			case lanoff:
				set_disp_lan_off(fd);
				break;
			case wlan3on:
				set_disp_wlan3_on(fd);
				break;
			case wlan4on:
				set_disp_wlan4_on(fd);
				break;
			case whalf:
				set_disp_wifi_on_half(fd);
				break;
			case wfull:
				set_disp_wifi_on_full(fd);
				break;
			case woff:
				set_disp_wifi_off(fd);
				break;
			case buff:
				set_display_time(fd,buf);
				break;
			case daemon:
				start_time_daemon(fd);
				break;
			default:
				break;
	}
		close(fd);
		return 0;
		
		
		
}
		
			
	
	
	
	
	
	
	
	
	
	
	














