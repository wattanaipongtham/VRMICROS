#include "serial.h"
#include <stdint.h>
#include <string>
#include "usbd_cdc_if.h"
//#include "timebase.h"
extern "C"{
	void delay(uint32_t);
}
uint8_t print_buf[128];
int i=0;
void Serial::print(const char* msg){
	while(i<strlen(msg)){
		print_buf[i] = *msg;
		msg++;
	}
	//sprintf(print, "%s", msg);
	CDC_Transmit_FS((uint8_t*)print, strlen(print));
	while(!((USB->ISTR)&(1U<<15))){}
}
void Serial::println(const char* msg){
	char* serialMsg;
	sprintf(serialMsg, "%s\r\n", msg);
	CDC_Transmit_FS((uint8_t*)serialMsg, strlen(serialMsg));
	while(!((USB->ISTR)&(1U<<15))){}
}