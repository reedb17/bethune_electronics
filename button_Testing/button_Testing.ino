int btn = 2;

void setup(){
  Serial.begin(9600);
  pinMode(btn, INPUT);
}




void loop() {
 int btnState = digitalRead(btn);
  Serial.println(btnState);
 delay(100); 
}
