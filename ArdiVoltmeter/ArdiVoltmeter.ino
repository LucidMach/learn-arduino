#include "LiquidCrystal.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

float inV = 0.0;
int tempV=0.0;


void setup()
{
   Serial.begin(9600);                            
   lcd.begin(16,2);                               
   lcd.print("ArdiVoltmeter");
}

void loop()
{
   tempV= analogRead(A0);                        
   inV = (tempV*5.0) / 1024.0;           //Conversion formula for voltage 
 
    Serial.print("v= ");
    Serial.println(inV);
    lcd.setCursor(0,1);
    lcd.print("Voltage= ");
    lcd.print(inV);
    delay(300);
}
