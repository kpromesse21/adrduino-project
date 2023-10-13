int BP =3;
int LED_rouge = 4;
int LED_verte =5;
int n =0;
void setup() {
  // put your setup code here, to run once:
pinMode(BP, INPUT_PULLUP);
pinMode(LED_rouge, OUTPUT);
pinMode(LED_verte,OUTPUT);
Serial.begin(9600);
Serial.println("Initialisation...");
Serial.println(" NB: led rouge s'allume pendant 4sec d'appuis");
delay(500);
}

void loop() {
  
  while(digitalRead(BP)==LOW){
    n =n+1;
    delay(250);//Incrémenter n toutes les 250ms
    Serial.print("n = ");
    Serial.println(n);
  }
  if(n>0 && n<4){ //SI APPUYUI COURT ALLUMER LA LED1
    digitalWrite(LED_rouge,HIGH);
    delay(2000);
    digitalWrite(LED_rouge,LOW);
    n = 0;
  }
  else if (n>=4){ //SI APPUI LONG APPUYER LA LED2
    digitalWrite(LED_verte,HIGH);
    delay(2000);
    digitalWrite(LED_verte,LOW);
    n = 0;
  }
}
