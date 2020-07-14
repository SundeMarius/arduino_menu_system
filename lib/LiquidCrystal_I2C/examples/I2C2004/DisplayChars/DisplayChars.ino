//Demo for I2C LCD1602 module, I2C LCD 2004 module by OPEN-SMART Team
//Hardware: An I2C LCD1602 module or I2C LCD 2004
//Board: OPEN-SMART UNO R3, Arduino UNO R3,Arduino Mega2560...
//IDE:   Arduino-1.6.5
//Function: Display characters
//Store: http://www.aliexpress.com/store/1199788
//      http://dx.com
/*********************************************************************/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x20,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal_I2C lcd(0x38,20,4);  //if the LCD does not work, please use the other address:0x38
//LiquidCrystal_I2C lcd(0x3f,20,4);  //if the LCD does not work, please use the other address:0x3f
//LiquidCrystal_I2C lcd(0x27,20,4);  //if the LCD does not work, please use the other address:0x27

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  displayTemp(20.5);//display 20.5 Degrees Celsius
  lcd.setCursor(0, 1);
  displayDate(2017,9,23);  //display date is 2017.09.23
  lcd.setCursor(0, 2);                    
  displayClcok(12,30);//display time 12:30
  delay(3000);
  
  displayKeyCodes();
}


void loop()
{
  
}
// display all keycodes
void displayKeyCodes(void) {
  uint8_t i = 0X20;
  while (1) {
    lcd.clear();
    lcd.print("Codes 0x"); lcd.print(i, HEX);
    lcd.print("-0x"); lcd.print(i+16, HEX);
    lcd.setCursor(0, 1);
    for (int j=0; j<16; j++) {
      lcd.write(i+j);
    }
    delay(4000);
	if(i == 0xF0)break;//the end
	else i+=16;
  }
}

void displayTemp(float temp)
{
  lcd.print("Temp is ");
  lcd.print(temp,1);
  lcd.print("C");
}

void displayDate(uint16_t year, uint8_t month, uint8_t dayOfMonth)
{
  lcd.print("Date is ");
  lcd.print(year, DEC);
  lcd.print(".");
  if(month < 10)lcd.print("0");
  lcd.print(month, DEC);
  lcd.print(".");
  if(dayOfMonth < 10)lcd.print("0");  
  lcd.print(dayOfMonth, DEC);
}

void displayClcok(uint8_t hour, uint8_t minute)
{
  lcd.print("Time is ");
  lcd.print(hour, DEC);
  lcd.print(":");
  lcd.print(minute, DEC);
}

/*********************************************************************************************************
The end of file
*********************************************************************************************************/
