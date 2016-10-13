int sensorPinA = 6; // define input pins for sensor (LDR, Break beam, Hall effect...).
int sensorPinB = 5;
int currentStateA = 0;  //define current state of the sensor pin. 1-Unbroken, 0-Broken.
int currentStateB = 0;
int lastStateA = 0;   //define last state change of the sensor pin.
const int stepsPerRotA = 16;   //Total number of broken-unbroken changes in one rotation.
int stepsA = 0;
float rotations = 0;            //Count of the number of rotations.


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);   // Start communication to the serial port
pinMode(sensorPinA, INPUT);   //Set the digital pin as an input
pinMode(sensorPinB, INPUT);
digitalWrite(sensorPinA, HIGH);   //Set the internal pull-up resistor to high. If you are using a pull-up resistor in circuit this isn't needed.
digitalWrite(sensorPinB, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

currentStateA = digitalRead(sensorPinA);   //Set the current state to the current value read from the digital pin
currentStateB = digitalRead(sensorPinB);
Serial.print("Current: ");
Serial.print(currentStateA);
Serial.print(", ");
Serial.println(currentStateB);

if((currentStateA == 0) && (lastStateA == 1)) {
  if(currentStateB == 0){
    stepsA = stepsA - 1;
    Serial.println("CWW1");
    }
    else{
      stepsA = stepsA + 1;
      Serial.println("CW1");
    }
}

if((currentStateA == 1) && (lastStateA == 0)) {
  if(currentStateB == 1){
    stepsA = stepsA - 1;
    Serial.println("CCW2");
    }
    else{
      stepsA = stepsA + 1;
      Serial.println("CW2");
    }
}


lastStateA = currentStateA;  //This sets the last state equal to the current state.
rotations = stepsA / stepsPerRotA;

Serial.print(stepsA);
Serial.print(", ");
Serial.println(rotations);

delay(100);


}
