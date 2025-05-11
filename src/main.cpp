#include <Arduino.h>
#include <WaterHeater.hpp>

void setup() {
  cWaterHeater *W1 = new cWaterHeater();
  W1->StartHeater(); 
}

void loop() {

}

