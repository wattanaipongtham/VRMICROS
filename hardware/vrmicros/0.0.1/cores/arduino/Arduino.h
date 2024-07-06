#ifndef Arduino_H
#define Arduino_H

#include <stdint.h>
#include <string.h>
#include "usbd_cdc_if.h"
#include "serial.h"
#include "gpio.h"
#include "gpio.c"
#include "adc.c"
#include "adc.h"

extern "C" {
  void delay(uint32_t);
}

Serial Serial;

#endif