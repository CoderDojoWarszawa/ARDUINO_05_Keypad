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

  Inne:
  A3 - buzer
  7 - odbiornik IR

*********************************************************************/
#include <IRremote.h>
#define pin_IR 7
#define DIR_L 12
#define DIR_R 13
#define PWM_L 3
#define PWM_R 11
#define STOP_L 9
#define STOP_R 8
#define buzzer A3

IRrecv irrecv(pin_IR);
decode_results odczyt;

// Zmienne pomocnicze

void setup() {
  //Inicjacja odczytu kodów IR
  irrecv.enableIRIn(); // Aktywacja odczytu
  //Inicjacja potrzebnych wejść do sterowania silnikami
  pinMode(DIR_L, OUTPUT);
  pinMode(DIR_R, OUTPUT);
  pinMode(PWM_L, OUTPUT);
  pinMode(PWM_R, OUTPUT);
  pinMode(STOP_L, OUTPUT);
  pinMode(STOP_R, OUTPUT);
}

// Wydaj dźwięk
void bip() {
  tone(buzzer, 2800);
  delay(100);
  noTone(buzzer);
  delay(100);
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

void taniec1() {
  bip();
  motor_L(50);
  delay(200);
  motor_R(-50);
  delay(200);
  stop_L();
  delay(200);
  stop_R();
  delay(300);
  motor_L(30);
  motor_R(30);
  delay(500);
  stop_L();
  stop_R();
  delay(1000);
  bip();
  for (int i = 0; i <= 4; i++) {
    motor_L(50);
    motor_R(-50);
    delay(400);
    stop_L();
    delay(300);
  }
  delay(1000);
  bip();
  for (int i = 0; i <= 4; i++) {
    motor_L(50);
    motor_R(-50);
    delay(400);
    stop_R();
    delay(300);
  }
  stop_L();
  bip();
  delay(50);
  bip();
}

void taniec2(void) {
  bip();
  motor_L(50);
  motor_R(50);
  delay(1000);
  stop_L();
  stop_R();
  delay(50);
  motor_L(-50);
  motor_R(-50);
  delay(1000);
  stop_L();
  stop_R();
  bip();
  delay(50);
  bip();
}

void taniec3(void) {
  bip();
  motor_L(100);
  motor_R(100);
  delay(1000);
  stop_L();
  stop_R();
  delay(50);
  motor_L(-100);
  motor_R(-100);
  delay(1000);
  stop_L();
  stop_R();
  bip();
  delay(50);
  bip();
}

void taniec4(void) {
  bip();
  motor_L(-50);
  motor_R(50);
  delay(1000);
  stop_L();
  stop_R();
  delay(50);
  motor_L(50);
  motor_R(-50);
  delay(1000);
  stop_L();
  stop_R();
  bip();
  delay(50);
  bip();
}

void taniec5() {
  bip();
  motor_L(50);
  delay(200);
  motor_R(-50);
  delay(200);
  stop_L();
  delay(200);
  stop_R();
  delay(300);
  motor_L(30);
  motor_R(30);
  delay(500);
  stop_L();
  stop_R();
  delay(1000);
}

void taniec6(void) {
  bip();
  for (int i = 0; i <= 4; i++) {
    motor_L(-50);
    motor_R(50);
    delay(1000);
    stop_L();
    stop_R();
    delay(50);
    motor_L(50);
    motor_R(-50);
    delay(1000);
    stop_L();
    stop_R();
    bip();
    delay(50);
    bip();
  }
}


void loop() {
  if (irrecv.decode(&odczyt)) {
    Serial.println(odczyt.value, HEX);
    // Porównywanie wartości w HEX. Przed liczbą HEX dajemy 0x
    switch (odczyt.value) {
      case 0xFFA25D: taniec1(); break;  // cyfra 1
      case 0xFF629D: taniec2(); break;  // cyfra 2
      case 0xFFE21D: taniec3(); break;  // cyfra 3
      case 0xFF22DD: taniec4(); break;  // cyfra 4
      case 0xFF02FD: taniec5(); break;  // cyfra 5
      case 0xFFC23D: taniec6(); break;  // cyfra 6
      case 0xFFE01F: break;  // cyfra 7
      case 0xFFA857: break;  // cyfra 8
      case 0xFF906F: break;  // cyfra 9
    }
    irrecv.resume();
  }
}
