#include <Cytron_SmartDriveDuo.h>

#define IN1 3 // Arduino pin 4 is connected to MDDS30 pin IN1.
#define AN1 5 // Arduino pin 5 is connected to MDDS30 pin AN1.
#define AN2 6 // Arduino pin 6 is connected to MDDS30 pin AN2.
#define IN2 7 // Arduino pin 7 is connected to MDDS30 pin IN2.
Cytron_SmartDriveDuo smartDriveDuo30(PWM_INDEPENDENT, IN1, IN2, AN1, AN2);

signed int speedL, speedR;
//IR ARRAY
#define I0 A0
#define I1 A1
#define I2 A2
#define I3 A3
#define I4 A4
#define I5 A5

#define L 650


void setup()
{ 
  pinMode (I0, INPUT);
  pinMode (I1, INPUT);
  pinMode (I2, INPUT);
  pinMode (I3, INPUT);
  pinMode (I4, INPUT);
  pinMode (I5, INPUT);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(AN1,OUTPUT);
  pinMode(AN2,OUTPUT);


  pinMode(13, OUTPUT);
  Serial.begin(9600);

  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
}

void loop()
{  
   int S0 = analogRead(I0);
   int S1 = analogRead(I1);
   int S2 = analogRead(I2);
   int S3 = analogRead(I3);
   int S4 = analogRead(I4);
   int S5 = analogRead(I5);

  while(S2 > L && S3 > L)
  {
   Serial.print(S2);
   Serial.print("-");
   Serial.println(S3);
   f();
  }
  while(S3 > L)
  {
   Serial.println(S3);
   r();
  }
  while(S2 > L)
  {
   Serial.println(S2);
   l();
  }
  smartDriveDuo30.control(speedL, speedR); 
 }

void f(){
  digitalWrite(13,HIGH);
  speedL = 10;
  speedR = 10;
}
void r(){
  digitalWrite(13,HIGH);
  speedL = 10;
  speedR = 0;
}
void l(){
  digitalWrite(13,HIGH);
  speedL = 0;
  speedR = 10;
}
void b(){
  digitalWrite(13,HIGH);
  speedL = -10;
  speedR = -10;
}
void s()
{
  digitalWrite(13,HIGH);
  speedL = 0;
  speedR = 0;
}
