#include "Button.h"

Button::Button(int pin_main, int pin_a, int pin_b) {
  this->pin_main = pin_main;
  this->pin_a = pin_a;
  this->pin_b = pin_b;
  pinMode(pin_main, INPUT);
  pinMode(pin_a, INPUT);
  pinMode(pin_b, INPUT);
}
boolean Button::get_main() {
  return digitalRead(pin_main);
}
boolean Button::get_a() {
  return digitalRead(pin_a);
}
boolean Button::get_b() {
  return digitalRead(pin_b);
}

