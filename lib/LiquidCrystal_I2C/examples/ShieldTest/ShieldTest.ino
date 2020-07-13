/***********************************************************/
//Demo for the I2C LCD Shield by Catalex
//Hardware: I2C LCD Shield *1
//Board:  Arduino UNO R3 or Arduino Mega2560 R3
//IDE:	 Arduino-1.0
//Function:  Display "Hello, world!" on the I2C LCD Shield 
//      and the two touch keyes can control it.
//Store:    http://www.dx.com/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x38,16,2);//I2C address of the I2C LCD Shield is 0x38
//LiquidCrystal_I2C lcd(0x20,16,2);  //if the LCD does not work, please use the other address:0x20
#define TOUCH_KEY1 5//Touch key1 is connected to D5 on the shield
#define TOUCH_KEY2 2//Touch key2 is connected to D2 on the shield

#define ON 1
#define OFF 0
unsigned char Backlight = ON;
unsigned char Display = ON;

void setup() {

  lcd.init();	 // initialize the lcd 
  lcd.backlight();//turn on the backlight
  
  pinMode(TOUCH_KEY1, INPUT);
  pinMode(TOUCH_KEY2, INPUT);
  lcd.print("Hello, world!");
  
}

void loop() {

  if(digitalRead(TOUCH_KEY1)){//If you touch key1 on the touch area
    ControlBacklight();//every time you touch key1, the backlight will be on or off 
	delay(200);//to avoid duplication trigger
  }
  if(digitalRead(TOUCH_KEY2)){//If you touch key2 on the touch area
    ControlDisplay();//every time you touch key2, the characters will be display or not 
	delay(200);//to avoid duplication trigger
  }
}

void ControlBacklight()
{
  if(Backlight) Backlight = OFF;
  else Backlight = ON;
  if(Backlight) lcd.backlight();
  else lcd.noBacklight();
}
void ControlDisplay()
{
  if(Display) Display= OFF;
  else Display = ON;
  if(Display) lcd.display();
  else lcd.noDisplay();
}