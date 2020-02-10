#include "SevSeg.h"
#include "TimerOne.h"

//Stwórz instancję wyswietlacz
SevSeg wyswietlacz;

void setup() {
  Timer1.initialize(10000); // Ustawienie przerwania czasowego na 10ms
  Timer1.attachInterrupt(refresh); //Jako kod przerwania wywołaj funkcję refresh
  //Ustawienie parametrów wyświetlacza i jego inicjacja
  byte numDigits = 2; //Ile cyfr ma wyświetlacz
  byte digitPins[] = {10, 11}; //Piny cyfr
  byte segmentPins[] = {9, 8, 2, 5, 4, 7, 6, 3}; //Piny segmentów {A, B, C, D, E, F, G, P}
  bool resistorsOnSegments = true; //Czy są rezystory na segmentach
  byte hardwareConfig = COMMON_CATHODE; // Typ podłączenia
  wyswietlacz.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
}

int temp=0;
int liczba=0;
int zmiana=0;

void refresh(){
  wyswietlacz.refreshDisplay();
  temp++;
  if (temp == 100){
    liczba = liczba + zmiana;
    temp =0;
  }
}

void loop() {
  wyswietlacz.setNumber(liczba);
  if (liczba == 100){
    liczba=0;
  }
  if ((zmiana == 0) && (digitalRead(12) == LOW)){
    delay(200);
    zmiana = 1;
  }
  if ((zmiana == 1) && (digitalRead(12) == LOW)){
    delay(200);
    zmiana = 0;
  }
  if (digitalRead(13) == LOW){
    delay(50);
    zmiana = 0;
    liczba = 0;
  }
}



