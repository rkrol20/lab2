#include<Servo.h>
 Servo serwomechanizm;
 int jasn_akt=0,poz_akt=125,jasn_zad=100, uchyb;
 float poz_teor=0,Kp=0.07;
 
void setup() {
  Serial.begin (9600);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
   pinMode(11,OUTPUT);
  serwomechanizm.attach(3);
}

void loop() {
//układ sprzężenia z regulatorem P
jasn_akt=analogRead(A0);
Serial.print("jasnosc: ");
Serial.print(jasn_akt);
uchyb=jasn_akt-jasn_zad;
Serial.print(" uchyb: ");
Serial.print(uchyb);
poz_teor=poz_teor+Kp*uchyb;
if(poz_teor>180)
  {
    poz_teor=180;
  }
  if(poz_teor<125)
  {
    poz_teor=125;
  }
Serial.print(" pozycja teoretyczna: ");
Serial.print(poz_teor);
poz_akt=poz_teor;
serwomechanizm.write(poz_akt);
Serial.print(" pozycja: ");
 Serial.println(poz_akt);

if(uchyb==0|abs(uchyb)==1)
{
  digitalWrite(12,HIGH);
}
else
{
   digitalWrite(12,LOW);
}

if(uchyb>1&&uchyb<10)
{
  digitalWrite(13,HIGH);
}
else
{
  digitalWrite(13,LOW);
}
if(uchyb>-10&&uchyb<-1)
{
  digitalWrite(11,HIGH);
}
else
{
  digitalWrite(11,LOW);
}
  delay(100);
}
