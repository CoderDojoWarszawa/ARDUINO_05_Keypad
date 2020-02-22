#define pin_R A5
#define pin_L A4

int wartosc_R = 0;
int wartosc_L = 0;
int roznica = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Inicjacja komunikacji");
  pinMode(pin_R, INPUT);
  pinMode(pin_L, INPUT);
}

void loop() {
  wartosc_R = analogRead(pin_R);
  wartosc_L = analogRead(pin_L);
  roznica = wartosc_R - wartosc_L;
  Serial.print(wartosc_L);
  Serial.print(" . ");
  Serial.print(wartosc_R);
  Serial.print(" . ");
  Serial.println(roznica);
  delay(100);
}
