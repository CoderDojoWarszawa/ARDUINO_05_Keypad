/*
Podłączenie wyświetlacza:
WYŚW  - ARDUINO
pin 1 - pin 2 - segment C
pin 2 - pin 3 - segment P
pin 3 - pin 4 - segment E
pin 4 - pin 5 - segment D
pin 5 - pin 6 - segment G
pin 6 - pin 7 - segment F
pin 7 - pin GND - cyfra 2 
pin 8 - pin GND - cyfra 1 
pin 9 - pin 8   - segment B
pin 10 - pin 9  - segment A

UWAGA: Każdy segment łączymy przez rezystor - przynajmniej 2 kohm
*/

#define SEG_A 9
#define SEG_B 8
#define SEG_C 2
#define SEG_D 5
#define SEG_E 4
#define SEG_F 7
#define SEG_G 6
#define SEG_P 3

void setup() {
  //Inicjacja pinów jako wyjście
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(SEG_P, OUTPUT);
}

void loop() {
  //Test segmentów
  digitalWrite(SEG_A, HIGH);
  delay(800);
  digitalWrite(SEG_B, HIGH);
  delay(800);
  digitalWrite(SEG_C, HIGH);
  delay(800);
  digitalWrite(SEG_D, HIGH);
  delay(800);
  digitalWrite(SEG_E, HIGH);
  delay(800);
  digitalWrite(SEG_F, HIGH);
  delay(800);
  digitalWrite(SEG_G, HIGH);
  delay(800);
  digitalWrite(SEG_P, HIGH);
  delay(800);
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_E, LOW);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  digitalWrite(SEG_P, LOW);
  delay(800);
}
