#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
String odebrane;


void setup() {
  //Inicjacja komunikacji serial
  Serial.begin(9600);
  Serial.println("Jestem Arduino i Czekam na tekst:");  
  lcd.init();
  lcd.backlight();
  lcd.home();
  lcd.print("Odebralem: ");
}

void loop() {
  //Oczekiwanie na dane z serial
  if (Serial.available() > 0){
    odebrane = Serial.readStringUntil('\n');
    //Po odebraniu danych wyczyść wyświetlacz
    lcd.clear();
    lcd.home();
    lcd.print("Odebralem: ");
    //Ustawienie kursora 0,1 i wyświetlenie danych
    lcd.setCursor(0, 1);
    lcd.print(odebrane);
  }
}
