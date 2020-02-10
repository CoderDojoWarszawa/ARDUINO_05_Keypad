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
 
void setup(){
  Serial.begin(9600);
  Serial.println("Inicjacja komunikacji");
} 
void loop(){
  char klawisz = klawiatura.getKey();  
  if (klawisz){
    Serial.println(klawisz);
  }
}






