/*
*CE CODE PERMET DE FAIRE ================UN CONTROLLE DE NIVEAU D'UN RESERVOIR ET DE TEMPERATURE==============================
* @COMME CAPTEUR NOUS UTILISONS LE CAPTEUR ULTRASONIC POUR LE NIVEAUX
* @POUR LA TEMPERATURE NOUS UTILISERONS LE LM325
*
*/


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x20
#define BACKLIGHT_PIN 3
#define EN_PIN 2
#define RW_PIN 1
#define RS_PIN 0
#define D4_PIN 4
#define D5_PIN 5
#define D6_PIN 6
#define D7_PIN 7

LiquidCrystal_I2C lcd(I2C_ADDR, EN_PIN, RW_PIN, RS_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);//DECLARATIONDE DES PINS POUR LE LCD

const int TRIG_PIN = 4, ECHO_PIN = 3, BUZZER = 5, RELAY = 13, LM35 = A3;

float output_lm35;
const float HEITH_TANK = 250.0;
bool is_full = false;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  lcd.begin(20, 4);
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home();
  lcd.print("cotrolleur de niveaux");
}

void loop() {
  long DELAY, distance;
  //VERIFICATION DES ETATS
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  DELAY = pulseIn(ECHO_PIN, HIGH);
  output_lm35 = analogRead(LM35);
  distance = (DELAY / 2) / 29.1; // Conversion du delais de reponse en distance
  float vout = output_lm35 * 5.0 / 1023 * 1000;
  float temperature = vout / 10;
  float water_level;

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  if (temperature > 80) {
    digitalWrite(BUZZER, HIGH);
    delay(1000);
    digitalWrite(BUZZER, LOW);
  }

  if (distance >= HEITH_TANK) {
    water_level = 100;
  } else {
    water_level = (distance * 100) / HEITH_TANK;
  }

  lcd.setCursor(0, 2);
  lcd.print("Rempl: ");
  lcd.print(water_level);
  lcd.print(" %");
  Serial.print("Rempli: ");
  Serial.print(water_level);
  Serial.println(" %");

  if (water_level < 50 || !is_full) {
    pompage_eau(water_level);
  } else {
    digitalWrite(RELAY, LOW);
    lcd.setCursor(0, 3);
    lcd.print("Reservoir plein");
  }
}

void pompage_eau(float LEVEL) {
  digitalWrite(RELAY, HIGH);
  while (LEVEL < 98) {
    LEVEL++;
    lcd.setCursor(0, 2);
    lcd.print("Rempl: ");
    lcd.print(LEVEL);
    lcd.print(" %");
    lcd.setCursor(0, 3);
    lcd.print("Remplissage");

    if (LEVEL >= 98) {
      is_full = true;
      lcd.setCursor(0, 3);
      lcd.print("Reservoir plein");
      digitalWrite(RELAY, LOW);
      break;
    }
  }
}
