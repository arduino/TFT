#include <Adafruit_GFX.h>    // Core graphics library
#include <Arduino_GLCD.h> // Hardware-specific library
#include <SPI.h>
#include <SD.h>

#include <Esplora.h>

PImage img;

Arduino_GLCD tft = Arduino_GLCD(7, 0, 1); // Esplora pins

void setup() {
}

void loop() {
  Esplora.writeRGB(0, 0, 0);
  img = tft.loadImage("parrot.bmp");
  if (img.isValid()) {
    Esplora.writeGreen(255);
  }
  else
    Esplora.writeRed(255);
  tft.image(img, 0, 0);
  
  delay(3000);
}
