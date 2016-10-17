#include "Led.h"

Led::Led(int pin_gnd, int pin_red, int pin_green) {
  this->pin_gnd = pin_gnd;
  this->pin_red = pin_red;
  this->pin_green = pin_green;
  pinMode(pin_gnd, OUTPUT);
  pinMode(pin_red, OUTPUT);
  pinMode(pin_green, OUTPUT);
  digitalWrite(pin_gnd, HIGH);
}
void Led::off() {
  raw_red(0);
  raw_green(0);
}
void Led::green() {
  raw_red(0);
  raw_green(255);
}
void Led::red() {
  raw_red(255);
  raw_green(0);
}
void Led::orange() {
  raw_red(255);
  raw_green(255);
}
void Led::raw_red(int dim) {
  digitalWrite(pin_red, 255-dim);
}
void Led::raw_green(int dim) {
  digitalWrite(pin_green, 255-dim);
}

