int error,P,I,D,Kp,Ki,Kd,pid,pError,x=255;

int lf0 = A0;
int lf1 = A1;
int lf2 = A2;
int lf3 = A3;
int lf4 = A4;

int RMp=3;
int RMn=6;
int LMp=9;
int LMn=11;

int LFs[5]={0, 0, 0, 0, 0};

void setup() 
{
 pinMode(lf0,INPUT);
 pinMode(lf1,INPUT);
 pinMode(lf2,INPUT);
 pinMode(lf3,INPUT);
 pinMode(lf4,INPUT);

 pinMode(RMp,OUTPUT);
 pinMode(RMn,OUTPUT);
 pinMode(LMp,OUTPUT);
 pinMode(LMn,OUTPUT);
}

void loop() 
{
 IRin();
 errorFinder();
 PIDcurve();
 turn();
}

void IRin()
{
 LFs[0] = digitalRead(lf0);
 LFs[1] = digitalRead(lf1);
 LFs[2] = digitalRead(lf2);
 LFs[3] = digitalRead(lf3);
 LFs[4] = digitalRead(lf4);
}

void errorFinder()
{
 if((LFs[0]== 1 )&&(LFs[1]== 1 )&&(LFs[2]== 1 )&&(LFs[3]== 1)&&(LFs[4]== 0 ))
  error = 4;
 else if((LFs[0]== 1 )&&(LFs[1]== 1 )&&(LFs[2]== 1 )&&(LFs[3]==0)&&(LFs[4]== 0 )) 
  error = 3;
 else if((LFs[0]== 1 )&&(LFs[1]== 1 )&&(LFs[2]== 1 )&&(LFs[3]== 0)&&(LFs[4]== 1 )) 
  error = 2;
 else if((LFs[0]== 1 )&&(LFs[1]== 1 )&&(LFs[2]== 0 )&&(LFs[3]== 0)&&(LFs[4]== 1 )) 
  error = 1;
 else if((LFs[0]== 1 )&&(LFs[1]== 1 )&&(LFs[2]== 0 )&&(LFs[3]== 1)&&(LFs[4]== 1 )) 
  error = 0;
 else if((LFs[0]== 1 )&&(LFs[1]== 0 )&&(LFs[2]== 0 )&&(LFs[3]== 1)&&(LFs[4]== 1 )) 
  error =- 1;
 else if((LFs[0]== 1 )&&(LFs[1]== 0 )&&(LFs[2]== 1 )&&(LFS[3]== 1)&&(LFs[4]== 1 )) 
  error = -2;
 else if((LFs[0]== 0 )&&(LFs[1]== 0 )&&(LFs[2]== 1 )&&(LFs[3]== 1)&&(LFs[4]== 1 ))
  error = -3;
 else if((LFs[0]== 0 )&&(LFs[1]== 1 )&&(LFs[2]== 1 )&&(LFs[3]== 1)&&(LFs[4]== 1 )) 
  error = -4;
}

void PIDcurve()
{
 P = error;
 I = I + error;
 D = error-pError;
 pid = (Kp*P) + (Ki*I) + (Kd*D);
 pError = error;

 digitalWrite(RMp,128-pid);
 digitalWrite(RMn,0);
 digitalWrite(LMp,128+pid);
 digitalWrite(LMn,0);
}
void turn()
{
  if((LFs[0}==0) && (LFs[1]==0) && (LFs[2]==0) && (LFs[3]==0) && (LFs[4]==0))
     stp();
  else if((LFs[0}==l) && (LFs[1]==l) && (LFs[2]==0) && (LFs[3]==0) && (LFs[4]==0))
     stopright();
  else if((LFs[0}==0) && (LFs[1]==0) && (LFs[2]==0) && (LFs[3]==1) && (LFs[4]==1))
     stopleft();   
}

void stp()
{
  analogWrite(lp,0);
  analogWrite(ln,0);
  analogWrite(rp,0);
  analogWrite(rn,0);
}
void stopright()
{
 while((LFs[0]!= 1 )&&(LFs[1]!= 1 )&&(LFs[2]!= 0 )&&(LFs[3]!= 1)&&(LFs[4]!= 1 )) 
  {
   analogWrite(lp,x);
   analogWrite(ln,0);
   analogWrite(rp,0);
   analogWrite(rn,0);
  }
}
void stopleft()
{
  while((LFs[0]!= 1 )&&(LFs[1]!= 1 )&&(LFs[2]!= 0 )&&(LFs[3]!= 1)&&(LFs[4]!= 1 )) 
  {
   analogWrite(lp,0);
   analogWrite(ln,0);
   analogWrite(rp,x);
   analogWrite(rn,0);
  }
}
