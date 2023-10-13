

int l1 = 2, l2 = 3, l3 = 4;  //declararion des bronche des lampes connectées
int bp = 8;                  // déclaration de la bronche du BP
int capteur = A0;            //fignal analloique du capteur
// int seuil=500;
int n = 0;  //compteur init
void setup() {
  // put your setup code here, to run once:
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);

  // pinMode(l1,OUTPUT);
  pinMode(bp, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("initialisation du programme");
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(capteur);
  Serial.print("mesure:");
  Serial.println(val);
  if (val > 400) {
    digitalWrite(l1, HIGH);
  }
  if (val > 600) {
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
  }
  if (val > 800) {
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l3, HIGH);
  }
  if (val < 400) {
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);
  }
  if(digitalRead(bp) == LOW){
    Serial.println("NB:appuiyez jusqu'a 4 pour un apuis long");
  }
  while (digitalRead(bp) == LOW) {
    n++;
    // Serial.println("NB:appuiyez jusqu'a 4 pour un apuis long");
    Serial.print("n =");
    Serial.println(n);
    delay(250);
  }
  if (n > 0 && n < 4) {
    digitalWrite(l2, HIGH);
    Serial.println("lampe 2 allumage pendant 1sec");
    delay(1000);
    digitalWrite(l2, LOW);
  } else if (n >= 4) {
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l3, HIGH);
    Serial.println("allumage toute les lampes pendant 1sec");
    delay(1000);
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);
  }
  n=0;
}
