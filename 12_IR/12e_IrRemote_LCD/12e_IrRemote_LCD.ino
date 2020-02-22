#include <IRremote.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define pin_IR 11
#define pin_Servo 9

IRrecv irrecv(pin_IR);
decode_results odczyt;
Servo serwo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

char znak;
String tekst = "";
int pozycja =0;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Aktywacja odczytu
  irrecv.blink13(true); // Po odebraniu kodu migaj diodą LED 13
  serwo.attach(pin_Servo);
  lcd.init();
  lcd.backlight();
  lcd.home();
  lcd.print("Odebrane:");
}

void loop() {
  if (irrecv.decode(&odczyt) == true) {
    Serial.println(odczyt.value, HEX);
    // Porównywanie wartości w HEX. Przed liczbą HEX dajemy 0x
    switch (odczyt.value) {
      case 0xFF9867: tekst += '0'; break;
      case 0xFFA25D: tekst += '1'; break;
      case 0xFF629D: tekst += '2'; break;
      case 0xFFE21D: tekst += '3'; break;
      case 0xFF22DD: tekst += '4'; break;
      case 0xFF02FD: tekst += '5'; break;
      case 0xFFC23D: tekst += '6'; break;
      case 0xFFE01F: tekst += '7'; break;
      case 0xFFA857: tekst += '8'; break;
      case 0xFF906F: tekst += '9'; break;
      case 0xFF38C7: serwo.write(pozycja); tekst = ""; break;
    }
    pozycja = tekst.toInt();
    if (pozycja > 180){
      pozycja = 180;
    }
    irrecv.resume();
    lcd.setCursor(0, 1);
    lcd.print(tekst);
    lcd.print("                ");
  }
//  Serial.print("Text: ");
//  Serial.print(tekst);
//  Serial.print(" INT:");
//  Serial.println(pozycja);
  delay(100);
}

