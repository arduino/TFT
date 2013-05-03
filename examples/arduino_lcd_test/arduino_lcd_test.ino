/***************************************************
  This is an example sketch for the Adafruit 1.8" SPI display.
  This library works with the Adafruit 1.8" TFT Breakout w/SD card
  ----> http://www.adafruit.com/products/358
  as well as Adafruit raw 1.8" TFT display
  ----> http://www.adafruit.com/products/618
 
  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

//#define sclk 13
//#define mosi 11
#define cs   7
#define dc   0
#define rst  1  // you can also connect this to the Arduino reset

#include <Adafruit_GFX.h>    // Core graphics library
#include <GTFT.h> // Hardware-specific library
#include <SPI.h>

// Option 1: use any pins but a little slower
//Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, mosi, sclk, rst);

// Option 2: must use the hardware SPI pins
// (for UNO thats sclk = 13 and sid = 11) and pin 10 must be
// an output. This is much faster - also required if you want
// to use the microSD card (see the image drawing example)
GTFT tft = GTFT(cs, dc, rst);
float p = 3.1415926;

void setup(void) {
  Serial.begin(9600);
  Serial.print("hello!");

  // Put this line at the beginning of every sketch that uses the GLCD:
  tft.begin();

  Serial.println("init");

  uint16_t time = millis();
  // clear the screen with an orange background
  tft.background(255, 128, 0);
  time = millis() - time;

  delay(500);
  
  // clear the screen with a cyan background (using the "color" type);
  color c = tft.newColor(0, 255, 255);
  tft.background(c);
  delay(500);

  Serial.println(time, DEC);
  delay(500);

  // large block of text
  tft.background(0, 64, 0);
  testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", tft.newColor(255, 255, 0));
  delay(1000);

  // tft print function!
  tftPrintTest();
  delay(4000);

  // a single pixel
  tft.stroke(0, 255, 0);
  tft.point(tft.width()/2, tft.height()/2);
  delay(500);

  // line draw test
  testlines(tft.newColor(255, 255, 0)); // yellow
  delay(500);

  // optimized lines
  testfastlines(tft.newColor(255, 0, 0), tft.newColor(0, 0, 255));
  delay(500);

  testdrawrects(tft.newColor(0, 255, 0));
  delay(500);

  testfillrects(tft.newColor(255, 255, 0), tft.newColor(255, 0, 255));
  delay(500);

  tft.background(0);
  testfillcircles(10, tft.newColor(0, 0, 255));
  testdrawcircles(10, tft.newColor(255, 255, 255));
  delay(500);

  testroundrects();
  delay(500);

  testtriangles();
  delay(500);

  mediabuttons();
  delay(500);

  Serial.println("done");
  delay(1000);
}

void loop() {
  tft.invertDisplay(true);
  delay(500);
  tft.invertDisplay(false);
  delay(500);
}

void testlines(color color) {
  tft.background(0);
  tft.stroke(color);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.line(0, 0, x, tft.height()-1);
  }
  for (int16_t y=0; y < tft.height(); y+=6) {
    tft.line(0, 0, tft.width()-1, y);
  }

  tft.background(0);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.line(tft.width()-1, 0, x, tft.height()-1);
  }
  for (int16_t y=0; y < tft.height(); y+=6) {
    tft.line(tft.width()-1, 0, 0, y);
  }

  tft.background(0);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.line(0, tft.height()-1, x, 0);
  }
  for (int16_t y=0; y < tft.height(); y+=6) {
    tft.line(0, tft.height()-1, tft.width()-1, y);
  }

  tft.fillScreen(0);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.line(tft.width()-1, tft.height()-1, x, 0);
  }
  for (int16_t y=0; y < tft.height(); y+=6) {
    tft.line(tft.width()-1, tft.height()-1, 0, y);
  }
}

void testdrawtext(char *text, color color) {
  tft.stroke(color);
  tft.textWrap(text, 0, 0);
}

void testfastlines(color color1, color color2) {
  tft.background(0);
  tft.stroke(color1);
  for (int16_t y=0; y < tft.height(); y+=5) {
    tft.line(0, y, tft.width(), y);
  }
  tft.stroke(color2);
  for (int16_t x=0; x < tft.width(); x+=5) {
    tft.line(x, 0, x, tft.height());
  }
}

void testdrawrects(color color) {
  tft.background(0);
  tft.stroke(color);
  for (int16_t y=0; y < tft.height(); y+=6) {
    tft.rect(tft.width()/2 -y/2, tft.height()/2 -y/2 , y, y);
  }
}

void testfillrects(color color1, color color2) {
  tft.background(0);
  tft.fill(color1);
  tft.stroke(color2);
  for (int16_t y=tft.height()-1; y > 6; y-=6) {
    tft.rect(tft.width()/2 -y/2, tft.height()/2 -y/2 , y, y);
  }
}

void testfillcircles(uint8_t radius, color color) {
  tft.noStroke();
  tft.fill(color);
  for (int16_t x=radius; x < tft.width(); x+=radius*2) {
    for (int16_t y=radius; y < tft.height(); y+=radius*2) {
      tft.circle(x, y, radius);
    }
  }
}

void testdrawcircles(uint8_t radius, color color) {
  tft.stroke(color);
  tft.noFill();
  for (int16_t x=0; x < tft.width()+radius; x+=radius*2) {
    for (int16_t y=0; y < tft.height()+radius; y+=radius*2) {
      tft.circle(x, y, radius);
    }
  }
}

void testtriangles() {
  tft.background(0);
  color color = tft.newColor(255, 0, 0);
  int t;
  int w = 79;
  int x = 127;
  int y = 0;
  int z = 159;
  for(t = 0 ; t <= 9; t+=1) {
    tft.stroke(color);
    tft.triangle(w, y, y, x, z, x);
    x-=5;
    y+=5;
    z-=5;
    color+=100;
  }
}

void testroundrects() {
  tft.background(0);
  tft.noFill();
  int color = 100;
  int i;
  int t;
  for(t = 0 ; t <= 4; t+=1) {
    int x = 0;
    int y = 0;
    int w = 159;
    int h = 127;
    for(i = 0 ; i <= 19; i+=1) {
      tft.stroke(color);
      tft.rect(x, y, w, h, 5);
      x+=2;
      y+=3;
      w-=4;
      h-=6;
      color+=1100;
    }
    color+=100;
  }
}

void tftPrintTest() {
  tft.background(0);
  tft.stroke(255, 0, 0); // red
  tft.textSize(1);
  tft.text("Hello World!\n", 0, 30); // the ending \n will put 
                                     // the cursor below the line

  tft.stroke(255, 255, 0); // yellow
  tft.textSize(2);
  // note: you can freely use text() and print()/println()
  tft.println("Hello World!");
  
  tft.stroke(0, 255, 0); // green
  tft.textSize(3);
  tft.println("Hello World!");
  
  tft.stroke(0, 0, 255); // blue
  tft.textSize(4);
  tft.print(1234.567);

  delay(1500);
  tft.background(0); // black
  tft.stroke(255, 255, 255); // white
  tft.textSize(0);
  tft.text("Hello World!\n", 0, 0);
  tft.textSize(1);
  tft.stroke(0, 255, 0); // green
  tft.print(p, 6);
  tft.println(" Want pi?");
  tft.println(" ");
  tft.print(8675309, HEX); // print 8,675,309 out in HEX!
  tft.println(" Print HEX!");
  tft.println(" ");
  tft.stroke(255, 255, 255); // white
  tft.println("Sketch has been");
  tft.println("running for: ");
  tft.stroke(255, 0, 255);  // magenta
  tft.print(millis() / 1000);
  tft.stroke(255, 255, 255);
  tft.print(" seconds.");
}

void mediabuttons() {
  // play
  tft.background(0);
  tft.noStroke();
  tft.fill(255, 255, 255);
  tft.rect(1, 34, 78, 60, 8);
  tft.fill(255, 0, 0);
  tft.triangle(16, 44, 16, 84, 65, 64);
  delay(500);
  // pause
  tft.fill(255, 255, 255);
  tft.rect(81, 34, 78, 60, 8);
  tft.fill(0, 255, 0);
  tft.rect(95, 42, 20, 45, 5);
  tft.rect(125, 42, 20, 45, 5);
  delay(500);
  // play color
  tft.fill(0, 0, 255);
  tft.triangle(16, 44, 16, 84, 65, 64);
  delay(50);
  // pause color
  tft.fill(255, 0, 0);
  tft.rect(95, 42, 20, 45, 5);
  tft.rect(125, 42, 20, 45, 5);
  // play color
  tft.fill(0, 255, 0);
  tft.triangle(16, 44, 16, 84, 65, 64);
}
