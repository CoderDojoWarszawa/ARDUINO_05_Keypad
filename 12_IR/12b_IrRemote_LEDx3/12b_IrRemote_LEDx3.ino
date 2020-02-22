#include <IRremote.h>
#define pin_IR 11
#define Red 2
#define Yellow 3
#define Green 4

IRrecv irrecv(pin_IR);
decode_results odczyt;

void setup(){
  Serial.begin(9600); 
  irrecv.enableIRIn(); // Aktywacja odczytu
  irrecv.blink13(true); // Po odebraniu kodu migaj diodą LED 13
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
  digitalWrite(Red, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Green, LOW);
}
void loop(){
  if (irrecv.decode(&odczyt)){
    Serial.println(odczyt.value, HEX);
    irrecv.resume();
  }
  // Porównywanie wartości w HEX. Przed liczbą HEX dajemy 0x
  switch (odczyt.value){
    case 0xFFA25D: digitalWrite(Red, HIGH); break;    // cyfra 1
    case 0xFF629D: digitalWrite(Yellow, HIGH); break; // cyfra 2
    case 0xFFE21D: digitalWrite(Green, HIGH); break;  // cyfra 3
    case 0xFF22DD: digitalWrite(Red, LOW); break;     // cyfra 4
    case 0xFF02FD: digitalWrite(Yellow, LOW); break;  // cyfra 5
    case 0xFFC23D: digitalWrite(Green, LOW); break;   // cyfra 6
  }
}



