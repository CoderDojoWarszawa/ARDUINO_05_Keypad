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
byte godzina = 23;
byte minuta = 59;
byte sekunda = 30;
  
void loop() {
  display.showNumberDecEx(minuta*100+sekunda, 0x40, true, 4, 0);
  delay(500);
  display.showNumberDecEx(minuta*100+sekunda, 0, true, 4, 0);
  delay(500);
  sekunda++;
  if (sekunda == 60){
    minuta++;
    sekunda=0;
  }
  if (minuta == 60){
    godzina++;
    minuta=0;
  }
  if (godzina == 24){
    godzina=0;
  }
  if (sekunda%10==5){
    sensors.requestTemperatures(); //Pobranie temperatury
    //Wyświetlenie temperatury
    display.showNumberDec(sensors.getTempCByIndex(0),false,2,0);
    //Wyświetlenie napisu oC 
    display.setSegments(stopnieC,2,2);
    delay(2000);
    sekunda++;
    sekunda++;
  }  
}
