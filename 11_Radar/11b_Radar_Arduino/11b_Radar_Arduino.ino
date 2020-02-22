#include <Servo.h>. 
Servo serwo;  //Tworzymy instancję o nazwie serwo
#define trigPin 12
#define echoPin 11

void setup() 
{
  serwo.attach(9);  //Serwomechanizm podłączony do pin 9
  Serial.begin(9600); //Komunikacja serial z prędkością 9600
  //Ustawienie pinów dla czujnika odległości
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// Funkcja mierzaca i zwracająca odleglość w cm
int zmierzOdleglosc(){
  int dystans = 0;
  // Wyzwolenie pomiaru 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Odczyt wyniku pomiaru i obliczenie odleglości
  //3ci parametr to timeout czyli ile czujnik ma czekać na powrót sygnału
  //timeout=710+58*odległość w cm. Tutaj max to 50cm bo Processing przetwarza max 40cm
  dystans = pulseIn(echoPin, HIGH, 3610) / 58; 
  if (dystans == 0){
    dystans=400;
  }
  return dystans;
}

int odleglosc=0;
void loop() {
  //Obrót ramienia od 5 do 175 stopni
  for(int i=5;i<=175;i++){  
    serwo.write(i);
    delay(25);
    odleglosc = zmierzOdleglosc();
    //Wyslanie odleglosci przez port serial
    Serial.print(i);
    Serial.print(",");
    Serial.print(odleglosc);
    Serial.print(".");
  }
  //Obrót ramienia od 175 do 5 stopni
  for(int i=175;i>5;i--){  
    serwo.write(i);
    delay(25);
    odleglosc = zmierzOdleglosc();
    //Wyslanie odleglosci przez port serial
    Serial.print(i);
    Serial.print(",");
    Serial.print(odleglosc);
    Serial.print(".");
  }
}

