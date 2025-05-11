#include <Arduino.h>
#include <WaterHeater.h>

void setup() {
  cWaterHeater *W1 = new cWaterHeater();
  W1->StartHeater(); 
}

void loop() {

}

