
//Reed Bethune
//Code Below is by Makematics for their FingerTracking project - NOT MINE
//Modified with my own code and code form Sparkfun.com

// import the fingertracker library
// and the SimpleOpenNI library for Kinect access
import fingertracker.*;
import SimpleOpenNI.*;

// declare FignerTracker and SimpleOpenNI objects
FingerTracker fingers;
SimpleOpenNI kinect;
// set a default threshold distance:
// 625 corresponds to about 2-3 feet from the Kinect
int threshold = 625;

//serial communications
import processing.serial.*;
Serial myPort;


//MY CODE
//declare font
PFont f;
// END MY CODE

void setup() {
  size(640, 480);
  
  //MY CODE
  f = createFont("Arial",32,true);
  //END MY CODE
  
  //set port for communication with arduino
  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 9600);
  
  
  // initialize your SimpleOpenNI object
  // and set it up to access the depth image
  kinect = new SimpleOpenNI(this);
  kinect.enableDepth();
  // mirror the depth image so that it is more natural
  kinect.setMirror(true);

  // initialize the FingerTracker object
  // with the height and width of the Kinect
  // depth image
  fingers = new FingerTracker(this, 640, 480);
  // the "melt factor" smooths out the contour
  // making the finger tracking more robust
  // especially at short distances
  // farther away you may want a lower number
  fingers.setMeltFactor(100);
}

void draw() {
  
  //MY CODE
  //declare font and numFin for use in if statements
  textFont(f,16);

  // END MY CODE
  
  
  // get new depth data from the kinect
  kinect.update();
  // get a depth image and display it
  PImage depthImage = kinect.depthImage();
  image(depthImage, 0, 0);
  
  //MY CODE
  //AR onscreen buttons
  fill(0, 255, 0, 100);
  rect(0, 320, 160, 160, 200);
  fill(255, 0, 0, 100);
  rect(160, 320, 160, 160, 200);
  fill(200, 200, 0, 100);
  rect(320, 320, 160, 160, 200);
  fill(0, 0, 240, 100);
  rect(480, 320, 160, 160, 200);
  //END MY CODE

  // update the depth threshold beyond which
  // we'll look for fingers
  fingers.setThreshold(threshold);
  
  // access the "depth map" from the Kinect
  // this is an array of ints with the full-resolution
  // depth data (i.e. 500-2047 instead of 0-255)
  // pass that data to our FingerTracker
  int[] depthMap = kinect.depthMap();
  fingers.update(depthMap);

  // iterate over all the contours found
  // and display each of them with a green line
  stroke(0,255,0);
  for (int k = 0; k < fingers.getNumContours(); k++) {
    fingers.drawContour(k);
  }
  
  // iterate over all the fingers found
  // and draw them as a red circle
  noStroke();
  fill(255,0,0);
  for (int i = 0; i < fingers.getNumFingers(); i++) {
    PVector position = fingers.getFinger(i);
    ellipse(position.x - 5, position.y -5, 20, 20);
    
    
    //MY CODE
    
    //button boolean structure
    
    
    
    if (position.y > 320){
      
      if (position.x > 0) {
        if (position.x < 160) {
          fill(0, 255, 0);
          text("FORWARD", 300, 100);
          myPort.write('f');
        } //end if
      }//End if
      
      if (position.x > 160){
        if (position.x < 320) {
          fill(255, 0, 0);
          text("BACKWARD", 300, 100);
          myPort.write('b');
        }//end if
      }//end if
      
      if (position.x > 320) {
        if (position.x < 480) {
          fill(200, 200, 0);
          text("LEFT", 300, 100);
          myPort.write('l');
        }//end if
      }//end if
      
      if (position.x > 480){
        if (position.x < 640) {
          fill(0, 0, 240);
          text("RIGHT", 300, 100);
          myPort.write('r');
        }//end if
      }//end if
      
    }//end if
    
    else{
      fill(100, 0, 100);
      text("STOPPED", 300, 100);
      myPort.write('s');
    }//end else
    
    fill(255, 0, 0);
    
    //END MY CODE
    
  }//end for loop
  
  

  
  
  
  // show the threshold on the screen
  fill(255,0,0);
  text(threshold, 10, 20);
  
  
}//end void DRAW

// keyPressed event:
// pressing the '-' key lowers the threshold by 10
// pressing the '+/=' key increases it by 10 
void keyPressed(){
  if(key == '-'){
    threshold -= 10;
  }
  
  if(key == '='){
    threshold += 10;
  }
  
}


