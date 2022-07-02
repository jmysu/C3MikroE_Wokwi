/*
  Wokwi LED && Neopixel simulation
  by Jimmy.Su
*/
#include <Adafruit_NeoPixel.h>
#define PIN        19
#define NUMPIXELS  1

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32-C3-MikroE!");
  pinMode(0, OUTPUT);
  pixels.begin();
}

int r = 150;
int g = 0;
int b = 0;
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(0, HIGH);
  delay(500);
  digitalWrite(0, LOW);
  delay(500);
 
  pixels.clear();
  pixels.setPixelColor(0, r, g, b);
  pixels.show();

  int temp = b;
  b = g;
  g = r;
  r = temp;
}