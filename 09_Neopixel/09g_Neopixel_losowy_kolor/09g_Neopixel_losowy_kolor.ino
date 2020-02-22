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
  int red = random(0, 255);
  int green = random (0, 255);
  int blue = random (0, 255);
  for (int i=0; i<NUM; i++){ 
    pixels.setPixelColor(i, red, green, blue);
    pixels.show();
    delay(50);
  }
}


