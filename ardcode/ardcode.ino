
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

// string to hold the data from the serial buffer
String inputString = "";

// string to hold text
String myText = " ";
boolean userText = false;
// variable to indicate shape or color to draw on screen
int myvariable = 0;

// variable to check if there is a complete piece of data or not
bool stringComplete = false;

void setup() {
  // start serial communication
  Serial.begin(9600);
  // start the screen
  tft.begin();
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void loop() {
  if (stringComplete == true) {
    if (inputString.indexOf("1") != -1) {
         myvariable = 1;
          userText = false;
    } else if (inputString.indexOf("2") != -1) {
      myvariable = 2;
      userText = false;
    } else if (inputString.indexOf("3") != -1) {
      myvariable = 3;
      userText = false;
    } else if (inputString.indexOf("4") != -1) {
      myvariable = 4;
      userText = false;
    } else if (inputString.indexOf("5") != -1) {
      myvariable = 5;
      userText = false;
    } else if (inputString.indexOf("6") != -1) {
      myvariable = 6;
      userText = false;
    } else if (inputString.indexOf("7") != -1) {
      myvariable = 7;
      userText = false;
    } else {
       myText = inputString;
       userText = true;
    }
    inputString = "";
    stringComplete = false;
  }
  
    if (myvariable == 1 && userText ==false) {
     myText = "CIRCLE";
     Circle();
     delay(500);
    }else if (myvariable == 1 && userText ==true) {
     Circle();
     delay(500);
     } else if (myvariable == 2 && userText ==false) {
     myText = "SQUARE";
     Rectangle();
     delay(500);
    } else if (myvariable == 2 && userText ==true) {
     Rectangle();
      delay(500);
    } 
     else if (myvariable == 3 && userText ==false) {
     myText = "TRIANGLE";
     Triangle();
     delay(500);
    } else if (myvariable == 3 && userText ==true) {
     Triangle();
      delay(500);
    } else if (myvariable == 4 && userText ==false) {
      myText = "RED"; 
      myColor = redColor;
      delay(500);
    } else if (myvariable == 4 && userText ==true) {
     myColor = redColor;
     delay(500);
    } else if (myvariable == 5 && userText ==false) {
      myText = "YELLOW";    
      myColor = yellowColor;
      delay(500);
    } else if (myvariable == 5 && userText ==true) {
     myColor = yellowColor;
      delay(500);
    } else if (myvariable == 6 && userText ==false) {
      myText = "BLUE";    
      myColor = blueColor;
      delay(500);
    } else if (myvariable == 6 && userText ==true) {
     myColor = blueColor;
      delay(500);
    } else if (myvariable == 7 && userText ==false) {
      myText = "GREEN";    
      myColor = greenColor;
      delay(500);
    } else if (myvariable == 7 && userText ==true) {
     myColor = greenColor;
      delay(500);
    } else {
      myText = "Hello World";
    }
      testText();
      delay(50);
  }

void testText() {
  tft.fillScreen(ILI9341_BLACK); // erase the screen (similar to p5js background(0);)
  tft.setCursor(0, 0);
  tft.setTextColor(myColor);
  tft.setTextSize(3);
  tft.println(myText);
}

void Rectangle() {
  unsigned long start;
  int           i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;
  start = micros();
  for (i = min(tft.width(), tft.height()); i > 20; i -= 6) {
    i2 = i / 2;
    tft.fillRoundRect(cx - i2, cy - i2, i, i, i / 8, myColor);
    yield();
  }
}

void Triangle() {
  unsigned long start, t = 0;
  int           i, cx = tft.width()  / 2 - 1,
                   cy = tft.height() / 2 - 1;
  start = micros();
  for (i = min(cx, cy); i > 10; i -= 5) {
    start = micros();
    tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
                     myColor);
    t += micros() - start;
    tft.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i, myColor);
    yield();
  }
  return t;
}

void Circle() {
  unsigned long start;
  int cx = tft.width()  / 2 - 1;
  int cy = tft.height() / 2 - 1;

  int x, y, w = tft.width(), h = tft.height(), radius = 0.5 * w;
  start = micros();
  tft.fillCircle(cx, cy, radius, myColor);
}

