
#ifndef _ARDUINO_GLCD_H
#define _ARDUINO_GLCD_H

#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>



class Arduino_GLCD : public Adafruit_ST7735 {
public:
  Arduino_GLCD(uint8_t CS, uint8_t RS, uint8_t RST);

  void begin();  
};

#if (USB_VID == 0x2341) && (USB_PID == 0x803C) // are we building for Esplora?
extern Arduino_GLCD EsploraLCD;
#endif

#endif // _ARDUINO_GLCD_H
