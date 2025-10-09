//Prevents reddefinition if not defined
#ifndef TEMPERATURE_SENSOR_H
//define
#define TEMPERATURE_SENSOR_H

#include <OneWire.h>
#include <DallasTemperature.h>


class TemperatureSensor {
   // Member Variable Interface 
  private:
    byte _pin;
    OneWire* _oneWire;
    DallasTemperature* _sensors;
   
  //Member Function Interface  
  public:
    TemperatureSensor(byte pin);
    void begin();
    float getFahrenheit();
    float getCelsius();
};

#endif
