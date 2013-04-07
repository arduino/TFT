#include <Adafruit_GFX.h>    // Core graphics library
#include <Arduino_GLCD.h> // Hardware-specific library
#include <SPI.h>
#include <SD.h>

#include <Esplora.h>

#define SD_CS    8  // Chip select line for SD card

PImage img;

Arduino_GLCD tft = Arduino_GLCD(7, 0, 1); // Esplora pins

void setup() {
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  if (!SD.begin(SD_CS)) {
    Serial.println("failed!");
    return;
  }
  Serial.println("OK!");
  tft.begin();
}

void loop() {
  delay(5000);
  Esplora.writeRGB(0, 0, 0);
  img = tft.loadImage("parrot.bmp");
  if (img.isValid()) {
    Esplora.writeGreen(255);
  }
  else
    Esplora.writeRed(255);
  tft.image(img, 0, 0);
  delay(30000);
}
