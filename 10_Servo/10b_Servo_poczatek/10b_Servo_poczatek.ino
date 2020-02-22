#include <Servo.h> 
Servo serwo;  //Tworzymy instancję o nazwie serwo

// GND (czarny, ciemnobrązowy) - GND
// +5V Zasilanie (czerwony) - +5V
// Sygnał sterujący (żółty/pomarańczowy) - 9

void setup() 
{
  serwo.attach(9);  //Serwomechanizm podłączony do pin 9
} 
void loop() 
{  
  serwo.write(0); //Ustawienie wychylenia na 0 stopni
  delay(1000);
  serwo.write(45); //Wychylenie 45 stopni
  delay(1000);
  serwo.write(90); //Wychylenie 90 stopni
  delay(1000);
  serwo.write(135); //Wychylenie 135 stopni
  delay(1000);
  serwo.write(180); //Wychylenie 180 stopni
  delay(1000);
}

