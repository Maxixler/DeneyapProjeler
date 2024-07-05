#include <Deneyap_OLED.h>
OLED oled;
int light;
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(115200); // Haberleşme BaudRate'i 115200 olarak ayarlandı
  
  oled.begin(0x7A); // OLed ekrana gerekli bilgiler yazdırıldı
  oled.clearDisplay();
  oled.setTextXY(0,0);
  oled.putString("*Işık Yoğunluğu*");
  oled.setTextXY(7,0);
  oled.putString("****************");

}

void loop() {
  light = analogRead(A0);
  if(light < 100){
      oled.clearDisplay();
      oled.setTextXY(3,0);
      oled.putString("Oda Karanlik");
  }
  if(light > 100){
    oled.clearDisplay();
    oled.setTextXY(3,0);
      oled.putString("Oda Aydinlik");
  }
}
