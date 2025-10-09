// Library Imports
#include <OneWire.h> // Library for 1-Wire protocol
#include <DallasTemperature.h> // Library for Dallas temperature sensors
#include <Adafruit_GFX.h> // Adafruit graphics library
#include <Adafruit_SSD1306.h> // Adafruit SSD1306 OLED display driver
#include "Temperature_Sensor.h" // Custom header for TemperatureSensor class
#include "config.h"  // Custom project config

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
TemperatureSensor tempSensor(DS18B20_PIN);

// Initializes serial, temperature sensor, and OLED display.
// Shows startup message on display.
void setup() {
  Serial.begin(9600);

  tempSensor.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found!");
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Temperature Sensor");
  display.display();
  delay(1000);
}

// Reads temperatures in C and F, prints to serial, and updates OLED display.
void loop() {
  float tempC = tempSensor.getCelsius();
  float tempF = tempSensor.getFahrenheit();

  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print(" C  |  ");
  Serial.print(tempF);
  Serial.println(" F");

  display.clearDisplay();
  display.setCursor(0, 10);
  display.setTextSize(2);
  display.print(tempC, 1);
  display.print(" C");

  display.setCursor(0, 35);
  display.setTextSize(2);
  display.print(tempF, 1);
  display.print(" F");

  display.display();

  delay(1000);
}
