/*

 GLCD Bouncing Ball
 
 This example for the Arduino GLCD draws a circle on 
 the screen that bounces when it hits an edge.
 
 This example code is in the public domain.
 
 Created 15 April 2013 by Scott Fitzgerald
 
 http://arduino.cc/en/Tutorial/GLCDBouncingBall
 
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
#include <Arduino_GLCD.h> // Hardware-specific library
#include <SPI.h>

Arduino_GLCD LCDscreen = Arduino_GLCD(cs, dc, rst);

// initial position of the circle
int xPos = LCDscreen.width()/2;
int yPos = LCDscreen.height()/2;

// previous position of the circle
int xOldPos;
int yOldPos;

// speed on the X & Y axis
int xSpeed = -1;
int ySpeed = 1;

void setup(){
  
  // initialize the screen
  LCDscreen.begin();

  // clear the screen with a black background
  LCDscreen.background(0,0,0); 
}

void loop(){
  // check if the circle's edge position is at the top or bottom
 if (xPos > LCDscreen.width()-10 || xPos < 0) {
   // change direction
   xSpeed = -xSpeed;
 }
 
   // check if the circle's edge is at the screen's left or right edge 
  if (yPos > LCDscreen.height()-10 || yPos < 0) {
   // change direction
   ySpeed = -ySpeed;
 }  
 
  // update the current position of the circle
 xPos += xSpeed;
 yPos += ySpeed;
 
  // if the current position is different than the previous position
  if (xOldPos != xPos || yOldPos != yPos) {
    // erase the previous circle
    LCDscreen.stroke(0,0,0);
    LCDscreen.fill(0,0,0);
    LCDscreen.rect(xOldPos, yOldPos, 10, 10);
  }

  // draw the circle in it's current position  
  LCDscreen.stroke(255,255,255);
  LCDscreen.fill(250,200,10);
  LCDscreen.rect(xPos, yPos, 10,10);

  // save the current position for the next loop 
  xOldPos = xPos;
  yOldPos = yPos;
  
  delay(50);
}

