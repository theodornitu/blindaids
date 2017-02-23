/*** Project name: ***/
/*** Project author:  ***/
/*** Copyright:   ***/
/*** Licence    ***/

// Average human walking speed: 5Km/h = 1.38m/s = 


// Sensor and motors pins definition
const int L_TRIG = 9;
const int L_ECHO = 8;
const int R_ECHO = 6;
const int R_TRIG = 7;
const int Mot_right_pin = A1;
const int Mot_left_pin = A2;
// End of sensor and motors pin definition


// Distance constraints
long duration, distance, RightSensor,LeftSensor;
long dist_max_left=0;
long dist_max_right=0;
float Mot_left,Mot_right;
// End of distance constraints

void setup()
{
  // Initialize the serial port to see the measured distances
  Serial.begin(115200);
  
  // Initialize the pins as input/output
  pinMode(L_TRIG, OUTPUT);
  pinMode(L_ECHO, INPUT);
  pinMode(R_TRIG, OUTPUT);
  pinMode(R_ECHO, INPUT);
  pinMode(Mot_left_pin, OUTPUT);
  pinMode(Mot_right_pin, OUTPUT);
  // End of pins initialization
  

}

void loop()
{
  
  // Left sensor distance measurement
  SonarSensor(L_TRIG, L_ECHO); 
  LeftSensor = distance;
  if(dist_max_left<LeftSensor)
    dist_max_left=LeftSensor;
  // End of left sensor distance measurement
  
  // Right sensor distance measurement
  SonarSensor(R_TRIG, R_ECHO);
  RightSensor = distance;
  if(dist_max_right<RightSensor)
    dist_max_right=RightSensor;
  // End of right sensor distance measurement
  
  // Right sensor serial printing
  Serial.print("Ditanta maxima dreapta: ");
  Serial.print(dist_max_right);
  Serial.print(" ");
  Serial.print("Distanta R: ");
  Serial.println(RightSensor);
  // End of right sensor serial printing
  
  // Right motor driving algorithm
  if(RightSensor<250&&RightSensor>150)
  {
    analogWrite(Mot_right_pin,255);
    delay(300);
    analogWrite(Mot_right_pin,0);
    delay(600);
}
  if(RightSensor<150&&RightSensor>75)
  {
    analogWrite(Mot_right_pin,255);
    delay(300);
    analogWrite(Mot_right_pin,0);
    delay(300);
  }
  if(RightSensor<75&&RightSensor>35)
  {
    analogWrite(Mot_right_pin,255);
    delay(300);
    analogWrite(Mot_right_pin,0);
    delay(100);
  }
  if(RightSensor<35)
    analogWrite(Mot_right_pin,255);
  if(RightSensor>250)
    analogWrite(Mot_right_pin,0);  
  // End of right motor driving algorithm
  
  
  // Left sensor Serial printing
  Serial.print("Ditanta maxima stanga: ");
  Serial.print(dist_max_left);
  Serial.print(" ");
  Serial.print("Distanta L: ");
  Serial.println(LeftSensor);
  // End of left sensor Serial printing

  // Left motor driving algorithm
  if(LeftSensor<250&&LeftSensor>150)
  {
    analogWrite(Mot_left_pin,255);
    delay(300);
    analogWrite(Mot_left_pin,0);
    delay(600);
}
  if(LeftSensor<150&&LeftSensor>75)
  {
    analogWrite(Mot_left_pin,255);
    delay(300);
    analogWrite(Mot_left_pin,0);
    delay(300);
  }
  if(LeftSensor<75&&LeftSensor>35)
  {
    analogWrite(Mot_left_pin,255);
    delay(300);
    analogWrite(Mot_left_pin,0);
    delay(100);
  }
  if(LeftSensor<35)
    analogWrite(Mot_left_pin,255);
  if(LeftSensor>250)
    analogWrite(Mot_left_pin,0); 
  // End of left motor driving algorithm 
    
}

  void SonarSensor(int trigPin,int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}
