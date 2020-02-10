/*********************************************************************
Połączenia:

Dioda LED Anoda  - pin 8
Dioda LED Katoda - GND - masa - 0V

Przycisk 1 - pin 7
Przycisk 2 - GND - masa - 0V
*********************************************************************/


// Instrukcje wykonywane raz po starcie Arduino
void setup() {  
  //Ustawienie pinu 8 jako wyjście
  pinMode(8, OUTPUT);
  //Ustawienie pinu 7 jako wejście z dodatkowym rezystorem podciągającym
  pinMode(7, INPUT_PULLUP);
  digitalWrite(8, LOW); //Wyłączenie diody
}

// deklaracja zmiennej
boolean stan_diody = LOW;

//Instrukcje, które będą wykonywały się w koło (w pętli) 
void loop() {
 
// Jeśli przycisk wciśnięty
  if (digitalRead(7) == LOW) {
    // przełączenie diody w stan przeciwny do obecnego
    stan_diody = !stan_diody;
    digitalWrite(8, stan_diody);
    // debouncing - drgania styków
    delay(50);
  } 
}

