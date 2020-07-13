//Demo for I2C LCD1602 module, I2C LCD 2004 module by OPEN-SMART Team
//Hardware: An I2C LCD1602 module or I2C LCD 2004
//Board: OPEN-SMART UNO R3, Arduino UNO R3,Arduino Mega2560...
//IDE:   Arduino-1.6.5
//Function: Get temperature from temperture sensor and get time from DS1307 module
//              and display on I2C LCD
//Store: http://www.aliexpress.com/store/1199788
//      http://dx.com
/*********************************************************************/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DS1307.h>
#include <TimerOne.h>
#include "OS_NTC.h"

#define NTC_PIN A1 //SIG pin of NTC module connect to A1 of IO Shield, that is pin A1 of Arduino
Temperature temper(NTC_PIN); 

//LiquidCrystal_I2C lcd(0x20,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal_I2C lcd(0x38,20,4);  //if the LCD does not work, please use the other address:0x38
//LiquidCrystal_I2C lcd(0x3f,20,4);  //if the LCD does not work, please use the other address:0x3f
//LiquidCrystal_I2C lcd(0x27,20,4);  //if the LCD does not work, please use the other address:0x27

DS1307 clock;//define a object of DS1307 object

#define ON 1
#define OFF 0
unsigned char Update = ON;
unsigned char halfsecond = 0;


void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  
  initDisplay();
  
  Timer1.initialize(500000);//timing for 500ms
  Timer1.attachInterrupt(TimingISR);//declare the interrupt serve routine:TimingISR 
  
}


void loop()
{
  if(Update == ON)
  {
    DataUpdate();
  }
}
void initDisplay()
{
  lcd.setCursor(0, 0);
  lcd.print("Date is ");
  lcd.setCursor(0, 1);
  lcd.print("Time is ");
  lcd.setCursor(0, 2);
  lcd.print("Temp is ");
}

void TimingISR()
{
  halfsecond++;
  if(halfsecond == 2)
  {
    Update = ON;
	halfsecond = 0;
  }

}
void DataUpdate()
{
  clock.getTime();
  
  lcd.setCursor(8, 0);
  lcd.print(clock.year+2000, DEC);
  lcd.print(".");
  if(clock.month < 10)lcd.print("0");
  lcd.print(clock.month, DEC);
  lcd.print(".");
  if(clock.dayOfMonth < 10)lcd.print("0");  
  lcd.print(clock.dayOfMonth, DEC);

  lcd.setCursor(8, 1);
  if(clock.hour < 10)lcd.print("0");
  lcd.print(clock.hour, DEC);
  lcd.print(":");
  if(clock.minute < 10)lcd.print("0");
  lcd.print(clock.minute, DEC);
  lcd.print(":");
  if(clock.second < 10)lcd.print("0");
  lcd.print(clock.second, DEC);
  
  for(uint8_t i = 8; i < 16;i++)
  {
    lcd.print(" ");
  }
  lcd.setCursor(8, 2);
  float celsius;
  celsius = temper.getTemperature();//get temperature
  displayTemp(celsius);
  Update = OFF;
}

void displayTemp(float temp)
{
  lcd.print(temp,1);
  lcd.print("C");
}

/*********************************************************************************************************
The end of file
*********************************************************************************************************/
