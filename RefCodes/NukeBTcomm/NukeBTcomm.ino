#include<SoftwareSerial.h>
SoftwareSerial BT(0,1);//(rx,tx)
String BTin;

void setup()
{
BT.begin(9600);
Serial.begin(9600);
}

void loop() 
{
 if(BT.available())
  {
   delay(10);
   char C=BT.read();
   BTin+=C;
  }
  Serial.println(BTin);
}
