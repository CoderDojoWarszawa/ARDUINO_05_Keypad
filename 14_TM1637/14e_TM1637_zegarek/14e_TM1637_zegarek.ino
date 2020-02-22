#include <TM1637Display.h>
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);

void setup() {
  //Ustawienie jasności wyświetlacza
  display.setBrightness(0x0A);
  //Wyczyszczenie wyświetlacza
  display.clear();
}

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
}
