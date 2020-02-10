/*********************************************************************
Połączenia:

Anoda LED czerwona  - pin 10
Anoda LED żółta     - pin 9
Anoda LED zielona   - pin 8

Anoda LED czerwona  - pin 6
Anoda LED zielona   - pin 5

Katoda wszystkie LED - GND - masa - 0V

*********************************************************************/


// Instrukcje wykonywane raz po starcie Arduino
void setup() {
  pinMode(10, OUTPUT); //Dioda czerwona
  pinMode(9, OUTPUT); //Dioda żółta
  pinMode(8, OUTPUT); //Dioda zielona
  pinMode(6, OUTPUT); //Dioda czerwona
  pinMode(5, OUTPUT); //Dioda zielona

// Wyłączenie diod
  digitalWrite(10, LOW); 
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);  
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);  
}

//Instrukcje, które będą wykonywały się w koło (w pętli) 
void loop() {
// Włączenie zielonej diody
  digitalWrite(10, LOW); //Czerwona
  digitalWrite(9, LOW); //Żółta
  digitalWrite(8, HIGH); //Zielona
  digitalWrite(6, HIGH); //Czerwone przejscie
  delay(3000);
// Zielona gaśnie, pali się żółta
  digitalWrite(8, LOW); //Zielona
  digitalWrite(9, HIGH); //Żółta 
  delay(800);
// Żółta gaśnie, pali się czerwona
  digitalWrite(9, LOW); //Żółta
  digitalWrite(10, HIGH); //Czerwona 
  digitalWrite(5, HIGH); //Zielone przejscie
  digitalWrite(6, LOW); //Czerwone przejscie
  delay(3000);
// Pali się czerwona z żółtą 
  digitalWrite(10, HIGH); //Czerwona
  digitalWrite(9, HIGH); //Żółta
  digitalWrite(5, LOW); //Zielone przejscie
  digitalWrite(6, HIGH); //Czerwone przejscie
  delay(800);
}
