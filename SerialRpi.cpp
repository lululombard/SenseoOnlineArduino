#include "SerialRpi.h"

void SerialRpi::serial(char* text, int temp) {
  Serial.println("");
  Serial.print(text);
  Serial.print(";");
  Serial.print(temp);
  Serial.print(";!");
}
void SerialRpi::serial_init() {
  for(int i=0;i<100;i++) serial("Booting...", 20);
}
