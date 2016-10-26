/*  
Building a Quadrature Encoder
http://youtu.be/j8rG3bjqriI - Encoder Basics
https://youtu.be/LjY1PSd8w2E - How to Build the Encoder
http://youtu.be/ -How to Code the Encoder
This code is for a quadrature encoder. It reads the state of a break beam, 
compares it to the previous state, and increments the number of state changes
that occur. When the number of state changes reaches a defined threshold,
the number of rotations is incremented.
To learn more, visit www.scijoy.community.
Released under the Creative Commons Attribution 4.0 license.
October 18, 2016
 */

const int sensorPinA = 6; // Define input pins for sensor (LDR, Break beam, Hall effect...). Lower track.
const int sensorPinB = 5; //Upper track.
const int stepsPerRotA = 16;   //Total number of broken-unbroken changes in one rotation.
int currentStateA = 0;  //Define current state of track A. 1-Unbroken, 0-Broken.
int currentStateB = 0; //Define current state of track B. 1-Unbroken, 0-Broken.
int lastStateA = 0;   //Define last state of track A.
int stepsA = 0;  //Number of steps counted on track A.
float rotations = 0; //Count of the number of rotations.


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);   // Start communication to the serial port
  
//Set the digital pins as inputs
pinMode(sensorPinA, INPUT);
pinMode(sensorPinB, INPUT);

//Set the internal pull-up resistor to high. If you are using a pull-up resistor in circuit this isn't needed.
digitalWrite(sensorPinA, HIGH);  
digitalWrite(sensorPinB, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Set the current state to the current value read from the digital pin
currentStateA = digitalRead(sensorPinA);
currentStateB = digitalRead(sensorPinB);

  /*
  The If statements look for the direction of rotations and increment the step count +1 
  for clockwise and -1 counterclockwise. The first line compares the current state of the
  A track to the last read state of the A track. This means the encoder has moved to the
  next step. To determine direciton, the state of the B track is compared to either 0 or 1.
  Track A unbroken --> broken and Track B broken means it is rotating counterclockwise.
  Track A unbroken --> broken and Track B unbroken means it is rotating clockwise.
  Track A broken --> unbroken and Track B unbroken means it is rotating counterclockwise.
  Track A broken --> unbroken and Track B broken means it is rotating clockwise.
  */
  
if((currentStateA == 0) && (lastStateA == 1)) {
  if(currentStateB == 0){
    stepsA = stepsA - 1;
    Serial.println("CWW");
    }
    else{
      stepsA = stepsA + 1;
      Serial.println("CW");
    }
}

if((currentStateA == 1) && (lastStateA == 0)) {
  if(currentStateB == 1){
    stepsA = stepsA - 1;
    Serial.println("CCW");
    }
    else{
      stepsA = stepsA + 1;
      Serial.println("CW");
    }
}


lastStateA = currentStateA;  //This sets the last state equal to the current state.
rotations = stepsA / stepsPerRotA;  //The number of counted steps is divided by the number of steps in a rotation. This number can be positive (CW) or negative (CCW).

//Printing out steps and rotations. Current directions was printed out in the if statements.
Serial.print(stepsA);
Serial.print(", ");
Serial.println(rotations);

}
