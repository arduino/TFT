#include <Esplora.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Arduino_GLCD.h> // Hardware-specific library
#define SD_CS    8  // Chip select line for SD card

PImage img;

void setup() {
  Serial.begin(9600);
  while (!Serial) ;  // TODO do this for Leonardo-likes only
  
  Serial.print("Initializing SD card...");
  if (!SD.begin(SD_CS)) {
    Serial.println("failed!");
    return;
  }
  Serial.println("OK!");
  EsploraLCD.begin();
}

void loop() {
  delay(5000);
  Esplora.writeRGB(0, 0, 0);
  img = EsploraLCD.loadImage("parrot.bmp");
  if (img.isValid()) {
    Esplora.writeGreen(255);
  }
  else
    Esplora.writeRed(255);
    
  Serial.println("drawing images");
  EsploraLCD.background(0);
  EsploraLCD.image(img, 0, 0);
  EsploraLCD.image(img, 32, 32);
  delay(30000);
}
