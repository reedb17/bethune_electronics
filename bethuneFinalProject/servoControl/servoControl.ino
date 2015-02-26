//Reed Bethune
//Receiver code from Sparkfun.com - modified by me to function with the servos

//include servos
#include <Servo.h>

//piezo
int speaker = 8;

//pitches and tempo
int tempo = 2000;
int w = tempo;
int h = w/2;
int q = h/2;
int e = q/2;
int s = e/2;

int c4 = 261;
int d4 = 293;
int e4 = 330;
int f4 = 350;
int g4 = 392;
int an4 = 440;
int b4 = 494;
int c5 = 523;
int Db = 277;
int Eb = 311;
int Gb = 370;
int Ab = 415;
int Bb = 466;
int f5 = 698;
int g5b = 740;
int a5b = 830;
int e5b = 622;
int d5b = 554;
int d5 = 587;
int b5b = 932;
int e5 = 659;
int g5 = 784;

//zelda song function
void zeldaTheme() {
  int lineOneNotes [] = {Bb, Bb, f4, f4, Bb, Ab, Gb, Ab, Ab, Ab, Bb, Bb, Gb, Gb, Bb, an4, g4, an4, an4, an4};
  int lineOneRhythm [] = {h, e, e, e, e, s, s, h, q, e, h, e, e, e, e, s, s, h, q, e};
  
  int lineTwoNotes [] = {Bb, f4, f4, Bb, Bb, c5, d5, e5b, f5, f5, f5, f5, g5b, a5b, b5b, b5b, b5b, b5b, a5b, g5b, a5b, g5b, f5, f5};
  int lineTwoRhythm [] = {q, q, e, e, s, s, s, s, h, e, e, e, e, e, h, e, e, e, e, e, e, e, h, q};
    
  int lineThreeNotes [] = {e5b, f5, g5b, g5b, f5, e5b, d5b, e5b, g5b, g5b, e5b, d5b, c5, d5, e5, g5, f5, f4, f4, f4, f4, f4, f4, f4, f4, f4, f4, f4};
    
  for (int n = 0; n <= 19; n++){
    tone(speaker, lineOneNotes[n], lineOneRhythm[n]);
    delay(lineOneRhythm[n]);
  }//end lineOne
  
  for (int n = 0; n <= 23; n++){
   tone(speaker, lineTwoNotes[n], lineTwoRhythm[n]);
   delay(lineTwoRhythm[n]);
 }//end lineTwo
 
}//end zeldaTheme

//val to store incoming data ;
char val;

//MY CODE
//instances of servos
Servo rWheel;
Servo lWheel;

void setup(){
  
  //piezo on startup
  pinMode(speaker, OUTPUT);
  zeldaTheme();

  //set pins for LED output
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  
  //begin serial communication at 9600 Baud
  Serial.begin(9600);
  
  
  //attach the servos
  rWheel.attach(9);
  lWheel.attach(10);
  
}//end setup

void loop(){
  if (Serial.available()) {
    //if data is incoming, set it equal to val
   val = Serial.read();
  }//end if 
  
  if (val == 's'){
    rWheel.write(89);
    lWheel.write(90);
    Serial.println("s");
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
  
  if (val == 'f'){
    rWheel.write(180);
    lWheel.write(0);
    Serial.println("f");
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  
  if (val == 'b'){
    rWheel.write(0);
    lWheel.write(180);
    Serial.println("b");
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  
  if (val == 'l'){
    rWheel.write(0);
    lWheel.write(0);
    Serial.println("l");
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  
  if (val == 'r'){
    rWheel.write(180);
    lWheel.write(180);
    Serial.println("r");
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  
//END MY CODE
}//end void loop
