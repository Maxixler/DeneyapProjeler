byte pin[] = {D2, D3, D4, D5, D6, D7, D8, D9}; // Deneyapkart pin dizisi

int number[9][8] = { // Sayı dizisi
  {1, 1, 0, 0, 0, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 0, 1, 0}, // 2
  {1, 0, 0, 0, 0, 0, 1, 0}, // 3
  {1, 1, 0, 0, 0, 1, 0, 0}, // 4
  {1, 0, 0, 0, 1, 0, 0, 0}, // 5
  {0, 0, 0, 0, 1, 0, 0, 0}, // 6
  {1, 1, 0, 0, 0, 0, 0, 1}, // 7
  {0, 0, 0, 0, 0, 0, 0, 0}, // 8
  {1, 1, 0, 0, 0, 0, 0, 0}, // 9
};

void setup() {
  for (byte a = 0; a < 8; a++) {
    pinMode(pin[a], OUTPUT); // Çıkış pinlerini tanımla
  }
}

void loop() {
  for (int a = 0; a < 9; a++) { // 0'dan 9'a kadar olan sayılar için döngü
    for (int b = 0; b < 8; b++) { // Her sayı için 8 segmenti kontrol et
      digitalWrite(pin[b], number[a][b]); // Segmentleri uygun şekilde yak
    }
    delay(500); // 500 milisaniye bekle
  }
}
