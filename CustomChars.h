#ifndef CustomChars_h
#define CustomChars_h

#include "Arduino.h"
#include <LiquidCrystal_I2C.h>

class CustomChars
{
  public:
    static void init_lcd(LiquidCrystal_I2C);
    static void update_pbar(LiquidCrystal_I2C, int);
    static void clear_line(LiquidCrystal_I2C, int);
};

#endif
