#include <Servo.h>

Servo first;  // create servo object to control a servo
Servo second;
Servo third;
Servo fourth;
void setup() {
  Serial.begin(9600);
  first.attach(10);  // attaches the servo on to the servo objects
  second.attach(11);
  third.attach(12);
  fourth.attach(13);
  contractWings();
  pinMode(9,INPUT_PULLUP); 
  Serial.println("starting");
 }

void loop() {
  int val = digitalRead(9);
  //Serial.println(val);
  if (val==HIGH){
  
    //Default it is high, so if I get a HIGH input from the esp32, i should set the wings to 90 degrees
    contractWings();
    
  }
  else{
    // If its a low reading, I should open up the wings
    expandWings();
    
  }

}
void contractWings(){
  //The initial set is where each feather is at the 90 degreee angel, so set each one as such
  Serial.println("Contracting Wings");
  first.write(90);
  delay(15);
  second.write(90);
  delay(15);
  third.write(90);
  delay(15);
  fourth.write(90);
  delay(15);
}
void expandWings(){
  //The open set is where each expands 30 degrees to left/right incremently
  Serial.println("expanding Wings");
  first.write(60);
  delay(15);
  second.write(120);
  delay(15);
  third.write(30);
  delay(15);
  fourth.write(150);
  delay(15);
  
}
