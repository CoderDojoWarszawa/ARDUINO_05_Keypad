#include <LiquidCrystal.h>
#define pompka 10

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
// Deklaracja zmiennych pomocniczych
int progDzialania = 0;
int wilgotnoscGleby = 0;
int skalaDzialania =0;
int skalaGleby=0;

void setup() {
  lcd.begin(16, 2);
  pinMode(pompka, OUTPUT);
}
void loop() { 
  digitalWrite(pompka,HIGH);
  progDzialania = analogRead(A0);
  skalaDzialania=map(progDzialania, 0, 1023, 0, 100);
  wilgotnoscGleby = analogRead(A5);
  skalaGleby=map(wilgotnoscGleby, 0, 800, 0, 100);
  lcd.home();
  lcd.print("Wilgotnosc:     ");
  lcd.setCursor(12, 0);
  lcd.print(skalaGleby);
  lcd.print(" %"); 
  lcd.setCursor(0, 1);
  lcd.print("Prog:           ");
  lcd.setCursor(6, 1);
  lcd.print(skalaDzialania);
  lcd.print(" %");
  if (skalaGleby < skalaDzialania){
    lcd.setCursor(0,1);
    lcd.print("Pompka wlaczona");   
    digitalWrite(pompka,LOW);
    delay(1000);
  }
  digitalWrite(pompka,HIGH);
  lcd.setCursor(0, 1);
  lcd.print("Prog:           ");
  lcd.setCursor(6, 1);
  lcd.print(skalaDzialania);
  lcd.print(" %");
  delay(5000);
}


