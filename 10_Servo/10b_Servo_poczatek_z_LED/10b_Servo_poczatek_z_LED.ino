#include <Servo.h> 
#include <Adafruit_NeoPixel.h>
Servo serwo;  //Tworzymy instancję o nazwie serwo
Adafruit_NeoPixel pixels=Adafruit_NeoPixel(8,6,NEO_GRB+NEO_KHZ800);

// GND (czarny, ciemnobrązowy) - GND
// +5V Zasilanie (czerwony) - +5V
// Sygnał sterujący (żółty/pomarańczowy) - 9

void setup() 
{
  pixels.begin();
  pixels.setBrightness(10);
  serwo.attach(9);  //Serwomechanizm podłączony do pin 9
  for (int i=0; i<8; i++){
     pixels.setPixelColor(i,255,0,0); 
  }
  pixels.show();
  delay(1000);
} 

void pasek(int wychylenie)
{
  int j=0;
  j = map(wychylenie,0,180,0,7);
  for (int i=0; i<8; i++){
     pixels.setPixelColor(i,0,0,0); 
  }
  pixels.setPixelColor(j,255,0,0); 
  pixels.show(); 
}

void loop() 
{  
  serwo.write(0); //Ustawienie wychylenia na 0 stopni
  pasek(0);
  delay(1000);
  serwo.write(45); //Wychylenie 45 stopni
  pasek(45);
  delay(1000);
  serwo.write(90); //Wychylenie 90 stopni
  pasek(90);
  delay(1000);
  serwo.write(135); //Wychylenie 135 stopni
  pasek(135);
  delay(1000);
  serwo.write(180); //Wychylenie 180 stopni
  pasek(180);
  delay(1000);
}

