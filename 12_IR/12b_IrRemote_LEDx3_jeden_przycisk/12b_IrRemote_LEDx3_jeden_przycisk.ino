#include <IRremote.h>
#define pin_IR 11
#define Red 2
#define Yellow 3
#define Green 4

IRrecv irrecv(pin_IR);
decode_results odczyt;
int lastRed =LOW;
int lastYellow =LOW;
int lastGreen =LOW;

void setup(){
  Serial.begin(9600); 
  irrecv.enableIRIn(); // Aktywacja odczytu
  irrecv.blink13(true); // Po odebraniu kodu migaj diodą LED 13
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
  digitalWrite(Red, lastRed);
  digitalWrite(Yellow, lastYellow);
  digitalWrite(Green, lastGreen);
}
void loop(){
  if (irrecv.decode(&odczyt)){
    Serial.println(odczyt.value, HEX);
    irrecv.resume();
  }
  // Porównywanie wartości w HEX. Przed liczbą HEX dajemy 0x
  switch (odczyt.value){
    case 0xFFA25D: lastRed=!lastRed; digitalWrite(Red, lastRed); break;    // cyfra 1
    case 0xFF629D: lastYellow=!lastYellow; digitalWrite(Yellow, lastYellow); break; // cyfra 2
    case 0xFFE21D: lastGreen=!lastGreen; digitalWrite(Green, lastGreen); break;  // cyfra 3
  }
  delay(200);
}



