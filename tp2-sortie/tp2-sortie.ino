

int led_r = 2, led_g = 3, led_y = 4, led_p = 5, b1 = 8, b2 = 9, b3 = 10;  //initialisation de tout le bronche utilisable
int n = 0, o = 0;                                                         //initialisation du compteur
void setup() {
  // put your setup code here, to run once:
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(led_y, OUTPUT);
  pinMode(led_p, OUTPUT);
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("initialisation");
  // Serial.println("initialisation");
}

void loop() {
  // put your main code here, to run repeatedly:
  while (digitalRead(b1) == LOW) {
    n = n + 1;
    delay(1000);  //Incrémenter n toutes les 250ms
    Serial.print("n = ");
    Serial.println(n);
  }

  while (digitalRead(b3) == LOW) {
    o = o + 1;
    delay(250);  //Incrémenter n toutes les 250ms
    Serial.print("o = ");
    Serial.println(o);
  }
  if (n % 2 != 0) {
    digitalWrite(led_r, HIGH);  // n=0;
    
                                // delay(6000);
  } else {
    digitalWrite(led_r, LOW);
  }
  if (digitalRead(b2) == LOW) {
    digitalWrite(led_g, HIGH);
  
    delay(3000);
    digitalWrite(led_g, LOW);
  }
  if (o > 0 && o < 4) {  //SI APPUYUI COURT ALLUMER LA LED purple
    digitalWrite(led_p, HIGH);
    Serial.println("led violet allumée 3 sec");
    delay(3000);
    digitalWrite(led_p, LOW);
    o = 0;
  } else if (o > 4) {  //SI APPUI LONG APPUYER LA LED yellow
    digitalWrite(led_y, HIGH);
    Serial.println("led jaune allumée pendant 2sec");
    delay(2000);
    digitalWrite(led_y, LOW);
    o = 0;
  }
}
