#include "serial.h"
#include <stdint.h>
#include <string>
#include "usbd_cdc_if.h"
//#include "timebase.h"
extern "C"{
	void delay(uint32_t);
}
void Serial::print(const char* msg){
	CDC_Transmit_FS((uint8_t*)msg, strlen(msg));
	delay(1);
}
void Serial::println(const char* msg){
	char* serialMsg;
	sprintf(serialMsg, "%s\r\n", msg);
	CDC_Transmit_FS((uint8_t*)serialMsg, strlen(serialMsg));
	delay(1);
}