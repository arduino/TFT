/*

 GLCD Color Picker
 
 This example for the Arduino GLCD reads the input of 
 potentiometers or analog sensors attached to A0, A1 and A2
 and uses the values to change the screen's color.
 
 This example code is in the public domain.
 
 Created 15 April 2013 by Scott Fitzgerald
 
 http://arduino.cc/en/Tutorial/GLCDColorPicker
 
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

void setup(void) {
  Serial.begin(9600);
  while(!Serial){
    ; // wait for serial to initialize on Leonardo
  }

  Serial.print("Initializing display!");

  // initialize the display
  LCDscreen.begin();

  // set the background to white
  LCDscreen.background(255, 255, 255);

}

void loop() {

  // read the values frm your sensors and scale them to 0-255
  int redVal = map(analogRead(A0), 0, 1023, 0, 255); 
  int greenVal = map(analogRead(A1), 0, 1023, 0, 255); 
  int blueVal = map(analogRead(A2), 0, 1023, 0, 255);
  
  // draw the background based on the mapped values
  LCDscreen.background(redVal, greenVal, blueVal);
  
  // send the values to the serial monitor
  Serial.print("background(");
  Serial.print(redVal);
  Serial.print(" , ");
  Serial.print(greenVal);
  Serial.print(" , ");
  Serial.print(blueVal);
  Serial.println(")");
  
  // wait for a moment
  delay(33);

}

