//Reed Bethune
//Custom Song:
//Music with arduino
//Reed Bethune

//define speaker port:
int speaker = 11;
int btn = 2;
//rhythm variables

int tempo = 2000;
int w = tempo;
int h = w/2;
int q = h/2;
int e = q/2;
int s = e/2;

//define pitches for 

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
 
void setup(){
  
  //set speaker pin to output
  pinMode(speaker, OUTPUT);
  Serial.begin(9600);
  pinMode(btn, INPUT);
  
}//end setup

void loop() {
  int btnState = digitalRead(btn);
    if (btnState == 1){
      zeldaTheme();
      Serial.println(btnState);
    }//end if
  
 
}//end loop



