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
int i = 0;
int j = 0;
int k = 0;
int delayTime2 = 350; // Delay between shifts

void scrollInFromRight (int line, char str1[]) {
  i = strlen(str1); 
  for (j = 16; j >= 0; j--) {
    lcd.setCursor(0, line);
    for (k = 0; k <= 15; k++) {
      lcd.print(" "); // Clear line
    }
    lcd.setCursor(j, line);
    lcd.print(str1);
    delay(delayTime2);
  }
}

void scrollInFromLeft (int line, char str1[]) {
  i = 40 - strlen(str1);
  line = line - 1;
  for (j = i; j <= i + 16; j++) {
    for (k = 0; k <= 15; k++) {
      lcd.print(" "); // Clear line
    }
    lcd.setCursor(j, line);
    lcd.print(str1);
    delay(delayTime2);
  }
}

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Zajecia");
  lcd.setCursor(0, 1);
  lcd.print("CoderDojo");
  delay(2000);
}

void loop() {
  lcd.clear();
  scrollInFromRight(0, "CoderDojo");
  scrollInFromRight(1, "Warszawa");
  delay(1000);
  lcd.clear();
  scrollInFromLeft(0, "Zajecia");
  scrollInFromLeft(1, "Elektronika");
  delay(1000);
  lcd.clear();
  scrollInFromRight(0, "Zajecia");
  scrollInFromLeft(1, "Arduino");
  delay(1000);
}


