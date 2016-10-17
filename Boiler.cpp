#include "Boiler.h"

int max_temp = 410;

Boiler::Boiler(int pin_boiler, int pin_sensor) {
  this->pin_boiler = pin_boiler;
  this->pin_sensor = pin_sensor;
  pinMode(pin_boiler, OUTPUT);
}
void Boiler::off() {
  digitalWrite(pin_boiler, LOW);
}
void Boiler::on() {
  digitalWrite(pin_boiler, HIGH);
}
boolean Boiler::state() {
  return digitalRead(pin_boiler);
}
boolean Boiler::is_max_temp() {
  return (get_temp_raw()>=max_temp);
}
int Boiler::get_temp() {
  int temp_about = (get_temp_raw()/7);
  if (temp_about < 20) return 20;
  if (temp_about > 99) return 99;
  return (temp_about);
}
int Boiler::get_temp_raw() {
  return analogRead(pin_sensor);
}
int Boiler::get_temp_max() {
  return max_temp;
}

