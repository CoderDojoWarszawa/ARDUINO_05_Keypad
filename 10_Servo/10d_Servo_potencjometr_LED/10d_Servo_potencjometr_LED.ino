#include <Servo.h> 
#include <Adafruit_NeoPixel.h>

// GND (czarny, ciemnobrązowy) - GND
// +5V Zasilanie (czerwony) - +5V
// Sygnał sterujący (żółty/pomarańczowy) - 9

Adafruit_NeoPixel pixels=Adafruit_NeoPixel(8,6,NEO_GRB+NEO_KHZ800);
Servo serwo;  //Tworzymy instancję o nazwie serwo
int odczyt = 0;
int skala = 0;

void setup() 
{
  pixels.begin();
  pixels.setBrightness(10);
  serwo.attach(9);  //Serwomechanizm podłączony do pin 9
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
  //Odczyt wartości z ADC
  odczyt = analogRead(A0);
  //Przemapowanie wartości z zakresu 0-1023 na 0-180
  skala = map(odczyt, 0, 1023, 0, 180);
  serwo.write(skala); 
  //pasek(skala);
}





