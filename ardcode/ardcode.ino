
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#define TFT_DC 9
#define TFT_CS 10

// building off example from https://github.com/adafruit/Adafruit_ILI9341/blob/master/examples/graphicstest/graphicstest.ino
// serial communication via https://github.com/shfitz/CC-Summer-2017/tree/master/SerialCommunication

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

//define colors
int yellowColor = tft.color565(255, 255, 0);
int redColor = tft.color565(255, 0, 0);
int blueColor = tft.color565(0, 0, 255);
int greenColor = tft.color565(0, 255, 0);
int myColor = tft.color565(255, 255, 255);


String myText = " ";
 
// string to hold the data from the serial buffer
int myvariable = 0;

void setup() {
  // start serial communication
  Serial.begin(9600);
  // start the screen
  tft.begin(); 
}

void loop() {
  if (Serial.available() > 0) {
    myvariable = Serial.read();
  }

  if (myvariable == '1') { 
    myText = "CIRCLE";    
    Serial.write(myvariable);
    Serial.println(Circle());
    delay(500);

  } else if (myvariable == '2') {
  myText = "SQUARE";    
    Serial.write(myvariable);
    Serial.println(Rectangle());
    delay(500);
 
 } else if (myvariable == '3') {

  myText = "TRIANGLE";    
    Serial.write(myvariable);
    Serial.println(Triangle());
    delay(500);
  
 } else if (myvariable == '4') {

  myText = "REDDDD";    // draw new text on the screen
    Serial.write(myvariable);
    myColor = redColor; 
    //Serial.println(testFilledRoundRects());
    delay(500);
 
 } else if (myvariable == '5') {

  myText = "YELLOW";    // draw new text on the screen
    Serial.write(myvariable);
    myColor = yellowColor; 
    delay(500);
  
} else if (myvariable == '6') {

  myText = "BLUE";    
    Serial.write(myvariable);
    myColor = blueColor; 
    delay(500); 
 
} else if (myvariable == '7') {

  myText = "GREEN"; 
  Serial.write(myvariable);
  myColor = greenColor; 
  delay(500); 
} 

else {
    myText = "Hello World"; 
  }

  testText(); 
  delay(50); 
}

void testText() {
  tft.fillScreen(ILI9341_BLACK); // erase the screen (similar to p5js background(0);)
  tft.setCursor(0, 0);  
  tft.setTextColor(ILI9341_GREEN); 
  tft.setTextSize(3);
  tft.println(myText); 
}



unsigned long Rectangle() {
  unsigned long start;
  int           i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;

  //tft.fillScreen(ILI9341_BLACK);
  start = micros();
  for(i=min(tft.width(), tft.height()); i>20; i-=6) {
    i2 = i / 2;
    tft.fillRoundRect(cx-i2, cy-i2, i, i, i/8, myColor);
    yield(); 
  }

}

unsigned long Triangle() {
  unsigned long start, t = 0;
  int           i, cx = tft.width()  / 2 - 1,
                   cy = tft.height() / 2 - 1;

  //tft.fillScreen(ILI9341_BLACK);
  start = micros();
  for(i=min(cx,cy); i>10; i-=5) {
    start = micros();
    tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      myColor);
    t += micros() - start;
    tft.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i, myColor);
    yield();
  }

  return t; } 


unsigned long Circle() {
  unsigned long start;

   int cx = tft.width()  / 2 - 1;
   int cy = tft.height() / 2 - 1;
  
  int x, y, w = tft.width(), h = tft.height(), radius = 0.5 * w;

  //tft.fillScreen(ILI9341_BLACK);
  start = micros();
  tft.fillCircle(cx, cy, radius, myColor);

 

} 



