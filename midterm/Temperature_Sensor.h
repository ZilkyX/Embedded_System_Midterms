//Prevents redefinition if not defined
#ifndef TEMPERATURE_SENSOR_H
//Define
#define TEMPERATURE_SENSOR_H

//Libraries needed for declaration
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
