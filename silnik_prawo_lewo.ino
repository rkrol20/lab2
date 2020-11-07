
int v=0;
volatile int zezwol=0,i=0;
 void wlacz()
 {
  if(zezwol==0)
  {
    i++;
    zezwol=1;
  }
  else
  {
    zezwol=0;
  }
}
  
void setup() {
 
  Serial.begin (9600);

  pinMode(0, INPUT_PULLUP); 
  pinMode(1, INPUT_PULLUP); 
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), wlacz, RISING);
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  zezwol=0;
}
 
void loop() {

Start:

if( zezwol==0)
{
 Serial.println("Stop programu. Ilosc uruchomien:");
 Serial.println(i);
    delay(1000);
goto Start; 
}
else 
{
 Serial.println("Program działa");
}
Priorytet:
if(digitalRead(0)==LOW)
  {
    v++;
    if(v>255)
    {
      v=255;
    }
   
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    analogWrite(6,v);
    
    delay(50);
  }
 

 if(digitalRead(1)==LOW&&digitalRead(0)==HIGH)
  {
    if(digitalRead(0)==LOW)
    {
      goto Priorytet; 
    }
    v++;
    if(v>255)
    {
      v=255;
    }
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    analogWrite(6,v);
    
    delay(50);
  }

 if(digitalRead(1)==HIGH&&digitalRead(0)==HIGH)
 {
  v=0;
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
 }
}
