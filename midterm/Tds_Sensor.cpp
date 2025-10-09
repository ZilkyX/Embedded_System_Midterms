// Own Header
#include "Tds_Sensor.h"
//Additional libraries needed for implementation
#include <Arduino.h>

// Constructor: Initializes the TDS sensor with pin, reference voltage, and sample count.
TDSSensor::TDSSensor(byte pin, float vref, int scount) {
  _pin = pin;
  _vref = vref;
  _scount = scount;
  _analogBuffer = new int[_scount];
  _analogBufferTemp = new int[_scount];
  _analogBufferIndex = 0;
}

// Initializes the sensor pin as input.
void TDSSensor::begin() {
  pinMode(_pin, INPUT);
}

// Computes the median value from an array of integers for noise filtering.
int TDSSensor::getMedianNum(int bArray[], int filterLen) {
  int bTab[filterLen];
  for (int i = 0; i < filterLen; i++)
    bTab[i] = bArray[i];
  int i, j, bTemp;
  // Bubble sort: Swap adjacent elements if out of order.
  for (j = 0; j < filterLen - 1; j++) {
    for (i = 0; i < filterLen - j - 1; i++) {
      if (bTab[i] > bTab[i + 1]) {
        bTemp = bTab[i];
        bTab[i] = bTab[i + 1];
        bTab[i + 1] = bTemp;
      }
    }
  }

  // Return median: Middle value (odd) or average of two middles (even).
  if ((filterLen & 1) > 0) {
    bTemp = bTab[(filterLen - 1) / 2];
  } else {
    bTemp = (bTab[filterLen / 2] + bTab[filterLen / 2 - 1]) / 2;
  }
  return bTemp;
}

// Reads analog values, computes median voltage, applies temperature compensation, and calculates TDS value in ppm.
float TDSSensor::getTDS(float temperature) {
  static unsigned long analogSampleTime = millis();
  if (millis() - analogSampleTime > 40U) {
    analogSampleTime = millis();
    _analogBuffer[_analogBufferIndex] = analogRead(_pin);
    _analogBufferIndex++;
    if (_analogBufferIndex == _scount) _analogBufferIndex = 0;
  }

  static float tdsValue = 0;
  static unsigned long printTime = millis();
  if (millis() - printTime > 800U) {
    printTime = millis();

    for (int i = 0; i < _scount; i++) {
      _analogBufferTemp[i] = _analogBuffer[i];
    }

    // Median voltage: Scale ADC to volts.
    float averageVoltage = getMedianNum(_analogBufferTemp, _scount) * _vref / 1024.0;

    // Temp compensation: Normalize to 25°C (2% per °C adjustment).
    float compensationCoefficient = 1.0 + 0.02 * (temperature - 25.0);
    float compensationVoltage = averageVoltage / compensationCoefficient;

    tdsValue = (133.42 * compensationVoltage * compensationVoltage * compensationVoltage
                - 255.86 * compensationVoltage * compensationVoltage
                + 857.39 * compensationVoltage) * 0.5;
  }

  return tdsValue;
}
