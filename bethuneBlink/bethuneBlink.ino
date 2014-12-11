//Reed Bethune
//LED excercise 1

void blink(){
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(1000);
}//end blink


void setup() {
  pinMode(9, OUTPUT);
}//end setup

void loop() {
  blink();
}//end loop
