// Definicja wszystkich nut jest w oddzielnym pliku pitches.h
#include "pitches.h"
// Definicja pinu do którego podłączony jest buzzer
#define buzzer A0

// Nuty naszej piosenki trzymana jako tablica: melodia
int melodia[] = {
  NOTE_G4, NOTE_E4, 0, NOTE_G4, NOTE_E4, NOTE_G4, 
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_F4, 0, NOTE_F4, 
  NOTE_D4, 0, NOTE_F4, NOTE_D4, 0, NOTE_G4, NOTE_B4, NOTE_A4,
  NOTE_G4, NOTE_F4, NOTE_E4, 0, NOTE_G4, NOTE_G4, NOTE_E4, 0,
  NOTE_G4, NOTE_G4, NOTE_E4, 0, NOTE_G4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_GS4,
  NOTE_A4, 0, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_C5, 0
};

// Długość trwania każdej z nut: 2 = półnuta, 4 = ćwierćnuta , 8 = ósemka itp. 
// Trzymana jako tablica: czasTrwaniaNut. Rozmiar tablicy powinien być taki sam jak rozmiar tablicy melodia
int czasTrwaniaNut[] = {
  2, 3, 8, 2, 2, 2,  
  4, 4, 4, 4, 2, 2, 2,
  3, 8, 2, 3, 8, 2, 4, 4,
  4, 4, 2, 2, 4, 4, 3, 8,
  4, 4, 4, 4, 2, 4, 4, 4, 4,
  2, 2, 2, 4, 4, 2, 2
};

void setup() {
  // Użycie pinu do którego podłączony jest buzer jako WYJŚCIA=OUTPUT
  pinMode(A0, OUTPUT);
}

void loop() {
  // Przjście w pętli przez tablicję melodia. Rozmiar tablicy można wyliczyć za pomocą polecenia: sizeof()
  // Polecenie zwraca całkowity rozmiar pamięci zarezerwowany na tablicę. Aby więc obliczyć liczbę elementów
  // tablicy wystarczy podzielić go przez rozmiar pamięci zarezerwowany na pojedyńczy element tablicy   
  for (int nuta = 0; nuta < sizeof(melodia)/sizeof(melodia[0]); nuta++) {
    // Aby obliczyć czas trwania nuty dzielimy 1 sekundę przez pobrany z tabeli czas trwania nuty
    // ćwiercnuta = 1000/4, ósemka = 1000/8 itp.
    int dlugoscNuty = 1000 / czasTrwaniaNut[nuta];
    tone(buzzer, melodia[nuta], dlugoscNuty);

    // Aby rozróżnić nuty od siebie dodajemy pauzę między nimi: dlugoscNuty + 30% czyli: 1.3
    // Jeśli chcemy płynną muzykę to wystarczy zmienić ten współczynnik na 1
    int pauzaMiedzyNutami = dlugoscNuty * 1.3;
    delay(pauzaMiedzyNutami);
    // Wyłączenie buzera - dla zasady bo i tak podajemy czas trwania każdej nuty
    noTone(buzzer);
  }  
// Przerwa pomiędzy kolejnymi powtórzeniami piosenki
delay(3000);
}
