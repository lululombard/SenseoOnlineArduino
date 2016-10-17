#ifndef Led_h
#define Led_h

#include "Arduino.h"

class Led
{
  public:
    Led(int, int, int);
    void off();
    void green();
    void red();
    void orange();
    void raw_red(int dim);
    void raw_green(int dim);
  private:
    int pin_gnd, pin_red, pin_green;
};

#endif
