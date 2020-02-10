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
}

void refresh(){
  wyswietlacz.refreshDisplay();
}

void loop() {
  wyswietlacz.setNumber(34); //Wyswietl liczbę 34
  delay(1000);
  wyswietlacz.setChars("er");
  delay(1000);
}


  
