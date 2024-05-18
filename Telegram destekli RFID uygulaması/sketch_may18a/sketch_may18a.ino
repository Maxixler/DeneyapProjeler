#include <SPI.h>                  // SPI kutuphanesi tanimlandi.
#include <MFRC522.h>              // MFRC522 kutuphanesi tanimlandi.
#include <DeneyapTelegram.h>      // Telegram kutuphanesi tanimlandi.
#include <WiFiClientSecure.h>     // WiFiClientSecure kutuphanesi tanimlandi.
#include <WiFi.h>                 // Wifi kutuphanesi tanimlandi.

DeneyapTelegram telegram;         

#define BOTtoken "Bot tokeninizi buraya yapistirin" // Telegram uygulamasi üzerinden Botfather ile ogrenecegiz
#define CHAT_ID "chat id buraya yapistirilacak"     // idbot ile telegram ID'sini ogrenerek buraya yazacagiz

WiFiClientSecure client;

const char* ssid = "Wifi Adi";            // Bağlı oldugunuz Wifi Adini giriniz.
const char* password = "Wifi Sifresi";    // Bağlı oldugunuz Wifi Sifresini giriniz.

int buzzerPin=31; // Buzzerin bagli oldugu pin tanimlandi

int t=0; // okunan kart sayacı
int RST_PIN = D4; //RC522 modülü reset pini tanımlandı.
int SS_PIN = D10; //RC522 modülü chip select pini tanımlandı.

MFRC522 rfid(SS_PIN, RST_PIN); //RC522 modülü ayarları yapıldı.
byte ID[4] = {
 "sayi1","sayi2","sayi3","sayi4" // (67, 162, 166, 172) veya (121,127,254,179) kullanilabilir.
}; //Yetkili kart ID'sini tanımlıyoruz. 

void setup() {
  Serial.begin(115200); //Seri haberleşmeyi başlatıyoruz.
  SPI.begin(); //SPI iletişimini başlatıyoruz.
  rfid.PCD_Init(); //RC522 modülünü başlatıyoruz.

  pinMode(buzzerPin,OUTPUT);  // Buzzer pini cikis olarak ayarlandi.

  client.setInsecure(); // Wifi baglantilari yapiliyor.
  Serial.print("Internete baglaniyor: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi bağlandi");
  Serial.print("IP adresi: ");
  Serial.println(WiFi.localIP());
  telegram.begin(BOTtoken);
  telegram.send(CHAT_ID,"Cihaz Baglandi");

}


void loop() {

  if (!rfid.PICC_IsNewCardPresent()) //Yeni kartın okunmasını bekliyoruz.
    return;

  if (!rfid.PICC_ReadCardSerial()) //Kart okunmadığı zaman bekliyoruz.
    return;

  if (rfid.uid.uidByte[0] == ID[0] && //Okunan kart ID'si ile ID değişkenini karşılaştırıyoruz.
    rfid.uid.uidByte[1] == ID[1] &&
    rfid.uid.uidByte[2] == ID[2] &&
    rfid.uid.uidByte[3] == ID[3]) {
    tone (buzzerPin,224);  // Kart okundugunda buzzer ses cikartacak
    Serial.println("Kart Okundu");
    t+=1;
     telegram.send(CHAT_ID,"Kart okundu");  // Telegramdan "kart okundu" mesaji gonderiliyor.
  } 
  else { //Yetkisiz girişte içerideki komutlar çalıştırılır.
    Serial.println("Yetkisiz Kart");
  }
  rfid.PICC_HaltA();
}