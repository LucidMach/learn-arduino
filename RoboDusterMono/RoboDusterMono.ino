#include<Servo.h>

int pos;
Servo f1;

void setup() 
{
  f1.attach(7);
}

void loop() 
{
for(pos=0; pos<180; pos++)
 {
  f1.write(pos);
 }
for(pos=180; pos>90; pos--)
 {
  f1.write(pos); 
 }
}
