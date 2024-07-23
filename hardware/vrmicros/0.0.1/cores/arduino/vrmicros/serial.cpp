#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include "serial.h"
#include "usbd_cdc_if.h"

extern USBD_HandleTypeDef hUsbDeviceFS;

extern "C"{
	void delay(uint32_t);
}

const char crnl[] = "\r\n";
uint8_t* println_buf[128];
char tmp[128];

void Serial::print(const char* msg){
	/*Get message length*/
	uint8_t len = strlen(msg);

	/*Create USB_CDC handler use for checking USB Tx state*/
	USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef*)hUsbDeviceFS.pClassData;

	/*Check USB Tx state if not BUSY then operation string*/
	if (hcdc->TxState == 0){

		/*Copy to serial print buffer*/
		memcpy(println_buf, msg, len);

		/*Send message via USB*/
		CDC_Transmit_FS((uint8_t*)println_buf, len);

		while(hcdc->TxState != 0){}
	}

}

void Serial::print(int msg){
	char tmp_buf[128];

	/*Convert int to string*/
	itoa(msg, tmp_buf, 10);

	/*Get message length*/
	uint8_t len = strlen(tmp_buf);

	/*Create USB_CDC handler use for checking USB Tx state*/
	USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef*)hUsbDeviceFS.pClassData;

	/*Check USB Tx state if not BUSY then operation string*/
	if (hcdc->TxState == 0){

		/*Copy to serial print buffer*/
		memcpy(println_buf, tmp_buf, len);

		/*Send message via USB*/
		CDC_Transmit_FS((uint8_t*)println_buf, len);

		while(hcdc->TxState != 0){}
	}
}

void Serial::println(const char* msg){
	/*Get message length*/
	uint8_t len = strlen(msg);

	/*Create USB_CDC handler use for checking USB Tx state*/
	USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef*)hUsbDeviceFS.pClassData;

	/*Check USB Tx state if not BUSY then operation string*/
	if (hcdc->TxState == 0){

		/*Create temporary string buffer*/
		char tmp_buf[128];

		/*Create temporary string pointer*/
		char* tmp_ptr = tmp_buf;

		/*Clear tmp_buf*/
		memset(tmp_ptr, '\0', sizeof(tmp_ptr));

		/*Copy strings from message to temp location*/
		memcpy(tmp_ptr, msg, len);

		/*Concatenate strings with carrier return and line feed */
		strcat(tmp_ptr,crnl);

		/*Copy to serial print buffer*/
		memcpy(println_buf, tmp_ptr, len+2);

		/*Send message via USB*/
		CDC_Transmit_FS((uint8_t*)println_buf, len+2);

		while(hcdc->TxState != 0){}
	}
	
}

void Serial::println(int msg){

	/*Create USB_CDC handler use for checking USB Tx state*/
	USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef*)hUsbDeviceFS.pClassData;

	/*Check USB Tx state if not BUSY then operation string*/
	if (hcdc->TxState == 0){

		/*Create temporary string buffer*/
		char tmp_buf[128];

		/*Create temporary string pointer*/
		char* tmp_ptr = tmp_buf;

		/*Clear tmp_buf*/
		memset(tmp_ptr, '\0', sizeof(tmp_ptr));

		/*Convert int to string*/
		itoa(msg, tmp_buf, 10);

		/*Copy strings from message to temp location*/
		//memcpy(tmp_ptr, msg, len);

		/*Concatenate strings with carrier return and line feed */
		strcat(tmp_ptr,crnl);

		/*Copy to serial print buffer*/
		memcpy(println_buf, tmp_ptr, strlen(tmp_buf));

		/*Send message via USB*/
		CDC_Transmit_FS((uint8_t*)println_buf, strlen(tmp_buf));

		while(hcdc->TxState != 0){}
	}
}