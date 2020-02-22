/********************************************************************
  MotorShield v.3

  Niebieskie złącze:
  Vin - zewnętrzne zasilanie silników 7-12V - zasila też Arduino
  GND - zewnętrzne zasilanie silników GND
  A: + - podłączenie silnika A
  B: + - podłączenie silnika B

  Sterowanie silnikami:
  12 - kierunek silnik A
  13 - kierunek silnik B
  3 - PWM silnik A
  11 - PWM silnik B
  9 - hamulec silnik A
  8 - hamules silnik B
  A0 - pomiar prądu silnik A
  A1 - pomiar prądu silnik B

*********************************************************************/
#include <TM1637Display.h>
#define DIR_L 12
#define DIR_R 13
#define PWM_L 3
#define PWM_R 11
#define STOP_L 9
#define STOP_R 8
#define pin_R A5
#define pin_L A4
#define CLK 2
#define DIO 4
#define PUSH 7

TM1637Display display(CLK, DIO);

// Zmienne pomocnicze
int wartosc_R = 0;
int wartosc_L = 0;
int roznica = 0;
boolean jazda = false;

void setup() {
  //Inicjacja potrzebnych wejść do sterowania silnikami
  pinMode(DIR_L, OUTPUT);
  pinMode(DIR_R, OUTPUT);
  pinMode(PWM_L, OUTPUT);
  pinMode(PWM_R, OUTPUT);
  pinMode(STOP_L, OUTPUT);
  pinMode(STOP_R, OUTPUT);
  pinMode(pin_R, INPUT);
  pinMode(pin_L, INPUT);
  pinMode(PUSH, INPUT_PULLUP);
  display.setBrightness(0x09);
}

// Funkcja sterująca lewym silnikiem
void motor_L(int V) {
  // Wyłączenie hamulca
  digitalWrite(STOP_L, LOW);
  if (V > 0) {
    // Przemapowanie prędkości z zakresu 0-100 na wartości wypełnienia 100-255
    V = map(V, 0, 100, 100, 255);
    digitalWrite(DIR_L, LOW);
    analogWrite(PWM_L, V);
  } else {
    // Jeśli prędkość poniżej zera to przyjmij wartość dodatnią
    V = abs(V);
    // Przemapowanie prędkości z zakresu 0-100 na wartości wypełnienia 100-255
    V = map(V, 0, 100, 100, 255);
    digitalWrite(DIR_L, HIGH);
    analogWrite(PWM_L, V);
  }
}

// Funkcja sterująca prawym silnikiem
void motor_R(int V) {
  // Wyłączenie hamulca
  digitalWrite(STOP_R, LOW);
  if (V > 0) {
    // Przemapowanie prędkości z zakresu 0-100 na wartości wypełnienia 100-255
    V = map(V, 0, 100, 100, 255);
    digitalWrite(DIR_R, LOW);
    analogWrite(PWM_R, V);
  } else {
    // Jeśli prędkość poniżej zera to przyjmij wartość dodatnią
    V = abs(V);
    // Przemapowanie prędkości z zakresu 0-100 na wartości wypełnienia 100-255
    V = map(V, 0, 100, 100, 255);
    digitalWrite(DIR_R, HIGH);
    analogWrite(PWM_R, V);
  }
}

// Hamowanie lewym silnikiem
void stop_L(void) {
  analogWrite(PWM_L, 0);
  digitalWrite(STOP_L, HIGH);
}

// Hamowanie prawym silnikiem
void stop_R(void) {
  analogWrite(PWM_R, 0);
  digitalWrite(STOP_R, HIGH);
}

void loop() {
  wartosc_R = analogRead(pin_R);
  wartosc_L = analogRead(pin_L);
  roznica = wartosc_R - wartosc_L;
  if (roznica < -200) {
    roznica = -200;
  } else if (roznica > 200) {
    roznica = 200;
  }
  int zmianaPredkosci = map(roznica, -200, 200, -20, 20);
  display.showNumberDec(zmianaPredkosci, false, 4, 0);
  
  if (digitalRead(PUSH) == LOW) {
    jazda = true;
  }
  if (jazda == true) {
    motor_L(15 + zmianaPredkosci);
    motor_R(15 - zmianaPredkosci);
  }
}
