#define trigPin 12
#define echoPin 11

void setup(){
  Serial.begin(9600); //Komunikacja serial z prędkością 9600
  //Ustawienie pinów dla czujnika odległości
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

int zmierzOdleglosc(){ //Funkcja mierzaca i zwracająca odleglość w cm
  int dystans = 0;
  // Wyzwolenie pomiaru 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Odczyt wyniku pomiaru i obliczenie odleglości
  dystans = pulseIn(echoPin, HIGH) / 58; 
  if (dystans > 100){
    dystans=100;
  }
  return dystans;
}

int odleglosc; //Zmienna przechowująca odległość

void loop() {
  odleglosc = zmierzOdleglosc();
  Serial.print(odleglosc);
  Serial.println(" cm");
  delay(200);
}

