#include <Servo.h>
Servo f1;  
Servo f2;

int pos = 0;    
void setup() 
{
  f1.attach(3);  
  f2.attach(5);  
}

void loop() 
{
 for (pos = 0; pos <= 180; pos += 90) 
  { 
   f1.write(pos);              
   f2.write(pos);              
   delay(150);                       
   }
 for (pos = 180; pos >= 0; pos -= 90) 
  {  
   f1.write(pos);              
   f2.write(pos);              
   delay(150);                 
  }
}
