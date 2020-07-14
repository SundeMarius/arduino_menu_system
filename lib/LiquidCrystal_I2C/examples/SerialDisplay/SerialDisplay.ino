//Demo for I2C LCD1602 module by CATALEX
//Hardware: A I2C LCD1602 module
//Board: Arduino UNO R3,Arduino Mega2560...
//IDE:   Arduino-1.0
//Function: When the characters arrive over the serial port, it will be displayed on the LCD.
//Store: http://www.aliexpress.com/store/1199788
//      http://dx.com
/*********************************************************************/

 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//If you use the I2C LCD Shield by catalex, you should change 0x27 to 0x38 or 0x20
LiquidCrystal_I2C lcd(0x20,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display
//LiquidCrystal_I2C lcd(0x38,16,2);  //if the LCD does not work, please use the other address:0x38


void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
}

void loop()
{
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }
}
