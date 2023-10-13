
int lampe =12;
int capteur =A0;//fignal analloique du capteur
int seuil =500;
void setup() {
  // put your setup code here, to run once:
  pinMode(lampe,OUTPUT);
  Serial.begin(9600);
  Serial.println("INTERUPEUR CREPSCULAIRE");

}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(capteur);
  Serial.print("Lecture :");
  Serial.println(val);
  if(val>seuil){

  digitalWrite(lampe,HIGH);
  }else{

   digitalWrite(lampe,LOW);
  }

}
