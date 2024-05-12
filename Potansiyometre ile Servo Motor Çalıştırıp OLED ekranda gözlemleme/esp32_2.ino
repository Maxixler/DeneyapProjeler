#include <Deneyap_Servo.h>
#include <Deneyap_OLED.h>
#include <HCSR04.h>
Servo myservo;  

int servoPin = D1;  //Pin atamaları yapıldı
const int potpin = A0;
int pot_deger= 0; 
int val;
OLED oled;
void setup() {
Serial.begin(115200); // Haberleşme BaudRate'i 115200 olarak ayarlandı
 
  oled.begin(0x7A); // OLed ekrana gerekli bilgiler yazdırıldı
  oled.clearDisplay();
  oled.setTextXY(0,0);
  oled.putString("*Motor Derecesi*");
  oled.setTextXY(7,0);
  oled.putString("****************");
  pinMode(A0, INPUT);
  myservo.attach(servoPin);   //Servo ataması yapıldı

}
 
void loop() {

  pot_deger = analogRead(potpin); // Potansiyometre Değeri okundu
  val = map(pot_deger,0,1023,0,180);
   myservo.write(val/4);  // Potansiyometreden alınan değer servoya gönderildi
   oled.setTextXY(3,0);
      oled.putString("Derece = ");
      oled.setTextXY(3,9);
      oled.putFloat(val/4);   // Servonun açı değeri OLed ekrana gönderildi
    delay(200); 
}