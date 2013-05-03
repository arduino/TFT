/*

 Esplora GLCD Horizion
 
 This example for the Arduino GLCD and Esplora draws 
 a line on the screen that stays level with the ground
 as you tile the Esplora side to side
 
 This example code is in the public domain.
 
 Created 15 April 2013 by Scott Fitzgerald
 
 http://arduino.cc/en/Tutorial/EsploraGLCDHorizion
 
 */

#include <Esplora.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <GTFT.h> // Hardware-specific library
#include <SPI.h>

// horizontal start and end positions
int yStart = EsploraLCD.height()/2;
int yEnd = EsploraLCD.height()/2;

// previous start and end positions
int oldEndY;
int oldStartY;

void setup() {
  // initialize the display
  EsploraLCD.begin();
  // make the background black
  EsploraLCD.background(0,0,0); 
}

void loop()
{
  // read the x-axis of te accelerometer
  int tilt = Esplora.readAccelerometer(X_AXIS);

  // the values are 100 when tilted to the left
  // and  -100 when tilted to the right
  // map these values to the start and end points
  yStart = map(tilt,-100,100,EsploraLCD.height(),0);
  yEnd = map(tilt,-100,100,0,EsploraLCD.height());

  // if the previous values are different than the current values
  // erase the previous line
  if (oldStartY != yStart || oldEndY != yEnd) {
    EsploraLCD.stroke(0,0,0);
    EsploraLCD.line(0, oldStartY, EsploraLCD.width(), oldEndY);
  }

  // draw the line in magenta
  EsploraLCD.stroke(255,0,255);
  EsploraLCD.line(0,yStart,EsploraLCD.width(),yEnd);

  // save the current start and end points
  // to compare int he next loop
  oldStartY= yStart;
  oldEndY = yEnd;
  delay(10);            
}
