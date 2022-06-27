int s1,s2,duration,n=128;
int irr, irl;
int s;
int lp=5, ln=3, rp=6, rn=11;

void setup() 
{
 Serial.begin(9600);
 pinMode(3, OUTPUT); 
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(4, OUTPUT);//trigger
 pinMode(2, INPUT);//echo
 pinMode(7, INPUT); //left
 pinMode(9, INPUT); //right
 
}

void loop() 
{
  alligner(); 
  
  s1=Ultra(); 
  delay(90);
  s2=Ultra();
  Serial.println(s2);
  speedcontrol();
  speedGradient();  
}
int Ultra()
{
 digitalWrite(4, LOW);
 delayMicroseconds(2);
 digitalWrite(4, HIGH);
 delayMicroseconds(10);
 digitalWrite(4, LOW);
 
 duration = pulseIn(2, HIGH);
 s=duration*0.034/2;
 return s; 
}
void speedcontrol()
{
 if(s2>=s1+10)
  {
    n=n-50;
    forward(n);
  }
 else
   {
     n=n+50;
     forward(n);
   }
}

void alligner()
{
irr=digitalRead(9);
irl=digitalRead(7);
if(irr==HIGH)
   stopleft();
if(irl==HIGH)
   stopright();        
}

void forward(int p)
{
 analogWrite(lp,p);
 analogWrite(ln,0);
 analogWrite(rp,p);
 analogWrite(rn,0);
}


void stopright()
{
  analogWrite(lp,128);
  analogWrite(ln,0);
  analogWrite(rp,0);
  analogWrite(rn,0);
}

void stopleft()
{
  analogWrite(lp,0);
  analogWrite(ln,0);
  analogWrite(rp,128);
  analogWrite(rn,0);
}
void stp()
{
  analogWrite(lp,0);
  analogWrite(ln,0);
  analogWrite(rp,0);
  analogWrite(rn,0);
}

void speedGradient()
{
  if(s1>=25)
    forward(250);
  else if(s1>=20)
    forward(200);
  else if(s1>=15)
    forward(150);
  else if(s1>=10)
    forward(100);
  else if(s1>=5)
    forward(50);
  else
    stp();          
}
