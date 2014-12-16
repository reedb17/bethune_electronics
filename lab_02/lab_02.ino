//Reed Bethune
//LED Pattern Excercise

//Objects in Program

 int pin [] = {2, 3, 4, 5, 6, 7, 8, 9};
 
 void blinkLineFast(){
   
   for (int i = 0; i <= 8; i++){
   
   for (int i = 0; i <= 7; i++){
     digitalWrite(pin[i], HIGH);
     delay(100);
     digitalWrite(pin[i], LOW);
     delay(100);
   }//end for loop
   }//end for loop
 }//end blinkLineFast
 
 void everyOther(){
   
   for (int i = 0; i <= 8; i++){
     
     digitalWrite(pin[0], HIGH);
     digitalWrite(pin[2], HIGH);
     digitalWrite(pin[4], HIGH);
     digitalWrite(pin[6], HIGH);
     delay(500);
     digitalWrite(pin[0], LOW);
     digitalWrite(pin[2], LOW);
     digitalWrite(pin[4], LOW);
     digitalWrite(pin[6], LOW);
     digitalWrite(pin[1], HIGH);
     digitalWrite(pin[3], HIGH);
     digitalWrite(pin[5], HIGH);
     digitalWrite(pin[7], HIGH);
     delay(500);
     digitalWrite(pin[1], LOW);
     digitalWrite(pin[3], LOW);
     digitalWrite(pin[5], LOW);
     digitalWrite(pin[7], LOW);
   }//end for loop
   
 }//end everyOther

 void upAndDown(){
   
   
   for (int i = 0; i <= 8; i++){
     
   for (int i = 0; i <= 7; i++){
     
      digitalWrite(pin[i], HIGH);
     delay(100);
     digitalWrite(pin[i], LOW);
     delay(100);
     
   }// end for loop
   
     for (int i = 7; i >= 0; i--){
     
     digitalWrite(pin[i], HIGH);
     delay(100);
     digitalWrite(pin[i], LOW);
     delay(100);
     
   }// end for loop
   
   }//end loop
 }//end upAndDown
 
 void allOn(){
   
   for (int i = 0; i <= 7; i++){
     digitalWrite(pin[i], HIGH);
     
   }//end for loop
   
 }//end allOn

//setup
void setup(){
  for ( int i = 0; i <= 7; i++){
    pinMode(pin[i], OUTPUT);
  }//end for loop
}//end setuppind

//loop
void loop() {
  blinkLineFast();
  everyOther();
  upAndDown();
}//end loop
