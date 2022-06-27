#include<LiquidCrystal.h>
#define lm35 A0
  
double temp;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(lm35,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 temp=analogRead(lm35);
 temp*=0.4882;//volt mapping(5/1024)*100
 temp-=50;//offset correction
 TempDisp();

}

void TempDisp()
{
  lcd.print("Temprature:");
  lcd.setCursor(2,1);
  lcd.print(temp);
  delay(3000);
  lcd.clear();
}
