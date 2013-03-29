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
  background(newColor(red, green, blue));
}

void Arduino_GLCD::background(color c) {
  fillScreen(c);
}

void Arduino_GLCD::stroke(uint8_t gray) {
  stroke(gray, gray, gray);
}

void Arduino_GLCD::stroke(uint8_t red, uint8_t green, uint8_t blue) {
  stroke(newColor(red, green, blue));
}

void Arduino_GLCD::stroke(color c) {
  strokeColor = c;
}


void Arduino_GLCD::text(const char * text, uint16_t x, uint16_t y) {
  setTextWrap(false);
  setTextColor(strokeColor);
  setCursor(x, y);
  print(text);
}

void Arduino_GLCD::textWrap(const char * text, uint16_t x, uint16_t y) {
  setTextWrap(true);
  setTextColor(strokeColor);
  setCursor(x, y);
  print(text);
}



color newColor(uint8_t r, uint8_t g, uint8_t b) {
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}
