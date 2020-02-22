#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire czujnik(2); //Podłączenie czujnika do pin 2
//Przekazane nr. pin do biblioteki, sesnors to nasz czujnik
DallasTemperature sensors(&czujnik); 

//0x27 - adres I2C wyświetlacza
//16 - liczba znaków
//2 - liczba wierszy
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  //Inicjalizacja czujnika
  sensors.begin(); 
  //Inicjacja wyświetlacza
  lcd.init();
  //Włączenie podświetlenia
  lcd.backlight();
  //Ustawienie kursora na pozycji 0, 0
  lcd.home();
  // Wyświetlenie napisu
  lcd.print("Temperatura:");
}

//Zmienna przechowująca temperaturę
float temperatura=0;

void loop() {
  //Pobranie temperatury
  sensors.requestTemperatures(); 
  temperatura = sensors.getTempCByIndex(0);
  //Ustawienie kursora na pozycji 0, 1
  lcd.setCursor(0, 1);
  //Wyświetlenie temperatury
  lcd.print(temperatura);
  delay(500);
}


