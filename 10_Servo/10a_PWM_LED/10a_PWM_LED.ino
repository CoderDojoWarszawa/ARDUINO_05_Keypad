void setup() {  
  pinMode(9, OUTPUT); //Ustawienie pinu 9 jako wyjście
}

void loop() {
  digitalWrite(9, HIGH); //Włączenie diody
  delay(1000); //Odczekanie 1 sekundy
  digitalWrite(9, LOW); //Wyłączenie diody
  delay(1000); //Odczekanie jednej sekundy
}


/*********************************************************************
Połączenia:

Dioda LED Anoda  - pin 8
Dioda LED Katoda - GND - masa - 0V
*********************************************************************/

