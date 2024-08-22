//Interface the DHT11 Temp & Humidity sensor and display humidity and temperature
//in Farenheit on a 16x2 character LCD

#include <dht.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <DS3231.h>


DS3231 clock;
RTCDateTime dt;

int DHT11_PIN = 8;

dht DHT;
// const int RS = 2, EN = 3, D4 = 4, D5 = 5, D6 = 6, D7 = 7;

// LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
// These are the pins on the arduino
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  // Arduino Uno has one serial port
  lcd.begin(16,2);    //set 16 columns and 2 rows for the 16x2 LCD
}

void loop() {
  float readDHT = DHT.read11(DHT11_PIN);    //grab 40-bit data packet from DHT sensor
  // the above DHT.read11 reads info from arduino pin 13
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print((DHT.temperature * 9.00) / 5.00 + 32.00);
  //lcd.print((char)223);         //used to display degree symbol on display
  lcd.write(0xdf);              //another way to display degree symbol
  lcd.print("F");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(3000);
}
