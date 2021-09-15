#include "DHT.h"
#include <LiquidCrystal.h>
LiquidCrystal LCD = {9,8,7,6,5,4};
const int DHTPIN = 3;
const int DHTTYPE = DHT11;
int fan =11;
int Led = 12;
int Buzzer = 13;

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();
  LCD.begin(16,2);
  pinMode(Buzzer,OUTPUT);
  pinMode(fan,OUTPUT);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  //Cau 1a. In ra LCD
  LCD.setCursor(0,0);
  LCD.println("Nhiet do = ");
  LCD.print(t);
  LCD.setCursor(0,1);
  LCD.println("Do am = ");
  LCD.print(h);
  delay(100);

  //Cau 1b: do am < 90 thi bat quat
  if(h >=90){
    digitalWrite(fan,1);
    delay(2);
  }

  //Cau 1c: Nhiet do <24 bat den
  if(t < 24){
    digitalWrite(Led,1);
    delay(500);
  }
  else{
    digitalWrite(Led,0);
    delay(500);
  }
  //Cau 1d: Nhiet do >40 bat coi
  if(t > 40){
    tone(Buzzer,50);
    delay(2);
  }
}
