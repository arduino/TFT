/*

 Esplora GLCD Bouncing Ball
 
 This example for the Arduino LCD screen is for use
 with an Arduino Esplora.
 
 This example draws a circle on the screen that 
 bounces when it hits an edge.
 
 This example code is in the public domain.
 
 Created 15 April 2013 by Scott Fitzgerald
 
 http://arduino.cc/en/Tutorial/EsploraGLCDBouncingBall
 
 */
 
// include the necessary libraries
#include <Esplora.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <GLCD.h> // Hardware-specific library
#include <SPI.h>

// initial position of the circle
int xPos = EsploraLCD.width()/2;
int yPos = EsploraLCD.height()/2;

// previous position of the circle
int xOldPos;
int yOldPos;

// speed on the X & Y axis
int xSpeed = 1;
int ySpeed = 1;

void setup(){
  // initialize the screen
  EsploraLCD.begin();

  // clear the screen with a black background  
  EsploraLCD.background(0,0,0); 
}

void loop(){
  // check if the circle's center position is at the top or bottom
 if (xPos > EsploraLCD.width() || xPos < 0) {
   // change direction
   xSpeed = -xSpeed;
 }

  // check if the circle's center position is at the left or right edge 
  if (yPos > EsploraLCD.height() || yPos < 0) {
   // change direction    
   ySpeed = -ySpeed;
 }  
 
 // update the current position of the circle
 xPos += xSpeed;
 yPos += ySpeed;
 
 // if the current position is different than the previous position
  if (xOldPos != xPos || yOldPos != yPos) {
    // erase the previous circle
    EsploraLCD.fill(0,0,0);
    EsploraLCD.circle(xOldPos, yOldPos, 5);
  }
  
  // draw the circle in it's current position
  EsploraLCD.fill(250,16,200);
  EsploraLCD.circle(xPos, yPos, 5);
 
  // save the current position for the next loop
  xOldPos = xPos;
  yOldPos = yPos;
  
  // small delay
  delay(33);
}
