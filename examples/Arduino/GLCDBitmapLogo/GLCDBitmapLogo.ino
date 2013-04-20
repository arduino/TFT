#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Arduino_GLCD.h> // Hardware-specific library

// pin definition for the Uno
#define sd_cs  11
#define lcd_cs 10
#define dc     9
#define rst    8  

// pin definition for the Leonardo
//#define sd_cs  8
//#define lcd_cs 7
//#define dc     0
//#define rst    1  

Arduino_GLCD LCDscreen = Arduino_GLCD(lcd_cs, dc, rst);

PImage logo;

/*
 * To run this sketch:
 * - open the sketch folder (Ctrl-K)
 * - copy the "arduino.bmp" file to an SD
 * - put the SD into the SD slot of the Arduino LCD module.
 */

void setup() {
  EsploraLCD.begin();
  EsploraLCD.background(255, 255, 255);

  EsploraLCD.stroke(0, 0, 255);
  EsploraLCD.println();
  EsploraLCD.println("Arduino LCD Bitmap Example");
  EsploraLCD.stroke(0, 0, 0);
  EsploraLCD.println("Open serial monitor");
  EsploraLCD.println("to run the sketch");

  Serial.begin(9600);
  while (!Serial) {
    // wait for serial line to be ready
  }

  EsploraLCD.background(255, 255, 255);


  Serial.print("Initializing SD card...");
  if (!SD.begin(sd_cs)) {
    Serial.println("failed!");
    return;
  }
  Serial.println("OK!");
  LCDscreen.begin();
  LCDscreen.background(255, 255, 255);

  logo = LCDscreen.loadImage("arduino.bmp");
  if (!logo.isValid()) {
    Serial.println("error while loading arduino.bmp");
  }
}

void loop() {
  if (logo.isValid() == false) {
    return;
  }
  
  Serial.println("drawing image");
  int x = random(LCDscreen.width() - logo.width());
  int y = random(LCDscreen.height() - logo.height());
  LCDscreen.image(logo, x, y);
  delay(1500);
}
