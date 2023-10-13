/*
CE CODE PERMET D'AFFICHER UN TEXT SUR LE MONITEUR SERIE ET DE MESURER LE TEMPS ECOULE DEPUIS LA MISE SOUS TENSION DU MODULE
*/

long n = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                  //ici on choisi une vitesse de communication serie de 9600 bps
  Serial.println("bienvenue proma!");
  delay(2000);  //faire une pause de 2sec
}

void loop() {
  // put your main code here, to run repeatedly:
  n = millis();
  n = n / 1000;
  Serial.print("elapsed time: ");  //afficher le texte sans saut de ligne
  Serial.print(n);                 //afficher la valeur de n apres les : ci-dessus
  Serial.println("sec");           //ajouter sec apres la valeur affichee
  delay(1000);
}
