#include <IRremote.h>
#define pin_IR 11
// Tworzenie instancji klasy IRrecv o nazwie irrecv
IRrecv irrecv(pin_IR);
// Tworzenie instancji klasy decode_results o nazwie odczyt
// Tak naprawdę jest to zbiór zmiennych
decode_results odczyt;
  
void setup(){
  Serial.begin(9600); 
  irrecv.enableIRIn(); // Aktywacja odczytu
  irrecv.blink13(true); // Po odebraniu kodu migaj diodą LED 13
}
void loop(){
  // Jeśli są jakieś dane odebrane to zwracane jest TRUE
  // Odczytane dane są podstawiane do odczyt
  if (irrecv.decode(&odczyt) == true){
    // Wysłanie na serial odczytanego kodu w postaci HEX  
    Serial.println(odczyt.value, HEX);
    // Przygotowanie do pobrania nowego kodu
    irrecv.resume();
  }
}



