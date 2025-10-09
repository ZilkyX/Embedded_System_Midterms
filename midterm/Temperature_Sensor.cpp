// Own Header
#include "Temperature_Sensor.h"
//Additional libraries needed for implementation
#include <Arduino.h>

// Constructor: Initializes the temperature sensor with the specified pin.
TemperatureSensor::TemperatureSensor(byte pin) {
  _pin = pin;
  _oneWire = new OneWire(_pin);
  _sensors = new DallasTemperature(_oneWire);
}

// Initializes the DallasTemperature sensors.
void TemperatureSensor::begin() {
  _sensors->begin();
}

// Requests temperature and returns it in Fahrenheit.
float TemperatureSensor::getFahrenheit() {
  _sensors->requestTemperatures();
  float tempC = _sensors->getTempCByIndex(0);
  float tempF = _sensors->toFahrenheit(tempC);
  return tempF;
}

// Requests temperature and returns it in Celsius.
float TemperatureSensor::getCelsius() {
  _sensors->requestTemperatures();
  float tempC = _sensors->getTempCByIndex(0);
  return tempC;
}
