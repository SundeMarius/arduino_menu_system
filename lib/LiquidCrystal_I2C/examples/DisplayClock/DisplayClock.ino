/***********************************************************/
//Demo for the I2C LCD Shield by Catalex
//Hardware: I2C LCD Shield *1, DS1307 RTC *1 (http://www.dx.com/p/316101)
//Board:  Arduino UNO R3 or Arduino Mega2560 R3
//IDE:	 Arduino-1.0
//Function:  Get the time from the RTC and display on the I2C LCD Shield.
//Store:    http://www.dx.com/
/***************************************************************/
//* RTC module attached to I2C bus as follows:
//**[RTC] - [I2C LCD Shield]
//**SCL    - SCL
//**SDA    - SDA
//**VCC    - 5V
//**GND    - GND
/**********************************************************/

#include <TimerOne.h>
#include <Wire.h>
#include "DS1307.h"
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x38,16,2);//I2C address of the I2C LCD Shield is 0x38
//LiquidCrystal_I2C lcd(0x20,16,2);  //if the LCD does not work, please use the other address:0x20
DS1307 clock;//define a object of DS1307 object

#define TOUCH_KEY1 5//Touch key1 is connected to D5 on the shield
#define TOUCH_KEY2 2//Touch key2 is connected to D2 on the shield

#define ON 1
#define OFF 0
unsigned char ClockPoint;
unsigned char Update = ON;
unsigned char Backlight = ON;
unsigned char halfsecond = 0;

void setup() {
  clock.begin();
  clock.fillByYMD(2015,4,29);//Apr 29,2015
  clock.fillByHMS(17,28,30);//15:28 30"
  clock.fillDayOfWeek(WED);//Wednesday,The first three letters
  clock.setTime();//write time to the RTC chip
  lcd.init();	 // initialize the lcd 
  lcd.backlight();//turn on the backlight
  
  pinMode(TOUCH_KEY1, INPUT);
  
  Timer1.initialize(500000);//timing for 500ms
  Timer1.attachInterrupt(TimingISR);//declare the interrupt serve routine:TimingISR 
  
}

void loop() {

  if(Update == ON)
  {
    DataUpdate();
  }
  if(digitalRead(TOUCH_KEY1)){//If you touch key1 on the touch area
    ControlBacklight();
	delay(200);//to avoid duplication trigger
  }
}

void TimingISR()
{
  halfsecond++;
  if(halfsecond == 2)
  {
    Update = ON;
	halfsecond = 0;
  }
  
  if(ClockPoint ==ON) ClockPoint = OFF;
  else ClockPoint = ON;  
}


void DataUpdate()
{
  clock.getTime();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(clock.hour, DEC);
  lcd.print(":");
  lcd.print(clock.minute, DEC);
  lcd.print(":");
  lcd.print(clock.second, DEC);
  lcd.setCursor(0, 1);
  lcd.print(clock.month, DEC);
  lcd.print("/");
  lcd.print(clock.dayOfMonth, DEC);
  lcd.print("/");
  lcd.print(clock.year+2000, DEC);
  Update = OFF;
}
void ControlBacklight()
{
  if(Backlight) Backlight = OFF;
  else Backlight = ON;
  if(Backlight) lcd.backlight();
  else lcd.noBacklight();
}