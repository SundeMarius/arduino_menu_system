//Demo for I2C LCD2004 module by CATALEX
//Hardware: A I2C LCD2004 module
//Board: Arduino UNO R3,Arduino Mega2560...
//IDE:   Arduino-1.0
//Function: Display four lines of characters
//Store: http://www.aliexpress.com/store/1199788
//      http://dx.com
/*********************************************************************/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display
//LiquidCrystal_I2C lcd(0x3f,16,2);  //if the LCD does not work, please use the other address:0x3f

void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  lcd.setCursor(0,1);
  lcd.print("LCD for UNO");
   lcd.setCursor(0,2);
  lcd.print("CATALEX LCM IIC");
   lcd.setCursor(0,3);
  lcd.print("Design By Fred");
}

void loop()
{
}

