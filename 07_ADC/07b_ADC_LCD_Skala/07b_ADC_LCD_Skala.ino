#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int odczyt = 0;
int skala = 0;

void setup() {
  lcd.begin(16, 2);
}

void loop() {    
  //Odczyt wartości z ADC
  odczyt = analogRead(A0);
  skala = map(odczyt, 0, 1023, 0, 16);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ADC:     ");
  lcd.setCursor(5, 0);
  lcd.print(odczyt);
  Serial.println(skala);
  lcd.setCursor(0, 1);
  for (int i=0; i < skala; i++){
    lcd.print("#");
  }
  delay(100);
}



