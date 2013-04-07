#include <Adafruit_GFX.h>    // Core graphics library
#include <Arduino_GLCD.h> // Hardware-specific library
#include <SPI.h>
#include <SD.h>

PImage img;

Arduino_GLCD tft = Arduino_GLCD(7, 0, 1); // Esplora pins

void setup() {
  img = tft.loadImage("parrot.jpg");
  tft.image(img, 0, 0);
}

void loop() {
  
}
