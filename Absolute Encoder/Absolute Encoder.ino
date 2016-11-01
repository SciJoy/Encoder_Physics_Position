/*  
Building an Absolute Encoder
http://youtu.be/j8rG3bjqriI - Encoder Basics
https://youtu.be/LjY1PSd8w2E -How to Build and Encoder
https://youtu.be/CM0GePGEtrs -How to Program the Encoder
This code is for an absolute encoder. It reads the state of three break beam, 
compares the three readings, and outputs the location of the encoder.
To learn more, visit www.scijoy.community.
Released under the Creative Commons Attribution 4.0 license.
October 18, 2016
 */

const int sensorPins[]={5,6,7};  //An array of the the defined digital input pins. 5 is inner and 7 is outer.
int states[] = {0,0,0};  //An array that stores the current state of each sensor

void setup() {

//This for loop initilizes the input pins and turns on internal pull-up resistors
for (int i=0; i <3; i++){
      pinMode(sensorPins[i], INPUT);
  digitalWrite(sensorPins[i], HIGH);
 }

  Serial.begin(9600);  //Start serial communicaiton

}

void loop(){

//This for loop read the states of each o the sensors and stores it in an array.
 for (int j=0; j <3; j++){
      states[j]=digitalRead(sensorPins[j]); 
 }

/*
This series of else if statements looks at the current state of each sensor.
There are 8 defined sections on this three bit encoder. Each statements is
associated with on of those 8 sections. The program prints the degree values
for the section the encoder is currently located in.
*/

if(states[0] == 0 && states[1] == 0 && states[2]==0) {  // If the inner sensor is 0 and the middle is 1 and the outer is 0,
  Serial.println("0 degrees to 45 degrees");            // then print "0 degrees to 45". If not, move on to next else if statement.
}

else if(states[0] == 0 && states[1] == 0 && states[2]==1) {
  Serial.println("45 degrees to 90 degrees");
}

else if(states[0] == 0 && states[1] == 1 && states[2]==1) {
  Serial.println("90 degrees to 135 degrees");
}

else if(states[0] == 0 && states[1] == 1 && states[2]==0) {
  Serial.println("135 degrees to 180 degrees");
}

else if(states[0] == 1 && states[1] == 1 && states[2]==0) {
  Serial.println("180 degrees to 225 degrees");
}

else if(states[0] == 1 && states[1] == 1 && states[2]==1) {
  Serial.println("225 degrees to 270 degrees");
}

else if(states[0] == 1 && states[1] == 0 && states[2]==1) {
  Serial.println("270 degrees to 315 degrees");
}

else if(states[0] == 1 && states[1] == 0 && states[2]==0) {
  Serial.println("315 degrees to 360 degrees");
}
 
}
