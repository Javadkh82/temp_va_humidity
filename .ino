#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN 8
DHT dht(DHTPIN, DHTTYPE);
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



void setup() {
pinMode(DHTPIN, INPUT);
Serial.begin(9600);
dht.begin();
lcd.begin(16,2);
}

void loop() {
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();
lcd.setCursor(0,0);
lcd.print("TEMPERATURE:");
lcd.print(temp);
lcd.print("c");
lcd.setCursor(0,1);
lcd.print("Humidity:");
lcd.print(humidity);
lcd.print("%");
delay(1000);
}
