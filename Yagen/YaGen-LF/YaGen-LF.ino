#include<Cytron_SmartDriveDuo.h>
#define IN1 3 // Arduino pin 4 is connected to MDDS30 pin IN1.
#define AN1 5 // Arduino pin 5 is connected to MDDS30 pin AN1.
#define AN2 6 // Arduino pin 6 is connected to MDDS30 pin AN2.
#define IN2 7 // Arduino pin 7 is connected to MDDS30 pin IN2.
int speedL,speedR;
#define lf0 A0 
#define lf1 A1 
#define lf2 A2 
#define lf3 A3 
#define lf4 A4
#define lf5 A5
int error;
#define L 650
int sensor[] = {0,0,0,0,0,0}; 
Cytron_SmartDriveDuo md(PWM_INDEPENDENT, IN1, IN2, AN1, AN2);

void setup()
{
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(AN1,OUTPUT);
  pinMode(AN2,OUTPUT);

  pinMode(lf0,INPUT);
  pinMode(lf1,INPUT);
  pinMode(lf2,INPUT);
  pinMode(lf3,INPUT);
  pinMode(lf4,INPUT);
  pinMode(lf5,INPUT);

  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  irInput();
  irDisp();
  pid();  
  Serial.println(error);
}

void irInput()
{
  sensor[0] = analogRead(lf0);
  sensor[1] = analogRead(lf1);
  sensor[2] = analogRead(lf2);
  sensor[3] = analogRead(lf3);
  sensor[4] = analogRead(lf4);
  sensor[5] = analogRead(lf5);
}
void pid()
{ 
  if(sensor[1]>L){
    error = -3;
    l(error);
  }
  else if(sensor[1]>L && sensor[2]>L){
    error = -2;
    l(error);
  }
  else if(sensor[1]>L && sensor[2]>L){
    error = -1;
    l(error);
  }
  else if(sensor[2]>L && sensor[3]>L){
    error = 0;
    f();
  }
  else if(sensor[3]>L){
    error = 1;
    r(error);
  }
  else if(sensor[3]>L && sensor[4]>L){
    error = 2;
    r(error);
  }
  else if(sensor[4]>L){
    error = 3;
    r(error);
  }
  else {
    s();
  }  
}


void f(){
  digitalWrite(13,HIGH);
  speedL = 10;
  speedR = 10;
  md.control(speedL,speedR);
}
void r(int e){
  digitalWrite(13,HIGH);
  speedL = 10*e;
  speedR = 0;
  md.control(speedL,speedR);
}
void l(int e){
  digitalWrite(13,HIGH);
  speedL = 0;
  speedR = -10*e;
  md.control(speedL,speedR);
}
void s()
{
  digitalWrite(13,HIGH);
  speedL = 0;
  speedR = 0;
  md.control(speedL,speedR);   
}
void irDisp()
{
  for(int i = 0; i<6; i++)
  {
    Serial.print(sensor[i]);
    Serial.print(",");
  }
  Serial.println(" ");
  delay(1000);
}  
