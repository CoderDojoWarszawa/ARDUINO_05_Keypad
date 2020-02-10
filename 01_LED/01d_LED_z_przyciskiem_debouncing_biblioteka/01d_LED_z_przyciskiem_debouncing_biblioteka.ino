/*********************************************************************
Połączenia:

Dioda LED Anoda  - pin 8
Dioda LED Katoda - GND - masa - 0V

Przycisk 1 - pin 7
Przycisk 2 - GND - masa - 0V

https://github.com/thomasfredericks/Bounce2
*********************************************************************/
#include <Bounce2.h>

// Inicjalizacja obiektu bounce
Bounce przycisk = Bounce();

// Instrukcje wykonywane raz po starcie Arduino
void setup() {  

  //Ustawienie pinu 8 jako wyjście
  pinMode(8, OUTPUT);
  //Ustawienie pinu 7 jako wejście z dodatkowym rezystorem podciągającym
  pinMode(7, INPUT_PULLUP);

  //Ustawienie działania obiektu bounce
  przycisk.attach(7);
  przycisk.interval(5); //Czas w ms jaki ignorować
  
  //Wyłączenie diody
  digitalWrite(8, LOW); 
}

// deklaracja zmiennej typu boolean
boolean stan_diody = false;

//Instrukcje, które będą wykonywały się w koło (w pętli) 
void loop() {
  przycisk.update();
 
// Jeśli wykryje zmiane stanu przycisku z wysokiego na niski to zadziała pętla
  if (przycisk.fell() == true) {
    // przełączenie diody w stan przeciwny do obecnego
    stan_diody = !stan_diody;
    digitalWrite(8, stan_diody);
    } 
}

