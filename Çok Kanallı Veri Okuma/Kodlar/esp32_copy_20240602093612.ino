#include "BluetoothSerial.h"
#include "I2S.h"
#define SAMPLE_RATE 10000
const int bufferSize = 100000;
BluetoothSerial SerialBT;
const int potPin1 = 12; 
const int potPin2 = 13;
int potValue1 = 0;
int potValue2 = 0;
void setup()
{
Serial.begin(115200);
  SerialBT.begin("DeneyapKart Test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}
void loop()
{
  if((Serial.available())||(SerialBT.available()))
   potValue1 = analogRead(potPin1);
 potValue2 = analogRead(potPin2);
 SerialBT.print("1: ");
 SerialBT.println(potValue1);
 SerialBT.print("2: ");
 SerialBT.println(potValue2);
}
