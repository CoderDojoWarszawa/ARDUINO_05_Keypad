#include <Adafruit_NeoPixel.h>
#define PIN 6 // Podłączenie do pin 6
#define NUM 16 // Ile diod ma nasz pasek
// Stworzenie instancji o nazwie pixels
Adafruit_NeoPixel pixels=Adafruit_NeoPixel(NUM,PIN,NEO_GRB+NEO_KHZ800);

void setup() {
  //Inicjalizacja biblioteki
  pixels.begin();
  //Ustawienie jasnosci na 10
  pixels.setBrightness(10);
}
void loop() {
  pixels.setPixelColor(0,255,0,0);
  pixels.setPixelColor(1,0,255,0);
  pixels.setPixelColor(2,0,0,255);
  pixels.setPixelColor(3,255,0,0);
  pixels.setPixelColor(4,0,255,0);
  pixels.setPixelColor(5,0,0,255);
  pixels.setPixelColor(6,255,0,0);
  pixels.setPixelColor(7,0,255,0);
  pixels.setPixelColor(8,255,0,0);
  pixels.setPixelColor(9,0,255,0);
  pixels.setPixelColor(10,0,0,255);
  pixels.setPixelColor(11,255,0,0);
  pixels.setPixelColor(12,0,255,0);
  pixels.setPixelColor(13,0,0,255);
  pixels.setPixelColor(14,255,0,0);
  pixels.setPixelColor(15,0,255,0);
  pixels.show();
}


