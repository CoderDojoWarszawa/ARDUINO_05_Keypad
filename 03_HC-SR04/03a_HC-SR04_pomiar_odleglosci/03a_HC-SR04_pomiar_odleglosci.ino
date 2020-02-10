/*
  Czujnik odległości podłączenie:
  Vcc - zasilanie +5V
  echoPin - pin 11
  trigPin - pin 12
  GND - masa 
*/
#define trigPin 12
#define echoPin 11

void setup() {
  // Inicjacja komunikacji serial do komputera
  Serial.begin(9600);
  Serial.println("Inicjacja komunikacji");
  // Inicjacja wejść i wyjść Arduino
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// Funkcja mierzaca i zwracająca odleglość w cm
// Do funkcji nie trzeba dostarczać niczego. Funkcja zwraca zmierzoną odległość jako INT.
int zmierzOdleglosc(){
  int dystans = 0;
  // Wyzwolenie pomiaru przez podanie sygnału HIGH (+5V) na złącze trigPin czujnika odległości
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Odczyt wyniku pomiaru z pinu echoPin czujnika
  // Czujnik na pin echoPin zwraca impuls (stan HIGH +5V) proporcjonalny do zmierzonej odległości.
  // My mierzymy długość trwania tego impulsu w mikrosekundach.
  // Wyliczanie odległości - wzór z dokumentacji czujnika: cm = długość_impulsu / 58
  dystans = pulseIn(echoPin, HIGH, 3030) / 58;
  //3ci parametr to timeout czyli ile czujnik ma czekać na powrót sygnału
  //timeout to: 710+a*58 gdzie a to odleglosc w cm
  return dystans;
}

void loop() {
  // Wywołanie funkcji która mierzy odległość, wynik zapisywany jest do zmiennej odległość
  int odleglosc = zmierzOdleglosc();
  Serial.print(odleglosc);
  Serial.println(" cm");

  //Następny pomiar za 200ms.
  delay(200);
}
