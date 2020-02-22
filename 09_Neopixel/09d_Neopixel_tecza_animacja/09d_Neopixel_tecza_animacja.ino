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
int czas=100;

void loop() {
  for (int i=0; i<NUM; i++){ // Kolor czerwony
    pixels.setPixelColor(i,255,0,0);
    pixels.show();
    delay(czas);
  }
  for (int i=0; i<NUM; i++){ // Kolor pomarańczowy
    pixels.setPixelColor(i,255,128,0);
    pixels.show();
    delay(czas);
  }
   for (int i=0; i<NUM; i++){ // Kolor żółty
    pixels.setPixelColor(i,255,255,0);
    pixels.show();
    delay(czas);
  }
  for (int i=0; i<NUM; i++){ // Kolor zielony
    pixels.setPixelColor(i,0,255,0);
    pixels.show();
    delay(czas);
  }
  for (int i=0; i<NUM; i++){ // Kolor jasno niebieski
    pixels.setPixelColor(i,0,255,255);
    pixels.show();
    delay(czas);
  }
  for (int i=0; i<NUM; i++){ // Kolor niebieski
    pixels.setPixelColor(i,0,0,255);
    pixels.show();
    delay(czas);
  }
  for (int i=0; i<NUM; i++){ // Kolor fioletowy
    pixels.setPixelColor(i,255,0,255);
    pixels.show();
    delay(czas);
  }
}

