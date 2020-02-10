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

void refresh(){
  wyswietlacz.refreshDisplay();
}

int liczba=0;
int zmiana=0;

void loop() {
  wyswietlacz.setNumber(liczba);
  delay(1000);
  liczba = liczba + zmiana;
  if (liczba == 100){
    liczba=0;
  }
  if (digitalRead(12) == LOW){
    zmiana = 1;
  }
  if (digitalRead(13) == LOW){
    zmiana = 0;
    liczba = 0;
  }
}



