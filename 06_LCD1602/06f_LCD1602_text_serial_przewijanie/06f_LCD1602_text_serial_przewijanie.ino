#include <LiquidCrystal.h>

/*
 Wyświetlacz podłączenie:
 VSS - masa - GND
 VDD - zasilanie +5V
 V0 - kontrast - potencjometr do +5V i GND 
 RS - pin 2 - wybór rejestrów (komenda, dane)
 RW - masa - GND
 E - pin 3 - zezwolenie na zapis do rejestrów
 D4 - pin 4 - dane
 D5 - pin 5 - dane
 D6 - pin 6 - dane
 D7 - pin 7 - dane
 A - zasilanie +5V - zasilanie podświetlenia
 K - masa GND - masa podświetlenia  
 */
 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
String odebrane;
int x = 0;

void setup() {
  //Inicjacja komunikacji serial
  Serial.begin(9600);
  Serial.println("Jestem Arduino i Czekam na tekst:");  
  //Deklaracja typu wyświetlacza
  lcd.begin(16, 2);
  //Ustawienie kursora na pozycji 0, 0
  lcd.setCursor(0, 0);
  //Wyświetlenie napisu
  lcd.print("Odebralem: ");
}

void loop() {
  //Oczekiwanie na dane z serial
  if (Serial.available() > 0){
    odebrane = Serial.readStringUntil('/n');
//    Serial.print("Odebralem znakow :");
//    Serial.println(odebrane.length());
    x=0;
  }
  //Proste przewijanie tekstu
  if (x == 17){
    x = 0;
  } else {
    x++ ;    
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Odebralem: ");
  lcd.setCursor(x, 1);
  lcd.print(odebrane);
  delay(500);
}


