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

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Zajecia");
  lcd.setCursor(0, 1);
  lcd.print("CoderDojo");
  delay(2000);
}
void loop() {
  for (int i=0; i<16; i++){
    lcd.scrollDisplayRight();
    delay(1000);
  }
  for (int i=0; i<16; i++){
    lcd.scrollDisplayLeft();
    delay(1000);
  }
}



