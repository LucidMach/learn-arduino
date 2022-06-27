int iri,iro,cnt=0,a=0,b=0,irp=7,orp=8;;
void setup() 
{
pinMode(irp,INPUT);
pinMode(orp,INPUT);
pinMode(13,OUTPUT);
}

void loop() 
{
iri=digitalRead(irp);
iro=digitalRead(orp);

while(iri==HIGH)
 {a+=a;  }
if(a>0)
 {cnt+=1;} 

while(iro==HIGH)
 {b+=b;  }
if(b>0)
 {cnt-=1;}

if(cnt>0)
 {digitalWrite(13,HIGH); }  

}
