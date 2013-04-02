#include "Arduino_GLCD.h"

Arduino_GLCD::Arduino_GLCD(uint8_t CS, uint8_t RS, uint8_t RST) 
  : Adafruit_ST7735(CS, RS, RST)
{
}

void Arduino_GLCD::begin() {
  initR(INITR_REDTAB);
  setRotation(1);
}
