#include "Arduino_GLCD.h"

Arduino_GLCD::Arduino_GLCD(uint8_t CS, uint8_t RS, uint8_t RST) 
  : Adafruit_ST7735(CS, RS, RST)
{
  strokeColor = 0;
  useStroke = true;
  fillColor = 0;
  useFill = false;
}

void Arduino_GLCD::begin() {
  initR(INITR_REDTAB);
  setRotation(1);
}



void Arduino_GLCD::background(uint8_t red, uint8_t green, uint8_t blue) {
  background(newColor(red, green, blue));
}

void Arduino_GLCD::background(color c) {
  fillScreen(c);
}

void Arduino_GLCD::stroke(uint8_t red, uint8_t green, uint8_t blue) {
  stroke(newColor(red, green, blue));
}

void Arduino_GLCD::stroke(color c) {
  useStroke = true;
  strokeColor = c;
  setTextColor(c);
}

void Arduino_GLCD::noStroke() {
  useStroke = false;
}

void Arduino_GLCD::noFill() {
  useFill = false;
}

void Arduino_GLCD::fill(uint8_t red, uint8_t green, uint8_t blue) {
  fill(newColor(red, green, blue));
}

void Arduino_GLCD::fill(color c) {
  useFill = true;
  fillColor = c;
}


void Arduino_GLCD::text(const char * text, int16_t x, int16_t y) {
  if (!useStroke)
    return;
  
  setTextWrap(false);
  setTextColor(strokeColor);
  setCursor(x, y);
  print(text);
}

void Arduino_GLCD::textWrap(const char * text, int16_t x, int16_t y) {
  if (!useStroke)
    return;
  
  setTextWrap(true);
  setTextColor(strokeColor);
  setCursor(x, y);
  print(text);
}


void Arduino_GLCD::textSize(uint8_t size) {
  setTextSize(size);
}

void Arduino_GLCD::point(int16_t x, int16_t y) {
  if (!useStroke)
    return;
  
  drawPixel(x, y, strokeColor);
}

void Arduino_GLCD::line(int16_t x1, int16_t y1, int16_t x2, int16_t y2) {
  if (!useStroke)
    return;
  
  if (x1 == x2) {
    drawFastVLine(x1, y1, y2 - y1, strokeColor);
  }
  else if (y1 == y2) {
    drawFastHLine(x1, y1, x2 - x1, strokeColor);
  }
  else {
    drawLine(x1, y1, x2, y2, strokeColor);
  }
}

void Arduino_GLCD::rect(int16_t x, int16_t y, int16_t width, int16_t height) {
  if (useFill) {
    fillRect(x, y, width, height, fillColor);
  }
  if (useStroke) {
    drawRect(x, y, width, height, strokeColor);
  }
}

void Arduino_GLCD::rect(int16_t x, int16_t y, int16_t width, int16_t height, int16_t radius) {
  if (radius == 0) {
    rect(x, y, width, height);
  }
  if (useFill) {
    fillRoundRect(x, y, width, height, radius, fillColor);
  }
  if (useStroke) {
    drawRoundRect(x, y, width, height, radius, strokeColor);
  }
}
color newColor(uint8_t r, uint8_t g, uint8_t b) {
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}
