/*

 GLCD Graph
 
 This example for an Arduino GLCD reads 
 the value of an analog sensor on A0, and 
 graphs the values on the screen.
 
 This example code is in the public domain.
 
 Created 15 April 2013 by Scott Fitzgerald
 
 http://arduino.cc/en/Tutorial/GLCDGraph
 
 */
 
 // pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8  

// pin definition for the Leonardo
// #define cs   7
// #define dc   0
// #define rst  1 

#include <Adafruit_GFX.h>    // Core graphics library
#include <GLCD.h> // Hardware-specific library
#include <SPI.h>

GLCD LCDscreen = GLCD(cs, dc, rst);

// position of the line on screen
int xPos = 0;

void setup(){
  // initialize the serial port
  Serial.begin(9600);

  // initialize the display
  LCDscreen.begin();

  // clear the screen with a pretty color
  LCDscreen.background(250,16,200); 
}

void loop(){
  // read the sensor and map it to the screen height
  int sensor = analogRead(A0);
  int drawHeight = map(sensor,0,1023,0,LCDscreen.height());
  
  // print out the height to the serial monitor
  Serial.println(drawHeight);
  
  // draw a line in a nice color
  LCDscreen.stroke(250,180,10);
  LCDscreen.line(xPos, LCDscreen.height()-drawHeight, xPos, LCDscreen.height());

  // if the graph has reached the screen edge
  // erase the screen and start again
  if (xPos >= 160) {
    xPos = 0;
    LCDscreen.background(250,16,200); 
  } 
  else {
    // increment the horizontal position:
    xPos++;
  }

  delay(16);
}

