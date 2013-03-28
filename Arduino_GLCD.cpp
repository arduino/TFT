#include "Arduino_GLCD.h"

Arduino_GLCD::Arduino_GLCD(uint8_t CS, uint8_t RS, uint8_t RST) 
  : Adafruit_ST7735(CS, RS, RST)
{
}

void Arduino_GLCD::begin() {
  initR(INITR_REDTAB);
}
    
void Arduino_GLCD::background(uint8_t gray) {
  background(gray, gray, gray);
}

void Arduino_GLCD::background(uint8_t red, uint8_t green, uint8_t blue) {
  background(Color565(red, green, blue));
}

void Arduino_GLCD::background(uint16_t color565) {
  fillScreen(color565);
}