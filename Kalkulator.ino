String odebrString=" ";
float odebrane=0,a=0,b=0,wynik;
char znak=' ';
int etap=0,czyKomunikat=0,blad=0;
void setup() {
   Serial.begin (9600);

}

void loop() {
if(etap==0)
{ 
  if(czyKomunikat==0)
  {
    Serial.println("________________\nPoczatek obliczen.\n\nPodaj pierwsza liczbe:");
    czyKomunikat=1;
  }
  if(Serial.available() > 0)
  {
    odebrString=Serial.readStringUntil('\n');
    Serial.println(odebrString);
     a=odebrString.toFloat();
     etap=1;
     czyKomunikat=0;
  }
}
if(etap==1)
{
  if(czyKomunikat==0)
  {
   Serial.println("Podaj operatora ('+','-','*','/','^'");
    czyKomunikat=1;
  }
  if(Serial.available()>0)
  {   
    odebrString=Serial.readStringUntil('\n');
    Serial.println(odebrString);
   
  znak=odebrString[0];
  etap=2;
  czyKomunikat=0;
  }
  }
 if(etap==2)
 {
  if(czyKomunikat==0)
  {
    Serial.println("Podaj druga liczbe:");
    czyKomunikat=1;
  }
  if(Serial.available() > 0)
  {
    odebrString=Serial.readStringUntil('\n');
    Serial.println(odebrString);
     b=odebrString.toFloat();
     etap=3;
     czyKomunikat=0;
  }
 }

  if(etap==3)
 {
  
    Serial.println("Wynik to:");
    
  switch(znak)
  {
    case '+':
      wynik=a+b;
      break;
     case '-':
      wynik=a-b;
      break;
     case '*':
      wynik=a*b;
      break;
     case '/':
      if(b==0)
      {
        Serial.println("Blad, dzielenie przez zero\n");
        blad=1;
        break;
      }
      wynik=a/b;
      break;
     case '^':
      wynik=pow(a,b);
      break;
     default:
      Serial.println("Blad skladni operatora\n");
        blad=1;
        break;
     
  }
  if(blad==0)
  {
    Serial.println(wynik);
  }
  blad=0;
  etap=0;
 }
}
