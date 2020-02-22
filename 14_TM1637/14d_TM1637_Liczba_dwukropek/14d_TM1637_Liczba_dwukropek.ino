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

byte sekundy=12;
byte minuty=56;

void loop() {
  //Wyświetlenie liczby
  display.showNumberDecEx(minuty*100+sekundy, 0x40, true, 4, 0);
  delay(500);
  display.showNumberDecEx(minuty*100+sekundy, 0, true, 4, 0);
  delay(500);
  sekundy++;
  if (sekundy =>60){
    sekundy=0;
    minuty++
  }

}
