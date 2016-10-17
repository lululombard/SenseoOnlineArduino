#include "Pump.h"

Pump::Pump(int pin_pump) {
  this->pin_pump = pin_pump;
  pinMode(pin_pump, OUTPUT);
}
void Pump::off() {
  digitalWrite(pin_pump, LOW);
}
void Pump::on() {
  digitalWrite(pin_pump, HIGH);
}
boolean Pump::state() {
  return digitalRead(pin_pump);
}
