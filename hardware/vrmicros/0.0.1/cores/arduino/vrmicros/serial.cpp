#include "serial.h"
#include <stdint.h>
#include <string>
#include "usbd_cdc_if.h"

const char* crnl = "asdf";
uint8_t* println_buf[128];

extern USBD_HandleTypeDef hUsbDeviceFS;

extern "C"{
	void delay(uint32_t);
}

int i=0;
uint8_t print_state = 0;

void Serial::print(const char* msg){
	//uint8_t* print_buf[128];
	uint8_t len = strlen(msg);

	memcpy(println_buf, msg, strlen(msg));

	CDC_Transmit_FS((uint8_t*)println_buf, len);
}
void Serial::println(const char* msg){
	//uint8_t* println_buf[128];
	uint8_t len = strlen(msg);

	USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef*)hUsbDeviceFS.pClassData;

  if (hcdc->TxState == 0){
    memcpy(println_buf, msg, len);
	memcpy(println_buf+len, crnl, 4);
	CDC_Transmit_FS((uint8_t*)println_buf, len+6);
  }
	
}