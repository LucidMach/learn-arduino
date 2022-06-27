int error, P, I=0, D, Kp, Ki, Kd, pid, pError=0, x = 255;

int lf0 = 2; 
int lf1 = 4; 
int lf2 = 7; 
int lf3 = 12; 
int lf4 = 13;  

int RMp = 3; 
int RMn = 6; 
int LMp = 9; 
int LMn = 11;  

int LFs[6] = {0, 0, 0, 0, 0, 0};  


void setup() 
{   
  pinMode(lf0, INPUT);   
  pinMode(lf1, INPUT);
  pinMode(lf2, INPUT);
  pinMode(lf3, INPUT);
  pinMode(lf4, INPUT);
  
  pinMode(RMp, OUTPUT);
  pinMode(RMn, OUTPUT);
  pinMode(LMp, OUTPUT);
  pinMode(LMn, OUTPUT);
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
  if ((LFs[0] == 1 ) && (LFs[1] == 1 ) && (LFs[2] == 1 ) && (LFs[3] == 1) && (LFs[4] == 0 ))
   error = 4;   
  else if ((LFs[0] == 1 ) && (LFs[1] == 1 ) && (LFs[2] == 1 ) && (LFs[3] == 0) && (LFs[4] == 0 ))
   error = 3;   
  else if ((LFs[0] == 1 ) && (LFs[1] == 1 ) && (LFs[2] == 1 ) && (LFs[3] == 0) && (LFs[4] == 1 ))
   error = 2;
  else if ((LFs[0] == 1 ) && (LFs[1] == 1 ) && (LFs[2] == 0 ) && (LFs[3] == 0) && (LFs[4] == 1 )) 
   error = 1;
  else if ((LFs[0] == 1 ) && (LFs[1] == 1 ) && (LFs[2] == 0 ) && (LFs[3] == 1) && (LFs[4] == 1 ))   
   error = 0;   
  else if ((LFs[0] == 1 ) && (LFs[1] == 0 ) && (LFs[2] == 0 ) && (LFs[3] == 1) && (LFs[4] == 1 ))
   error = - 1;  
  else if ((LFs[0] == 1 ) && (LFs[1] == 0 ) && (LFs[2] == 1 ) && (LFs[3] == 1) && (LFs[4] == 1 ))  
   error = -2;
  else if ((LFs[0] == 0 ) && (LFs[1] == 0 ) && (LFs[2] == 1 ) && (LFs[3] == 1) && (LFs[4] == 1 )) 
   error = -3;   
  else if ((LFs[0] == 0 ) && (LFs[1] == 1 ) && (LFs[2] == 1 ) && (LFs[3] == 1) && (LFs[4] == 1 ))  
   error = -4; 
}

void PIDcurve()
{
  P = error;
  I = I + error;
  D = error - pError;   
  Kp = 10;
  Ki = 0;
  Kp = 2; 
  pError = error;    

  pid = (Kp * P) + (Ki * I) + (Kd * D); //max= Kp*4 + Kd*(4-(-4)) = 128 ==> Kp+Kd*2=32
                                        // ReTune Expression if too turny i.e change previous error to 3 or 2
  digitalWrite(RMp, 128 - pid);
  digitalWrite(RMn, 0);

  digitalWrite(LMp, 0);
  digitalWrite(128 + pid, 0);
} 
void turn() 
{
  if ((LFs[0] == 1) && (LFs[1] == 0) && (LFs[2] == 0) && (LFs[3] == 0) && (LFs[4] == 0))
   stp();
  else if ((LFs[0] == 1) && (LFs[1] == 1) && (LFs[2] == 0) && (LFs[3] == 0) && (LFs[4] == 0))  
   stopright();  
  else if ((LFs[0] == 0) && (LFs[1] == 0) && (LFs[2] == 0) && (LFs[3] == 1) && (LFs[4] == 1))   
   stopleft(); 
}
void stp()
{
  analogWrite(LMp, 0);  
  analogWrite(LMn, 0); 
  analogWrite(RMp, 0);
  analogWrite(RMn, 0); 
}
void stopright()
{
  while ((LFs[0] != 1 ) && (LFs[1] != 1 ) && (LFs[2] != 0 ) && (LFs[3] != 1) && (LFs[4] != 1 ))   
  {
    analogWrite(LMp, x);
    analogWrite(LMn, 0);
    analogWrite(RMp, 0);
    analogWrite(RMn, 0); 
  }
}
void stopleft() 
{
  while ((LFs[0] != 1 ) && (LFs[1] != 1 ) && (LFs[2] != 0 ) && (LFs[3] != 1) && (LFs[4] != 1 ))
  {
    analogWrite(LMp, 0); 
    analogWrite(LMn, 0);
    analogWrite(RMp, x);
    analogWrite(RMn, 0); 
  }
} 
