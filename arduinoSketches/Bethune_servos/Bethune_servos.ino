// Reed Bethune
// Servo Excercise

// Bring in servo
#include <Servo.h>

// create instance of Servo
Servo servoA;
Servo servoB;

//setup
void setup() {
  //attach servo to Pin 9
  Serial.begin(9600);
  
  servoA.attach(9);
  servoB.attach(10);
  
  //servoA spins clockwise for 2 secs
  servoA.write(0);
  delay(2000);
  
  servoA.write(90);
  delay(1000);
  
  //servoB spins clockwise for 2 secs
  servoB.write(0);
  delay(2000);
  
  servoB.write(90);
  delay(1000);
  
  //servoA and servoB spin counterclockwise for 4 secs
  servoA.write(180);
  delay(4000);
  servoB.write(180);
  delay(4000);
  
  servoA.write(90);
  delay(1000);
  servoB.write(90);
  delay(1000);
  
  //servoA and servoB spin clockwise for 3 secs
  servoA.write(0);
  delay(3000);
  servoB.write(0);
  delay(3000);
  
  servoA.write(90);
  delay(1000);
  servoB.write(90);
  delay(1000);
  
  //servoA spins counterclockwise for 1 sec
  servoA.write(180);
  delay(1000);
  
  servoA.write(90);
  delay(1000);
  
 
  //servoB spins counterclockwise for 1 sec
  servoB.write(180);
  delay(1000);
  
  servoB.write(90);
  delay(1000);
  
}//end setup


void loop() {
  if (analogRead(0) > 550 ){
    servoA.write(0);
    servoB.write(180);
    
  }
  
  if (analogRead(0) < 550 ) {
    servoA.write(90);
    servoB.write(90);
    
    
  }
  
}//end loop
