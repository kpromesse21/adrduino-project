/*
ce code permet de commander une lampe avec la lecture au clavier des cartere 'a' et 'e' 
  'a': pour allumer
  'e': pour etteindre
*/


int LAMP=10;//definir le pin de la lamp
char commande;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//definition de la c=vitesse d'affichage
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    commande =Serial.read();
    if(commande=='a'){
      digitalWrite(LAMP, HIGH);
      Serial.println("lamp on");
    }
    if(commande=='e'){
      digitalWrite(LAMP, LOW);
      Serial.println("lamp off");
    }
  }
}
