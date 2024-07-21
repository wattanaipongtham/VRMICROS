#include "serial.h"
#include <stdint.h>
#include <string>
#include "usbd_cdc_if.h"

#define crnl "\r\n"
extern "C"{
	void delay(uint32_t);
}

int i=0;

void Serial::print(const char* msg){
	uint8_t* print_buf[128];
	uint8_t len = strlen(msg);

	memcpy(print_buf, msg, strlen(msg));

	CDC_Transmit_FS((uint8_t*)print_buf, len);
}
void Serial::println(const char* msg){
	uint8_t* println_buf[128];
	uint8_t len = strlen(msg);

	memcpy(println_buf, msg, strlen(msg));
	memcpy(println_buf+len, "\r\n", 2);
	
	CDC_Transmit_FS((uint8_t*)println_buf, len+2);
}