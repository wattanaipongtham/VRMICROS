#ifndef Arduino_H
#define Arduino_H

#include "gpio.h"
#include "gpio.c"

extern "C" {
  void delay(uint32_t);
}

#endif