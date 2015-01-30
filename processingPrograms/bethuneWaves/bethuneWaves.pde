/* Waveshape
Gives a waveshape visual rendering of the selected Werkstatt pin output
Code adapted from previous work of Sofian Audry
Written by Chris David Howe
Adapted for Multiple Views by Christopher Michaud / www.nebomusic.net
Moog Music Inc. 2014 */
 
//import required libraries
import processing.serial.*;
import cc.arduino.*;
Arduino arduino;//initialize the Arduino class and name it

WaveDrawer eg;
WaveDrawer lfo;
WaveDrawer vcf;
WaveDrawer vco;

int pin = 0;//define the analog input pin 
//intialize public variables
int val;      
int[] values;
float zoom;
int offset;

void keyPressed() {

   if (key == CODED) {

     if (keyCode == UP) {
      zoom = zoom+1f;}
      
   if (keyCode == DOWN) {
      zoom = zoom-1f;
        }
      
   if (keyCode == LEFT) {
      noLoop();}
      
   if (keyCode == RIGHT) {
      loop();}
          
  }
    
  }


void setup() 
{
  size(800,600);  //set dimensions of window 
  eg = new WaveDrawer();
  lfo = new WaveDrawer();
  vcf = new WaveDrawer();
  vco = new WaveDrawer();
  
  arduino = new Arduino(this, Arduino.list()[1], 57600);   //initialize arduino
  zoom = 2.0f;  //set initial zoom amount here
  smooth();
}

void draw()//Draw waveshape
{
  background(0);  //background color in RGB
  eg.setVal(arduino.analogRead(pin));  //get the value from the Werkstatt 
  lfo.setVal(arduino.analogRead(1));
  vcf.setVal(arduino.analogRead(2));
  vco.setVal(arduino.analogRead(3));

  // EG
  text("Potentiometer", 20, 25);
  eg.drawWave(100, 255, 255, 2, 100, 10);  //run drawWave function (r, g, b, thickness of line)

  // LFO
  text("Glide Sensor", 20, 125);
  lfo.drawWave(255, 100, 255, 2, 200, 10);
  
  // VCF
  text("Light Sensor", 20, 225);
  vcf.drawWave(255, 255, 100, 2, 300, 10);
  
  // VCO
  text("Flex Sensor", 20, 325);
  vco.drawWave(100, 100, 255, 2, 400, 10);
  
  keyPressed();


}

public class WaveDrawer {
  //intialize public variables
  int val;      
  int[] values;
  float zoom;
  int offset;
  float VCOout = 1023.0;
  
  public WaveDrawer() {
    values = new int[width];
    zoom = 2.0f;
  }
  
  void setVal(int v) {
    val = v;
    if (val != -1) {
      pushValue(val);
    }
  }
  
  void drawWave(int r, int g, int b, int weight, int y, int amp) {
  
  stroke(r, g, b);
  strokeWeight(weight);  
  
   if (zoom <= 1f){
          zoom = 1f;}
          
  int displayWidth = (int) (width / zoom);
  
  int k = values.length - displayWidth;
  
  int x0 = 0;
  int y0 = getY(values[k], y, amp);
  for (int i=1; i<displayWidth; i++) {
    k++;
    int x1 = (int) (i * (width-1) / (displayWidth-1));
    int y1 = getY(values[k], y, amp);
    line( x0, y0, x1, y1);
    x0 = x1;
    y0 = y1;
  }
}



int getY(int val, int y, int amp) {
  return (int)(y - val/amp / VCOout * (height - 1));
}

    public void pushValue(int value) {
          
    for (int i=0; i<width-1; i++){
      
      values[i] = values[i+1];
      values[width-1] = value;
    
    }
  
  
}

}

