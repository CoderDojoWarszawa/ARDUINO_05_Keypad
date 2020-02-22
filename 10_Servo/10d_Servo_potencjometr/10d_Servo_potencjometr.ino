#include <Servo.h> 

// GND (czarny, ciemnobrązowy) - GND
// +5V Zasilanie (czerwony) - +5V
// Sygnał sterujący (żółty/pomarańczowy) - 9

Servo serwo;  //Tworzymy instancję o nazwie serwo
int odczyt = 0;
int skala = 0;

void setup() 
{
  serwo.attach(9);  //Serwomechanizm podłączony do pin 9
} 

void loop() 
{  
  //Odczyt wartości z ADC
  odczyt = analogRead(A0);
  //Przemapowanie wartości z zakresu 0-1023 na 0-180
  skala = map(odczyt, 0, 1023, 0, 180);
  serwo.write(skala); 
}





