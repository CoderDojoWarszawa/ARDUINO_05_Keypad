#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.home();
  lcd.print("Zajecia");
  lcd.setCursor(0, 1);
  lcd.print("CoderDojo");
  delay(3000);
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
