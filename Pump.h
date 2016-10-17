#ifndef Pump_h
#define Pump_h

#include "Arduino.h"

class Pump
{
  public:
    Pump(int);
    void off();
    void on();
    boolean state();
  private:
    int pin_pump;
};

#endif
