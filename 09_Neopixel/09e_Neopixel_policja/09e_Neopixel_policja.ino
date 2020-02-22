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
int czas=30;

void loop() {
  for (int i=10; i<101; i=i+5){
    pixels.setBrightness(i);
    pixels.setPixelColor(0,255,0,0);
    pixels.setPixelColor(1,255,0,0);
    pixels.setPixelColor(2,255,0,0);
    pixels.setPixelColor(3,255,0,0);
    pixels.setPixelColor(4,0,0,255);
    pixels.setPixelColor(5,0,0,255);
    pixels.setPixelColor(6,0,0,255);
    pixels.setPixelColor(7,0,0,255);
    pixels.show();
    delay(czas);
  }
  for (int i=10; i<101; i=i+5){
    pixels.setBrightness(i);  
    pixels.setPixelColor(0,0,0,255);
    pixels.setPixelColor(1,0,0,255);
    pixels.setPixelColor(2,0,0,255);
    pixels.setPixelColor(3,0,0,255);
    pixels.setPixelColor(4,255,0,0);
    pixels.setPixelColor(5,255,0,0);
    pixels.setPixelColor(6,255,0,0);
    pixels.setPixelColor(7,255,0,0);
    pixels.show();
    delay(czas);
  }
}

