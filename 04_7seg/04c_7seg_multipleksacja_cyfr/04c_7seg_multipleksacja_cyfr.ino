/*
Podłączenie wyświetlacza:
WYŚW  - ARDUINO - opis
pin 1 - pin 2 - segment C
pin 2 - pin 3 - segment P
pin 3 - pin 4 - segment E
pin 4 - pin 5 - segment D
pin 5 - pin 6 - segment G
pin 6 - pin 7 - segment F
pin 7 - pin 11 - cyfra 2 
pin 8 - pin 10 - cyfra 1 
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
#define CYF_1 10
#define CYF_2 11

void setup() {
  //Inicjacja pinów jako wyjścia
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(SEG_P, OUTPUT);
  pinMode(CYF_1, OUTPUT);
  pinMode(CYF_2, OUTPUT);
}

void czujnik(void){
  delay(100);
}

void wyswietlacz(int cyfra) {
//Instrukcja switch ustawia odpowiednie stany 
//na wyjściach w zależności od podanej cyfry
  switch (cyfra) {
    case 0:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, HIGH);
        digitalWrite(SEG_E, HIGH);
        digitalWrite(SEG_F, HIGH);
        digitalWrite(SEG_G, LOW);
    break; 
    
    case 1:
        digitalWrite(SEG_A, LOW);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, LOW);
        digitalWrite(SEG_E, LOW);
        digitalWrite(SEG_F, LOW);
        digitalWrite(SEG_G, LOW);
    break; 
    
    case 2:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, LOW);
        digitalWrite(SEG_D, HIGH);
        digitalWrite(SEG_E, HIGH);
        digitalWrite(SEG_F, LOW);
        digitalWrite(SEG_G, HIGH);
    break; 
    
    case 3:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, HIGH);
        digitalWrite(SEG_E, LOW);
        digitalWrite(SEG_F, LOW);
        digitalWrite(SEG_G, HIGH);
    break; 
    
    case 4:
        digitalWrite(SEG_A, LOW);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, LOW);
        digitalWrite(SEG_E, LOW);
        digitalWrite(SEG_F, HIGH);
        digitalWrite(SEG_G, HIGH);
    break; 
    
    case 5:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, LOW);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, HIGH);
        digitalWrite(SEG_E, LOW);
        digitalWrite(SEG_F, HIGH);
        digitalWrite(SEG_G, HIGH);
    break; 
    
    case 6:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, LOW);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, HIGH);
        digitalWrite(SEG_E, HIGH);
        digitalWrite(SEG_F, HIGH);
        digitalWrite(SEG_G, HIGH);
    break;
   
    case 7:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, LOW);
        digitalWrite(SEG_E, LOW);
        digitalWrite(SEG_F, LOW);
        digitalWrite(SEG_G, LOW);
    break;
    
    case 8:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, HIGH);
        digitalWrite(SEG_E, HIGH);
        digitalWrite(SEG_F, HIGH);
        digitalWrite(SEG_G, HIGH);
    break;
    
    case 9:
        digitalWrite(SEG_A, HIGH);
        digitalWrite(SEG_B, HIGH);
        digitalWrite(SEG_C, HIGH);
        digitalWrite(SEG_D, HIGH);
        digitalWrite(SEG_E, LOW);
        digitalWrite(SEG_F, HIGH);
        digitalWrite(SEG_G, HIGH);
    break;
  }
}

void loop() {
  digitalWrite(CYF_1, LOW); //Włącz pierwszą cyfrę
  digitalWrite(CYF_2, HIGH); //Wyłącz drugą cyfrę
  wyswietlacz(5); //Wyświetl cyfrę na wyświetlaczu
  delay(10);
  digitalWrite(CYF_1, HIGH); //Wyłącz pierwszą cyfrę
  digitalWrite(CYF_2, LOW); //Włącz drugą cyfrę
  wyswietlacz(3); //Wyświetl cyfrę na wyświetlaczu
  delay(10);
}


