int P=150;



int lp=5;
int ln=3;
int rp=6;
int rn=11;
int ir,irr,irl;
int a=0;
int cnt=0;
unsigned long startms;
unsigned long currentms;
unsigned long deadline=2000;
int U;
int A;
int S;
int trigPin=4;
int echoPin=2;
int Sus;
int T;

void setup() 
{
 
 pinMode(lp, OUTPUT);
 pinMode(ln, OUTPUT);
 pinMode(rp, OUTPUT);
 pinMode(rn, OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(7, INPUT);  // right
 pinMode(8, INPUT);
 pinMode(9, INPUT);  // left
 Serial.begin(9600);
 startms=millis();
 
}
void loop() 
{
 forward(); 
 currentms=millis(); 
 
 ir=digitalRead(8);
 irr=digitalRead(7);
 irl=digitalRead(9);
 if(irr==HIGH)
   stopright();
 if(irl==HIGH)
   stopleft();  
 
 if(startms-currentms<=deadline)
 {
  if(ir==HIGH && a==0)
   {
    cnt++;
    a=7;
   }
  if(ir==LOW && a==7)
     a=0;
 }

 speedcalc();
 plusUltra();
 if(Sus>=S)
  stp(); 
}

void speedcalc()
{
  U=(cnt/10)*9; // no of rev=cnt/100 * wheel perimeter=18cm(2*pi(3)*radius(3)  whole divided by 2
  A= U/2;
  S= -(U*U)/(2*A);
}

void plusUltra()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  T = pulseIn(echoPin, HIGH);
  Sus = (T/2) / 29.1; 
}
void forward()
{
 analogWrite(lp,P);
 analogWrite(ln,0);
 analogWrite(rp,P);
 analogWrite(rn,0);
}

void rev()
{
 analogWrite(lp,0);
 analogWrite(ln,P);
 analogWrite(rp,0);
 analogWrite(rn,P);
 

}
void left()
{
 analogWrite(lp,0);
 analogWrite(ln,P);
 analogWrite(rp,P);
 analogWrite(rn,0);
} 
void right()
{
 analogWrite(lp,P);
 analogWrite(ln,0);
 analogWrite(rp,0);
 analogWrite(rn,P);
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
  analogWrite(lp,P);
  analogWrite(ln,0);
  analogWrite(rp,0);
  analogWrite(rn,0);
}

void stopleft()
{
  analogWrite(lp,0);
  analogWrite(ln,0);
  analogWrite(rp,P);
  analogWrite(rn,0);
}
