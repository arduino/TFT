
#ifndef _ARDUINO_GLCD_H
#define _ARDUINO_GLCD_H

#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

/// The Arduino LCD is a ST7735-based device.
/// By default, it is mounted horizontally.
/// GLCD class follows the convention of other
/// Arduino library classes by adding a begin() method
/// to be called in the setup() routine.
/// @author Enrico Gueli <enrico.gueli@gmail.com>
class GLCD : public Adafruit_ST7735 {
public:
  GLCD(uint8_t CS, uint8_t RS, uint8_t RST);

  void begin();  
};

/// Esplora boards have hard-wired connections with
/// the Arduino LCD if mounted on the onboard connector.
#if (USB_VID == 0x2341) && (USB_PID == 0x803C) // are we building for Esplora?
extern GLCD EsploraLCD;
#endif

#endif // _ARDUINO_GLCD_H
