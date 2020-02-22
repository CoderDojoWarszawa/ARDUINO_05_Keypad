#include <Servo.h> 
Servo serwo;  //Tworzymy instancję o nazwie serwo

void setup() 
{
  serwo.attach(9);  //Serwomechanizm podłączony do pin 9
  Serial.begin(9600); //Inicjacja komunikacji serial
  Serial.println("Inicjacja komunikacji");
  serwo.write(0);
  delay(500); 
} 

String readString;
int pozycja=0;

void loop() 
{  
  if (Serial.available() > 0) {
    // Przeczytaj ostatnie dane z bufora
    char znak = Serial.read();
    readString += znak;
    pozycja = readString.toInt();
    Serial.print("Poz: ");
    Serial.println(pozycja);
    serwo.write(pozycja); 
  }
  readString="";
}


// GND (czarny, ciemnobrązowy) - GND
// +5V Zasilanie (czerwony) - +5V
// Sygnał sterujący (żółty/pomarańczowy) - 9


