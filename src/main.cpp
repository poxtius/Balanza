#include <Arduino.h>

#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 4;

HX711 balanza;

void setup() {
  Serial.begin(57600);
  balanza.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  delay(250);
  balanza.set_scale(-1050);
  balanza.tare(10);
 
}

void loop() {

  if (balanza.is_ready()) {
    long reading = balanza.get_units(10);
    //Serial.print("HX711 reading: ");
    Serial.println(reading);
  } else {
    Serial.println("HX711 not found.");
  }

  delay(1000);
  
}

/*void setup() {
  Serial.begin(57600);
  balanza.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {

  if (balanza.is_ready()) {
    long reading = balanza.read();
    //Serial.print("HX711 reading: ");
    Serial.println(reading);
  } else {
    Serial.println("HX711 not found.");
  }

  delay(1000);
  
}*/