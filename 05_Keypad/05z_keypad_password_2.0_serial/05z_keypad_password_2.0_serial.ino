#include <Keypad.h>
#include <Password.h>
 
String newPasswordString; //hold the new password
char newPassword[6]; //charater string of newPasswordString
 
//initialize password to 1234
//you can use password.set(newPassword) to overwrite it
Password password = Password( "1234" );
 
byte maxPasswordLength = 6; 
byte currentPasswordLength = 0;
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
 
//Define the keymap
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
 
byte rowPins[ROWS] = {9, 8, 7, 6}; //Piny wierszy
byte colPins[COLS] = {5, 4, 3, 2}; //Piny kolum 
 
// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup(){
   Serial.begin(9600);
   Serial.println("Podaj hasło:");
}
 
void loop(){
   char key = keypad.getKey();
   if (key != NO_KEY){
      delay(60); 
      switch (key){
      case 'A': break; 
      case 'B': break; 
      case 'C': break; 
      case 'D': changePassword(); break; 
      case '#': checkPassword(); break;
      case '*': resetPassword(); break;
      default: processNumberKey(key);
      }
   }
}
 
void processNumberKey(char key) {
   Serial.print(key);
   currentPasswordLength++;
   password.append(key);
   if (currentPasswordLength == maxPasswordLength) {
      checkPassword();
   } 
}

void checkPassword() {
   if (password.evaluate()){
      Serial.println(" OK.");
   } else {
      Serial.println(" Wrong passwowrd!");
   } 
   resetPassword();
}

void resetPassword() {
   password.reset(); 
   currentPasswordLength = 0; 
}

void changePassword() {
//   newPasswordString = "123";
   newPasswordString.toCharArray(newPassword, newPasswordString.length()+1); //convert string to char array
   password.set(newPassword);
   resetPassword();
   Serial.print("Password changed to ");
   Serial.println(newPasswordString);
}

