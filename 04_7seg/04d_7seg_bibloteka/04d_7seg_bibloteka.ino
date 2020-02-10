#include "SevSeg.h"
//Utwórz instancję wyswietlacz
SevSeg wyswietlacz;

void czujnik(void){
  delay(100);
}

void setup() {
  //Ustawienie parametrów wyświetlacza i jego inicjacja
  byte numDigits = 2; //Ile cyfr ma wyświetlacz
  byte digitPins[] = {10, 11}; //Piny cyfr
  byte segmentPins[] = {9, 8, 2, 5, 4, 7, 6, 3}; //Piny segmentów {A, B, C, D, E, F, G, P}
  bool resistorsOnSegments = true; //Czy są rezystory na segmentach
  byte hardwareConfig = COMMON_CATHODE; //Typ podłączenia wyświetlacza
  wyswietlacz.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
}

void loop() {
  wyswietlacz.setNumber(34); //Wyswietl liczbę 34
  wyswietlacz.refreshDisplay();
}

