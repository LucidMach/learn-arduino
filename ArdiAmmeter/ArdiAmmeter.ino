#include<LiquidCrystal.h>
LiquidCrystal lcd (7,8,9,10,11,12);
 
void setup() 
{
 Serial.begin(9600);
 lcd.begin(16,2);
 lcd.clear();
}
 
void loop() 
{
 int R=Serial.read();;
 Serial.print("Resistance Value:");
 int V0 = analogRead(A0);
 int V1 = analogRead(A1);
 int Vd =(V0-V1) ;
 float V = (Vd*5)/1024;
 float I = (V/R);
 
 Serial.print("ArdiAmmeter");
 lcd.setCursor(0,0);
 lcd.print("Current Reading=");
 lcd.setCursor(0,1);
 lcd.print(I);
 lcd.print("A");
 delay(1000);
}
