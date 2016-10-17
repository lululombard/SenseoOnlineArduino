#include <LiquidCrystal_I2C.h>

#include "Led.h"
#include "Button.h"
#include "Boiler.h"
#include "Pump.h"
#include "SerialRpi.h"
#include "CustomChars.h"

Led led(9,10,11);
Button button(4,3,2);
Boiler boiler(7, A0);
Pump pump(6);
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(115200);
  SerialRpi::serial_init();
  CustomChars::init_lcd(lcd);
  lcd.setCursor(1,0);
  lcd.print("Senseo Online v2.0");
}

void loop() {
  delay(300);
  while(Serial.available()) {
    char character = Serial.read();
    if (character == 'c') cycle();
    if (character == 'b') c_boiler();
    if (character == 'p') c_pump();
  }
  if (button.get_main()) cycle();
  if (button.get_a()) c_boiler();
  if (button.get_b()) c_pump();
  lcd.setCursor(0,1);
  lcd.print("En attente d'ordres!");
  SerialRpi::serial("Waiting", boiler.get_temp());
  actuTempLcd();
  boiler.off();
  pump.off();
  led.green();
}

void cycle() {
  c_boiler();
  c_pump();
}

void c_boiler() {
  int oldpercent=0;
  int startpercent=boiler.get_temp_raw();
  CustomChars::update_pbar(lcd, 0);
  lcd.setCursor(2,2);
  lcd.print("Chauffe en cours");
  SerialRpi::serial("Heating", boiler.get_temp());
  boiler.on();
  led.red();
  delay(1000);
  while (!boiler.is_max_temp()) {
    if(Serial.available() || button.get_main()) break;
    int percent = (boiler.get_temp_raw()-startpercent)*100/(boiler.get_temp_max()-startpercent+10);
    if (percent < 0) percent = 0;
    if (percent > 100) percent = 100;
    if (percent > oldpercent) {
      CustomChars::update_pbar(lcd, percent);
      actuTempLcd();
    }
  }
  boiler.off();
  CustomChars::clear_line(lcd, 1);
  CustomChars::clear_line(lcd, 2);
  delay(300);
}

void c_pump() {
  led.red();
  lcd.setCursor(2,2);
  lcd.print("Cafe en cours...");
  delay(1000);
  for(int i=0;i<100;i++) {
    pump.on();
    if(Serial.available() || button.get_main()) break;
    SerialRpi::serial("Pumping", i);
    CustomChars::update_pbar(lcd, i);
    actuTempLcd();
    delay(500);
  }
  pump.off();
  CustomChars::clear_line(lcd, 1);
  CustomChars::clear_line(lcd, 2);
  delay(300);
}

void actuTempLcd() {
  lcd.setCursor(2,3);
  lcd.print("Bouilleur : ");
  lcd.print(boiler.get_temp());
  lcd.write(6);
  lcd.print("C");
}

