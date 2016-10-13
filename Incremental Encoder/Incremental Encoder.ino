int sensorPin = 5; // define input pin for sensor (LDR, Break beam, Hall effect...).
int currentState = 0;  //define current state of the sensor pin. 1-Unbroken, 0-Broken.
int lastState = 0;   //define last state change of the sensor pin.
int steps = 0;      // The number of steps the encoder has rotated. A step is a 1 or a zero.
const int stepsPerRot = 12;   //Total number of broken-unbroken changes in one rotation.
int rotations = 0;            //Count of the number of rotations.



void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);   // Start communication to the serial port
pinMode(sensorPin, INPUT);   //Set the digital pin as an input
digitalWrite(sensorPin, HIGH);   //Set the internal pull-up resistor to high. If you are using a pull-up resistor in circuit this isn't needed.
}

void loop() {
  // put your main code here, to run repeatedly:

currentState = digitalRead(sensorPin);   //Set the current state to the current value read from the digital pin

/*
 * This If statement compares the current state of the sensor pin that was just read to the last state that
 * was read from the sensor. If these states are the same, then the encoder is probably on the same step.
 * If the state has changed between readings, then the encoder has transistioned to the next state. Inside the
 * If statement, it adds 1 to the steps variable which is keeping track of the number of state changes there 
 * has been. This is the section that is incrementing forward as the encoder turns.
 */
if (currentState != lastState) { 
steps = steps + 1;
}

lastState = currentState;  //This sets the last state equal to the current state.

/*
 * This If statement keeps track of the number of steps the encoder has turned. If steps is greater than the
 * total number of steps in one rotation of the encoder, then the rotations variable is increminted by one.
 * The steps variable is also reset to zero.
 */

if (steps > stepsPerRot) {
  rotations = rotations + 1;
  steps = 0;
}


Serial.print(steps);
Serial.print(", ");
Serial.println(rotations);

//delay(10);


}
