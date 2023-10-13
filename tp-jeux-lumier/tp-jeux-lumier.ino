int LED_bleu=3;
int LED_jaune=5;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_bleu, OUTPUT);
  pinMode(LED_jaune, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_jaune, HIGH);
  delay(1000);
  digitalWrite(LED_jaune, LOW);
  for (int i = 0; i < 2; i++) {
    digitalWrite(3, HIGH);
    delay(500);
    digitalWrite(3, LOW);
    delay(500);
  }
}
