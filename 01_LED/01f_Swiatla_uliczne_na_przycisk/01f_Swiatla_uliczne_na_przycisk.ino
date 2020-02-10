/*********************************************************************
Połączenia:

Anoda LED zielona   - pin 8
Anoda LED żółta     - pin 9
Anoda LED czerwona  - pin 10

Katoda wszystkie LED - GND - masa - 0V

Przycisk 1 - pin 7
Przycisk 2 - GND - masa - 0V
*********************************************************************/


// Instrukcje wykonywane raz po starcie Arduino
void setup() {
  pinMode(10, OUTPUT); //Dioda czerwona
  pinMode(9, OUTPUT); //Dioda żółta
  pinMode(8, OUTPUT); //Dioda zielona
  pinMode(7, INPUT_PULLUP); //Przycisk

// Wyłączenie diod
  digitalWrite(10, LOW); 
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);  
}

//Instrukcje, które będą wykonywały się w koło (w pętli) 
void loop() {
// Włączenie zielonej diody
  digitalWrite(8, HIGH); //Zielona

//Jeśli przycisk jest wciśnięty to idź dalej
  delay(1000);
  while (digitalRead(7) == HIGH) {}  

// Zielona gaśnie, pali się żółta
  digitalWrite(8, LOW); //Zielona
  digitalWrite(9, HIGH); //Żółta 

//Jeśli przycisk jest wciśnięty to idź dalej
  delay(1000);
  while (digitalRead(7) == HIGH) {}  
  
// Żółta gaśnie, pali się czerwona
  digitalWrite(9, LOW); //Żółta
  digitalWrite(10, HIGH); //Czerwona 

//Jeśli przycisk jest wciśnięty to idź dalej
  delay(1000);
  while (digitalRead(7) == HIGH) {}  

// Pali się czerwona z żółtą 
  digitalWrite(10, HIGH); //Czerwona
  digitalWrite(9, HIGH); //Żółta

//Jeśli przycisk jest wciśnięty to idź dalej
  delay(1000);
  while (digitalRead(7) == HIGH) {}  
}
