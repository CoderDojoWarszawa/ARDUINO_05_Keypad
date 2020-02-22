#include <Adafruit_NeoPixel.h>

#define PIN 6 // Podłączenie do pin 6
#define NUM 8 // Ile diod ma nasz pasek

// Stworzenie instancji o nazwie pixels
Adafruit_NeoPixel pixels=Adafruit_NeoPixel(NUM,PIN,NEO_GRB+NEO_KHZ800);

void setup() {
  pixels.begin(); //Inicjalizacja biblioteki
  pixels.setBrightness(10); //Ustawienie jasnosci na 10
  for (int i=0; i<NUM; i++){
    pixels.setPixelColor(i,0,0,255); //Kolor niebieski
  }
  pixels.show();
}
int czas=100;
void loop() {
  for (int i=0; i<NUM; i++){
    pixels.setPixelColor(i,255,0,0); //Kolor czerwony
    pixels.setPixelColor(i-1,0,0,255); //Kolor niebieski
    pixels.show();
    delay(czas);
  }
  for (int i=NUM-1; i>=0; i--){
    pixels.setPixelColor(i,255,0,0); //Kolor czerwony
    pixels.setPixelColor(i+1,0,0,255); //Kolor niebieski
    pixels.show();
    delay(czas);
  }
}


