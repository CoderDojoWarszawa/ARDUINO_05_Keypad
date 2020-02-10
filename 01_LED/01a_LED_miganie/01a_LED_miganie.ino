/*********************************************************************
Połączenia:

Dioda LED Anoda  - pin 8
Dioda LED Katoda - GND - masa - 0V
*********************************************************************/

// Instrukcje wykonywane raz po starcie Arduino
void setup() {  
  //Ustawienie pinu 8 jako wyjście
  pinMode(8, OUTPUT);
}


//Instrukcje, które będą wykonywały się w koło (w pętli) 
void loop() {
  digitalWrite(8, HIGH); //Włączenie diody
  delay(1000); //Odczekanie 1 sekundy
  digitalWrite(8, LOW); //Wyłączenie diody
  delay(1000); //Odczekanie jednej sekundy
}
