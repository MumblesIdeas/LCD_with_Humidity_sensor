/*
 * Juan Segundo
 * 01/11/2023
 * Button, DHT, RTC, and LCD1602 code
 *
 //////////Sources///////////
 * https://www.hackster.io/ThothLoki/portable-arduino-temp-humidity-sensor-with-lcd-a750f4
 * https://components101.com/displays/16x2-lcd-pinout-datasheet
 * https://arduinointro.com/projects/make-interactive-arduino-projects-using-pushbutton-and-lcd
 * https://roboticsbackend.com/arduino-push-button-tutorial/
 * https://www.instructables.com/How-to-use-a-Push-Button-Arduino-Tutorial/
 * https://www.programmingelectronics.com/tutorial-17-using-a-button-old-version/
 * https://arduinogetstarted.com/tutorials/arduino-button
 * https://startingelectronics.org/beginners/arduino-tutorial-for-beginners/use-a-push-button-switch-with-arduino/
 * https://www.electronicshub.org/arduino-real-time-clock-tutorial/
 * https://www.instructables.com/1602-LCD-Contrast-Control-From-Arduino/
 * https://rastating.github.io/toggling-the-backlight-of-hd44780-lcds-with-an-arduino-uno/
 * https://projecthub.arduino.cc/ejshea/91bc36de-b825-4ed6-80cf-307586fd9bd6
 *   
 *   
 *   
 *   https://forum.arduino.cc/t/button-press-to-change-lcd-screen/278543/16
*/
#include <Adafruit_I2CDevice.h>
#include <Wire.h> // This is the Wire library
#include <RTClib.h>
#include <LiquidCrystal.h>
#include <DHT.h>
// #define LED_PIN 1 // Not sure what LED_PIN is used for...
// #define BUTTON_PIN 5
#define DHT11_PIN 8 // This is the pin we are connected to the S pin on the DHT ... that sends informatôn to the Arduino. 
// Apparently the line above are constants.


RTC_DS1307 rtc;// This needs the #include "RTClib.h" ... library to execute
dht DHT; // Creats a DHT object

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); /* These are the pins on the arduino
// Creates an LCD object.
// Parameters: (rs, enable, d4, d5, d6, d7)
// The d# stands for the pinout on the LCD.
// In this case, d4 on the LCD is connected to pin 6 on the arduino... etc... */

 
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}; // Sets up the day of the week matrix. 
// Might not need the lines below
// const int buttonPin=13; //button is connected to digital pin 7
// int val=0;
// int led_num=0; // Q: Not sure what val and led_num work.

void setup() // This void setup() funtion is mandatory arduino function ... think of this as the main function that is required for C++
// The code inside †his function will be executed once only.
{
  Serial.begin(9600);
  lcd.begin(16, 2); // This specifies the dimensions of the LCD. This is a 16 column by 2 row LCD configuration
  Wire.begin();
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //HT.begin();
  //delay(setTime);
}

// Remember that we must always use void loop

void loop(){
  }
/* void loop(){ 

//humidity=HT.readHumidity();
//tempC=HT.readTemperature();
//tempF=HT.readTemperature(true); // This line inputs temperature in Celsius

//Serial.print(" Humidity: ");
//Serial.print(humidity); // Whats the difference between serial.print and lcd.print ?
//Serial.print(" Temperature C ");
//Serial.print(tempC);

  int chk = DHT.read11(DHT11_PIN); // This initializes the sensor.
  lcd.setCursor(0,0); // This sets the cursor position on the Top Left of the LCD screen
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223); // This line prints out the degree symbol. This is in ASCII
  lcd.print("C");
  lcd.setCursor(0,1); // This sets the cursors to the Bottom Left of the LCD screen
  lcd.print("Humidity: "); 
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(3000); // This is 3000 milliseconds...3 seconds.
} */
/* This code is for the RTC clock.

void setup () 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  if (! rtc.begin()) 
  {
    lcd.print("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) 
  {
    lcd.print("RTC is NOT running!");
  }
  
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//auto update from computer time
    //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));// to set the time manualy 
  
}

void loop () 
{
    DateTime now = rtc.now();
    
    lcd.setCursor(0, 1);
    lcd.print(now.hour());
    lcd.print(':');
    lcd.print(now.minute());
    lcd.print(':');
    lcd.print(now.second());
    lcd.print("   ");

    lcd.setCursor(0, 0);
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    lcd.print(" ,");
    lcd.print(now.day());
    lcd.print('/');
    lcd.print(now.month());
    lcd.print('/');
    lcd.print(now.year());
   
}

*/

/*void loop()// Another mandatory function
// The code inside this function will be executed again and again ... it's a loop...
{
  val=digitalRead(buttonPin);// This reads input pin(buttonPin) and assigns it to the variable val
  // The digitalRead(); command reads the value from a specified pin, the value can either High(1) or Low(0)
  // 
  
  
  // if(val==1){ //button is pressed
  //   led_num=led_num+1; //add 1 to the led_num variable
  //   }
    if (led_num==0){
   
    DateTime now = rtc.now();

    lcd.setCursor(0, 0);
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    lcd.print(" ,");
    lcd.print(now.month());
    lcd.print('/');
    lcd.print(now.day());
    lcd.print('/');
    lcd.print(now.year());

    lcd.setCursor(0, 1);
    lcd.print(now.hour());
    lcd.print(':');
    lcd.print(now.minute());
    lcd.print(':');
    lcd.print(now.second());
    lcd.print("   ");

    delay(1000); 
  }

  else if (led_num==2){
   lcd.clear(); // Clears the LCD.
   int chk = DHT.read11(DHT11_PIN); // This initializes the sensor DHT11 temp/humidity sensor.
   lcd.setCursor(0,0); // This sets the cursor position on the Top Left of the LCD screen
   lcd.print("Temp: ");
   lcd.print(DHT.temperature);
   lcd.print((char)223); // This line prints out the degree symbol. This is in ASCII
   lcd.print("C");
   lcd.setCursor(0,1); // This sets the cursors to the Bottom Left of the LCD screen
   lcd.print("Humidity: "); 
   lcd.print(DHT.humidity);
   lcd.print("%");
  }
  else if (led_num==3){
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print(" Mode 3 ");

    //reset the led_num variable to 0
    led_num=0;

  }
  //wait 300 ms for the next reading
  delay(300); 
}

*/

/*
 * Issues/Problems
 * A - There is a nested if funtion. Not sure if this is the right thing to do.
 * B - For the time function ... when time is in single digits; it only diplays one number. Ex: 09:05 am is displayed as 9:5 am. It's really akward.
*/
