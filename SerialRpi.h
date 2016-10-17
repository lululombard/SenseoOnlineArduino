#ifndef SerialRpi_h
#define SerialRpi_h

#include "Arduino.h"

class SerialRpi
{
  public:
    static void serial(char*, int);
    static void serial_init();
};

#endif
