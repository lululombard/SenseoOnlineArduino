#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
  public:
    Button(int, int, int);
    boolean Button::get_main();
    boolean Button::get_a();
    boolean Button::get_b();
  private:
    int pin_main, pin_a, pin_b;
};

#endif
