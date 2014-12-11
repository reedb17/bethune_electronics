// Reed Bethune
// lab 01

//functions

void setup() {
  Serial.begin(9600); //start serial communication
//  Serial.println("Whaddup Dawg");
//  Serial.println("I'm Randy Jackson");
//  printHappy("Reed");
  function1();
  Serial.println(" ");
  function2a(120, 512);
  Serial.println(" ");
  function2b(97,32);
  Serial.println(" ");
  printGospels();
  Serial.println(" ");
  function3();
  Serial.println(" ");
  function4();
  Serial.println(" ");
  function5();
  Serial.println(" ");
  printFibo(0, 1, 0, 20);
  Serial.println(" ");
  computeArea(12, 12);
  Serial.println(" ");
//  function8();
  Serial.println(" ");
  function9();
  Serial.println(" ");
  function10();
  Serial.println(" ");
}//end setup

void loop(){
  
}//end loop

void printHappy(String name){
  String result = "Happy Birhtday " + name;
  Serial.println(result);
}//end printHappy

float computeArea(float wid, float len){
  float area = wid * len;
  Serial.println(area);
    return area;
}//end 

void function1(){
  
  Serial.println("I am an Arduino and I communicate at");
  Serial.println("9600 Baud rate. Ports 0 and 1 are used");
  Serial.println("for serial communication.");
  Serial.println(" ");
  Serial.println("Serial communication works  well for debugging");
  Serial.println("and monitoring sensor values during the");
  Serial.println("execution of a program.");
}//end function1

float function2a(float x, float y){
  
  float answer = (x/2) * y;
  
  Serial.println(answer);
    return answer;
  
}//end function2a

float function2b(float x, float y){
  
  float answer = (2*x) + x*y;
  
  Serial.println(answer);
    return answer;
  
}//end function2b
  

void printGospels(){
  
  //array
  String gospels [] = {"Matthew", "Mark", "Luke", "John"};
  
  Serial.println("The Gospels are: ");
  
  for (int i = 0; i < 4; i++){
    
    Serial.println(gospels[i]);
    
  }//end for loop
  
}//end printGospels

void function3(){
  
  String character [] = {"C3PO", "R2D2", "Luke Skywalker", "Han Solo", "Doctor Who"};
  
  Serial.println("My favorite movie characters are:");
  
  for (int i = 0; i < 5; i++){
    
    Serial.println(character[i]);
    
  }//end for loop
}//end function3

void function4(){
  
  int nums [] = {1,2,3,4,5,6,7,8};
  
  for (int i = 0; i < 8; i++){
    Serial.println(nums[i]);
  }//end for loop
  
  for (int i = 7; i >= 0; i--){
    Serial.println(nums[i]);
  }//end for loop
  
  for (int i = 1; i <= 7; i += 2){
    Serial.println(nums[i]);
  }//end for loop
  
  for (int i = 0; i <= 6; i += 2){
    Serial.println(nums[i]);
  }//end for loop
  
  for (int i = 6; i >= 0; i -= 2){
    Serial.println(nums[i]);
  }//end for loop
  
  for (int i = 7; i >= 1; i -= 2){
    Serial.println(nums[i]);
  }//end for loop
  
}//end function4

void function5(){
  
  String scale [] = {"C", "D", "E", "F", "G", "A", "B", "C"};
  
  for (int i = 0; i <= 7; i++){
    Serial.println(scale[i]);
  }//end for loop
  
    for (int i = 7; i >= 0; i--){
    Serial.println(scale[i]);
  }//end for loop
  
  
}//end function5

void printFibo(long prev, long cur, long fibo, int n){

 for (int i = 0; i <= n; i++){
   
   fibo = prev + cur;
   prev = cur;
   cur = fibo;
   Serial.println(fibo);
   
 }//end for loop
}//end printFibo


 //wild numbers 
 void function8(){
   for (int i = 0; i < 100000; i++){
     Serial.println(i*10);
   }//end for loop
 }//end function8
 
 //a. I think this function to explode really fast and the first number be 10, then 100, and then 1000, and etcetera
 //b. The function lists numbers in a pattern similar to that which I had expressed, only I cannot determine the relationship between numbers
 //the function eventually becomes negative, and I think this is a result of violation the datatype of int
 //c. I can change the result by changing i's datatype, to maybe a float or a long
 
 float function9(){
   
   long answer = 0;
   
   for (int i = 0; i < 1000; i++){
     
     if ((i%3 == 0) || (i%5 == 0)) {
       answer+=i;
     }//end if
     
   }//end for loop
   
   Serial.println(answer);
     return answer;
   
 }//end function9
 
  void function10(){
    
    String wordSet1 [] = {"Squids ", "Bears ", "Giraffes ", "Monkeys ", "Meerkats "};
    String wordSet2 [] = {"eat ", "kick ", "explode ", "paint ", "code "};
    String wordSet3 [] = {"waffles ", "pancakes ", "arduino ", "chairs ", "fruit "};
    String wordSet4 [] = {"on ", "in ", "around ", "near ", "under "};
    String wordSet5 [] = {"stages.", "tables.", "cages.", "computers.", "glaciers."};
    
    randomSeed(1);
    
    Serial.println(wordSet1[int(random(4))] + wordSet2[int(random(4))] + wordSet3[int(random(4))] + wordSet4[int(random(4))] + wordSet5[int(random(4))]);
    
  }//end function10
    
