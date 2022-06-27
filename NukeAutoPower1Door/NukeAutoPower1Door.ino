int iri,iro,cnti=0,cnto=0,cnt=-1,a=0,b=0,irp=7,orp=8;;
void setup() 
{
Serial.begin(9600);
pinMode(irp,INPUT);
pinMode(orp,INPUT);
pinMode(13,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
digitalWrite(2,HIGH);//irvcc
digitalWrite(3,LOW);//irgnd
digitalWrite(4,HIGH);//irvcc
}

void loop() 
{
iri=digitalRead(irp);
iro=digitalRead(orp);

peopleCount();
  
Serial.println(cnt);
if(cnt>0)
  digitalWrite(13,HIGH);   
else 
  digitalWrite(13,LOW); 

}

void peopleCount()
{
 
  if(iri==HIGH && a==0)
  {
   cnti++;
   if(cnti>cnto)
    {
     cnt++;
    } 
   else
    {
     cnt--;  
    } 
   a=7;
  
   
  }
  if(iri==LOW && a==7)
   a=0;   

     
  if(iro==HIGH && b==0)
  {
   cnto++;
   /*if(cnto>cnti)
    {
     cnt--;
    }
   else
    {
      cnt++; 
    }*/
   b=5;
  }
  if(iro==LOW && b==5)
   b=0; 
}
