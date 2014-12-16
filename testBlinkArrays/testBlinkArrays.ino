// Classwork: LED array asessment
//Reed Bethune
//All work here is honestly obtained and is my own.

//Objects in Program

 int pin [] = {2, 3, 4, 5, 6, 7, 8, 9};
 
 void blinkLine(){
   
   for (int i = 0; i <= 7; i++){
     digitalWrite(pin[i], HIGH);
     delay(1000);
     digitalWrite(pin[i], LOW);
     delay(1000);
   }//end for loop
   
 }//end blink


//setup
void setup(){
  for ( int i = 0; i <= 7; i++){
    pinMode(pin[i], OUTPUT);
  }//end for loop
}//end setuppind

//loop
void loop() {
  blinkLine();
}//end loop
