//Prevents reddefinition if not defined
#ifndef PH_H 
//Define
#define PH_H 

class PHSensor {
  //Member Function Interface
  public:
    PHSensor(byte pin, float calibrationValue = 22.34);
    float getPH();

  // Member Variable Interface
  private:
    byte _pin;
    float _calibrationValue;
    int _buffer[10];
    int _temp;
    unsigned long _avgval;
};

#endif
