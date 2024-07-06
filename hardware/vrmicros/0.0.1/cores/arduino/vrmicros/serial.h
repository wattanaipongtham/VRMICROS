#ifndef	__VRMICROS_SERIAL
#define __VRMICROS_SERIAL

#include <stdint.h>
#include <string.h>
#include "usbd_cdc_if.h"

class Serial {
  public:
    void print(const char* msg);
    void println(const char* msg);
};

#endif