#include <Esplora.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Arduino_GLCD.h> // Hardware-specific library

#define SD_CS    8  // Chip select line for SD card in Esplora

PImage logo;

/*
 * To run this sketch:
 * - open the sketch folder (Ctrl-K)
 * - copy the "arduino.bmp" file to an SD
 * - put the SD into the SD slot of the Arduino LCD module.
 */

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    // wait for serial line to be ready
  }
  Serial.print("Initializing SD card...");
  if (!SD.begin(SD_CS)) {
    Serial.println("failed!");
    Esplora.writeRed(255);
    return;
  }
  Serial.println("OK!");
  EsploraLCD.begin();
  EsploraLCD.background(255, 255, 255);
  Esplora.writeRGB(0, 0, 0);
  logo = EsploraLCD.loadImage("arduino.bmp");
  if (logo.isValid()) {
    Esplora.writeGreen(255);
  }
  else
    Esplora.writeRed(255);

}

void loop() {
  if (logo.isValid() == false) {
    return;
  }
  
  Serial.println("drawing image");
  int x = random(EsploraLCD.width() - logo.width());
  int y = random(EsploraLCD.height() - logo.height());
  EsploraLCD.image(logo, x, y);
  delay(1500);
}
