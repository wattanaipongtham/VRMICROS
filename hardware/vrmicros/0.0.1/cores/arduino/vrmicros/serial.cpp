#include "serial.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include "usbd_cdc_if.h"

char crnl[] = "\r\n";
uint8_t* println_buf[128];

extern USBD_HandleTypeDef hUsbDeviceFS;

extern "C"{
	void delay(uint32_t);
}

void Serial::print(const char* msg){
	/*uint8_t* print_buf[128];
	uint8_t len = strlen(msg);

	memcpy(println_buf, msg, strlen(msg));

	CDC_Transmit_FS((uint8_t*)println_buf, len);*/
}
void Serial::println(const char* msg){
	uint8_t len = strlen(msg);
	//memcpy(b, msg, len);
	USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef*)hUsbDeviceFS.pClassData;

  if (hcdc->TxState == 0){
	char a[128];
	char* b =a;
	memcpy(b, msg, 2);
	strcat(b,crnl);
	memcpy(println_buf, b, 6);
	CDC_Transmit_FS((uint8_t*)println_buf, len+2);
  }
	
}