#include <Servo.h> 


// GND (czarny, ciemnobrązowy) - GND
// +5V Zasilanie (czerwony) - +5V
// Sygnał sterujący (żółty/pomarańczowy) - 9

Servo serwo;  //Tworzymy instancję o nazwie serwo
int pozycja = 0; //Aktualna pozycja serwa 0-180
int zmiana = 1; //Co ile ma się zmieniać pozycja serwa?

void setup() {
  serwo.attach(9);  //Serwomechanizm podłączony do pin 9
  serwo.write(pozycja); //Ustawienie wychylenia na 0 stopni
  delay(1000);
} 
void loop() {  
  if (pozycja > 179) { 
    zmiana = -1;
  } 
  if (pozycja < 1) { 
    zmiana = 1;
  }
  pozycja = pozycja + zmiana; 
  serwo.write(pozycja);
  delay(50);  
}


