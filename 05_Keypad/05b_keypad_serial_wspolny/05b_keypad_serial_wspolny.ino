#include <Keypad.h>
const byte ROWS = 4; // Ile wierszy
const byte COLS = 4; // Ile kolumn 
byte rowPins[ROWS] = {9, 8, 7, 6}; //Piny wierszy
byte colPins[COLS] = {5, 4, 3, 2}; //Piny kolum 
char keys[ROWS][COLS] = { //Mapowanie klawiatury
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
//Inicjalizacja klawiatury
Keypad klawiatura = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char klucz[4] = {'1','2','3','4'};
char proba[4] = {'0','0','0','0'};
int z=0;
 
void setup(){
  Serial.begin(9600);
  Serial.println("Inicjacja komunikacji");
} 

void checkKEY(){
  int correct=0;
  for (int i=0; i<4;i++){
    if (proba[i]==klucz[i]){
      correct++;
    }
  }
  if (correct==4){
    Serial.println("Poprawny Kod");
  } else {
    Serial.println("Niepoprawny Kod !!!");
  }
}


void readKeypad(){
  char klawisz = klawiatura.getKey();  
  if (klawisz){
      switch(klawisz){
        case '*':
        z=0;
        break;
        case '#':
        checkKEY();
        break;
        default:
        Serial.print("*");
        proba[z]=klawisz;
        z++;
      }
      if (z == 4){
        Serial.println();
        z=0; 
      }
  }
}

void loop(){
  readKeypad(); 
}






