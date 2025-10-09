//Prevents reddefinition if not defined
#ifndef TEMPERATURE_SENSOR_H
//define
#define TEMPERATURE_SENSOR_H

#include <OneWire.h>
#include <DallasTemperature.h>
#include <Arduino.h>

class TemperatureSensor {
  //Member Function Interface  
  private:
    byte _pin;
    OneWire* _oneWire;
    DallasTemperature* _sensors;
   // Member Variable Interface
  public:
    TemperatureSensor(byte pin);
    void begin();
    float getFahrenheit();
    float getCelsius();
};

#endif
