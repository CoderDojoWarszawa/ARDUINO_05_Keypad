#include <OneWire.h>
#include <DallasTemperature.h>
OneWire czujnik(2); //Podłączenie do pin 2
DallasTemperature sensors(&czujnik); //Przekazane nr. pin do biblioteki

void setup() {
  Serial.begin(9600);
  sensors.begin(); //Inicjalizacja czujnika
}
 
void loop() { 
  sensors.requestTemperatures(); //Pobranie temperatury
  Serial.print("Aktualna temperatura: ");
  Serial.println(sensors.getTempCByIndex(0));  //Wyswietlenie informacji
  delay(500);
}




