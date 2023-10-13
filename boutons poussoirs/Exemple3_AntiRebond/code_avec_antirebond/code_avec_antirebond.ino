/*
Avec ce code, on allume la led en appuyant sur bp et pour l'eteindre il faut un nouvel appui. 
ICI ON DEFINIE UNE FONCTION SPECIALE QUI PERMET D'EVITER LES EFFETS DE REBONDS!!
*/
int switchPin = 9;
int ledPin = 6;
boolean lastButton = LOW; 

/* on va enregistrer l'etat du bp lors de la boucle précédente 
 *  dans la variable lastButton.
 */
/*
 * cette dernière est initialement mis à l'état bas (c'est une variable
 * booleen qui ne peut pendre que 2 états)
 */ 
boolean currentButton = LOW;
boolean ledOn = false; 
// l'état en cours de led est enrégistré dans la variable ledOn qui est initialement mise à 0
void setup()
{
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}
boolean debounce(boolean last,int BP)
/* Fonction pour eviter les effets de rebond. 
 *  cette function retourne une valeur booléen et ainsi elle definie comme booléen
 *  dans cette fonction, l'argument en entrée est la valeur last et la broche ou est connecte le BP
  */
{
  boolean current = digitalRead(BP); //pour déterminer la valeur actuelle du bp
  if (last != current)
  {
    delay(5); 
    /*si l'etat actuelle du bp est different de l'etat precedent, 
     * on temporise 5ms juste assez pour memoriser l'etat du bp avant la secession de l'appui
     */
    current = digitalRead(BP);
    // A ce moment on suppose que la valeur lue ne correspond plus au bonds
  }
  return current;
}
void loop()
{
  currentButton = debounce (lastButton,switchPin);
  if (lastButton == LOW && currentButton == HIGH) 
  // pour detecter le passage de l'ouverture à la fermeture du bp
  {
    ledOn = !ledOn; 
    //on met à jour cette variable car la led change d'etat
   }
  lastButton = currentButton;  
  digitalWrite(ledPin, ledOn);

}



