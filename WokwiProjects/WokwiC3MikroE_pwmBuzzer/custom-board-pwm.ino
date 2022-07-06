/*
  Wokwi LED && Neopixel simulation
  by Jimmy.Su
*/
#include "pwmWrite.h"
#include <Adafruit_NeoPixel.h>
#define PIN        19
#define NUMPIXELS  9

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Pwm pwm;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32-C3-MikroE!");
  pinMode(0, OUTPUT);
  pixels.begin();
  pwm.printPinsStatus();
}

int r = 150;
int g = 0;
int b = 0;
int duty = 0; 
int freq = 440;
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(0, HIGH);
  //PWM pin, duty, freq, resolution, shift
  pwm.write(1, duty, 400, 8, duty);
  pwm.write(3, 128, freq+duty*4, 8, 0);
  duty+=8;
  if (duty>255) duty=0; 
  delay(100);

  digitalWrite(0, LOW);
  pixels.clear();
  pixels.setPixelColor(0, r, g, b);
  pixels.show();
  delay(100);

  int temp = b;
  b = g;
  g = r;
  r = temp; 
}