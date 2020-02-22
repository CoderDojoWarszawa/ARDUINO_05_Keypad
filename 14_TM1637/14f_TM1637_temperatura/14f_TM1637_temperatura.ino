#include <TM1637Display.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define CLK 2
#define DIO 3
OneWire czujnik(4); //Termometr - pin 4
DallasTemperature sensors(&czujnik); 
TM1637Display display(CLK, DIO);

void setup() {
  sensors.begin(); //Inicjalizacja czujnika
  //Ustawienie jasności wyświetlacza
  display.setBrightness(0x0A);
  //Wyczyszczenie wyświetlacza
  display.clear();
}

byte stopnieC[]={ 
  SEG_A|SEG_B|SEG_F|SEG_G,  
  SEG_A|SEG_D|SEG_E|SEG_F
  }; 
  
void loop() {
  delay(1000);
  sensors.requestTemperatures(); //Pobranie temperatury
  //Wyświetlenie temperatury
  display.showNumberDec(sensors.getTempCByIndex(0),false,2,0);
  //Wy 
  display.setSegments(stopnieC,2,2);
}
