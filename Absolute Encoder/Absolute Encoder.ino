int sensorPins[]={5,6,7};
int states[] = {0,0,0};

void setup() {
 
for (int i=0; i <3; i++){
      pinMode(sensorPins[i], INPUT);
  digitalWrite(sensorPins[i], HIGH);
 }

  Serial.begin(9600);
  Serial.println("Inner, Middle, Outer");

}

void loop(){


 for (int j=0; j <3; j++){
      states[j]=digitalRead(sensorPins[j]); 
 }

/*
 for (int j=0; j <3; j++){
      sensorState[j]=digitalRead(sensorPins[j]); 
      Serial.print(sensorState[j]);
*/

if(states[0] == 0 && states[1] == 0 && states[2]==0) {
  Serial.println("0 degrees to 45 degrees");
}

else if(states[0] == 0 && states[1] == 1 && states[2]==0) {
  Serial.println("45 degrees to 90 degrees");
}

else if(states[0] == 0 && states[1] == 1 && states[2]==1) {
  Serial.println("90 degrees to 135 degrees");
}

else if(states[0] == 1 && states[1] == 1 && states[2]==1) {
  Serial.println("135 degrees to 180 degrees");
}

else if(states[0] == 1 && states[1] == 1 && states[2]==0) {
  Serial.println("180 degrees to 225 degrees");
}

else if(states[0] == 1 && states[1] == 0 && states[2]==0) {
  Serial.println("225 degrees to 270 degrees");
}

else if(states[0] == 1 && states[1] == 0 && states[2]==1) {
  Serial.println("270 degrees to 315 degrees");
}

else if(states[0] == 0 && states[1] == 0 && states[2]==1) {
  Serial.println("315 degrees to 360 degrees");
}
 

delay(100);

}
