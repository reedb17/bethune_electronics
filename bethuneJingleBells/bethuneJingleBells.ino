//Music with arduino
//Reed Bethune

//define speaker port:
int speaker = 11;

//rhythm variables

int tempo = 1000;
int w = tempo;
int h = w/2;
int q = h/2;
int e = q/2;
int s = e/2;

//define pitches for C scale

int c4 = 261;
int d4 = 293;
int e4 = 330;
int f4 = 350;
int g4 = 392;
int an4 = 440;
int b4 = 494;
int c5 = 523;

 void jingleBells() {
   
   int line1And3Notes [] = {e4, e4, e4, e4, e4, e4, e4, g4, c4, d4, e4};
   int line2Notes [] = {f4, f4, f4, f4, f4, e4, e4, e4, e4, d4, d4, e4, d4, g4};
   int line4Notes [] = {f4, f4, f4, f4, f4, e4, e4, e4, e4, g4, g4, f4, d4, c4};
   
   int line1And3Rhythm [] = {q, q, h, q, q, h, q, q, q, q, w};
   int line2Rhythm [] = {q, q, q, q, q, q, q, q, q, q, q, h, h};
   int line4Rhythm [] = {q, q, q, q, q, q, q, q, q, q, q, q, w}; 
     
     //line 1
   for (int n = 0; n <= 11; n++) {
     tone(speaker, line1And3Notes[n], line1And3Rhythm[n]);
     delay(line1And3Rhythm[n]);
   }//end for loop for line 1
   
   for (int n = 0; n <= 14; n++) {
     tone(speaker, line2Notes[n], line2Rhythm[n]);
     delay(line2Rhythm[n]);
   }//end for loop for line 2
   
   for (int n = 0; n <= 11; n++) {
     tone(speaker, line1And3Notes[n], line1And3Rhythm[n]);
     delay(line1And3Rhythm[n]);
   }//end for loop for line 3
   
   for (int n = 0; n <= 14; n++) {
    tone(speaker, line4Notes[n], line4Rhythm[n]);
    delay(line4Rhythm[n]);
   }//end for loop
   

 }//end jingleBells
 
void setup(){
  
  //set speaker pin to output
  pinMode(speaker, OUTPUT);
  
}//end setup

void loop() {

}//end loop



