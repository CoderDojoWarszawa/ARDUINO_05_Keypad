#include <LiquidCrystal_I2C.h>
#include <SimpleDHT.h>

//Czujnik podłączony pod pin 7
#define pinCzujnik 7
//Tworzenie instancji czujnika o nazwie dth11
SimpleDHT11 dht11;

//0x27 - adres I2C wyświetlacza
//16 - liczba znaków
//2 - liczba wierszy
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  //Inicjacja wyświetlacza
  lcd.init();
  //Włączenie podświetlenia
  lcd.backlight();
}

//Zmienne przechowujące temperaturę i wilgotność
byte temperatura = 0;
byte wilgotnosc = 0;

void loop() {
  int err = 0;
  //Pobranie temperatury
  //Pobranie zmierzonych wartości temperatury i wilgotności
  err = dht11.read(pinCzujnik, &temperatura, &wilgotnosc, NULL);
  if (err == 0){
    lcd.home();
    // Wyświetlenie napisu
    lcd.print("Temp: ");
    lcd.print(temperatura);
    lcd.print(" *C");
    //Ustawienie kursora na pozycji 0, 1
    lcd.setCursor(0, 1);
    //Wyświetlenie temperatury
    lcd.print("Wilg: ");
    lcd.print(wilgotnosc);
    lcd.print(" %RH");
  }
  delay(2000);
}


