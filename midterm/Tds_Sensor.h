//Prevents reddefinition if not defined
#ifndef TDS_H
//define
#define TDS_H

#include <Arduino.h>

class TDSSensor {
  //Member Function Interface
  public:
    TDSSensor(byte pin, float vref = 5.0, int scount = 30);
    void begin();
    float getTDS(float temperature = 25.0);
  // Member Variable Interface
  private:
    int getMedianNum(int bArray[], int filterLen);
    byte _pin;
    float _vref;
    int _scount;
    int* _analogBuffer;
    int* _analogBufferTemp;
    int _analogBufferIndex;
};

#endif
