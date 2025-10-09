#ifndef CONFIG_H
#define CONFIG_H

//Temperature sensor pin
#define DS18B20_PIN 4

//TDS sensor pin
#define TDS_PIN A0

//PH level sensor pin and calibration
#define PH_PIN A1
#define PH_CALIBRATION 22.34

//OLED Display Configs
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  
#define OLED_ADDRESS 0x3C

#endif
