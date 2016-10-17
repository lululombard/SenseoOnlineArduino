#include "CustomChars.h"

void CustomChars::init_lcd(LiquidCrystal_I2C lcd) {
  lcd.begin();
  lcd.backlight();
  
  byte start_empty[8] = { B01111, B10000, B10000, B10000, B10000, B10000, B10000, B01111 };
  byte start_full[8] = { B01111, B10000, B10111, B10111, B10111, B10111, B10000, B01111 };

  byte mid_empty[8] = { B11111, B00000, B00000, B00000, B00000, B00000, B00000, B11111 };
  byte mid_full[8] = { B11111, B00000, B11111, B11111, B11111, B11111, B00000, B11111 };

  byte end_empty[8] = { B11110, B00001, B00001, B00001, B00001, B00001, B00001, B11110 };
  byte end_full[8] = { B11110, B00001, B11101, B11101, B11101, B11101, B00001, B11110 };

  byte celcius[8] = { B00110, B01001, B01001, B00110, B00000, B00000, B00000, B00000 };

  lcd.createChar(0, start_empty);
  lcd.createChar(1, start_full);
  lcd.createChar(2, mid_empty);
  lcd.createChar(3, mid_full);
  lcd.createChar(4, end_empty);
  lcd.createChar(5, end_full);
  lcd.createChar(6, celcius);
}
void CustomChars::update_pbar(LiquidCrystal_I2C lcd, int percent) {
  lcd.setCursor(0,1);
  if (percent < 2) lcd.write(0);
  else lcd.write(1);

  for (int i = 1; i <= 18; i++) {
    lcd.setCursor(i,1);
    if ((percent+3)/5 > i) lcd.write(3);
    else lcd.write(2);
  }
  
  lcd.setCursor(19,1);
  if (percent < 97) lcd.write(4);
  else lcd.write(5);
}
void CustomChars::clear_line(LiquidCrystal_I2C lcd, int line) {
  lcd.setCursor(0, line);
  lcd.print("                    ");
}
