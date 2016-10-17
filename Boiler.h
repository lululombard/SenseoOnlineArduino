#ifndef Boiler_h
#define Boiler_h

#include "Arduino.h"

class Boiler
{
  public:
    Boiler(int, int);
    void off();
    void on();
    boolean state();
    boolean is_max_temp();
    int get_temp();
    int get_temp_raw();
    int get_temp_max();
  private:
    int pin_boiler, pin_sensor;
};

#endif
