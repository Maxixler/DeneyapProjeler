int ledPin1=11;
int sensorPin1=10;
int sensorPin2=12;
int ledPin2=13;
boolean val1 =0;
boolean val2 =0;
void setup(){
  pinMode(ledPin1, OUTPUT);
  pinMode(sensorPin1, INPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(sensorPin2, INPUT);
  Serial.begin (9600);
}
  
void loop (){

  val1 = digitalRead(sensorPin1);
  val2 = digitalRead(sensorPin2);
  Serial.println (val1);
  Serial.println (val2);
  delay(50);
  // when the sensor detects a signal above the threshold value, LED flashes
  if (val1==HIGH && val2 == LOW) {
    digitalWrite(ledPin1, HIGH);
    delay(50);
  }
  else if(val1==LOW && val2 == HIGH){
    digitalWrite(ledPin2, HIGH);
    delay(50);
  }
  else if(val1==HIGH && val2 == HIGH){
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    delay(50);
  }
  else{
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    delay(50);
  }
}