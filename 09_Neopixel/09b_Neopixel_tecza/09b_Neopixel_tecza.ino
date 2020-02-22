#include <Adafruit_NeoPixel.h>
#define PIN 6 // Podłączenie do pin 6
#define NUM 8 // Ile diod ma nasz pasek
// Stworzenie instancji o nazwie pixels
Adafruit_NeoPixel pixels=Adafruit_NeoPixel(NUM,PIN,NEO_GRB+NEO_KHZ800);

void setup() {
  //Inicjalizacja biblioteki
  pixels.begin();
  //Ustawienie jasnosci na 10
  pixels.setBrightness(10);
}
void loop() {
  pixels.setPixelColor(0,255,0,0);   // Kolor czerwony
  pixels.setPixelColor(1,255,128,0); // Kolor pomarańczowy
  pixels.setPixelColor(2,255,255,0); // Kolor żółty
  pixels.setPixelColor(3,0,255,0);   // Kolor zielony
  pixels.setPixelColor(4,0,255,255); // Kolor jasno niebieski
  pixels.setPixelColor(5,0,0,255);   // Kolor niebieski
  pixels.setPixelColor(6,128,0,255); // kolor fioletowy
  pixels.setPixelColor(7,255,0,128); // Kolor różowy
  pixels.show();
}


