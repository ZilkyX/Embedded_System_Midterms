#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void sendTemperature() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  float tempF = sensors.toFahrenheit(tempC);

  Serial.print("Temp C: ");
  Serial.print(tempC);
  Serial.print(" | Temp F: ");
  Serial.println(tempF);
}

void setup() {
  Serial.begin(115200);
  sensors.begin();
}

void loop() {
  sendTemperature();
}