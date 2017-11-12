//This project only works with the wired diagram in the wiring folder for sonar wired through a breadboard.

const int TRIG_PORT = 5; //The port for the trig on the sonar. The trig is the "sender". It sends the sound
const int ECHO_PORT = 6; // The port for the echo on the sonar. The echoi is the "reciever". It gets the pulse which we convert to distance
long duration; //32 bit value for our pulseIn
double distance; //Double value for our distance
//static const double DEGREES_TO_RADIANS_CONSTANT = (M_PI/180.0);

void setup() {
 pinMode(TRIG_PORT, OUTPUT); // Sets the trigPort as the output
 pinMode(ECHO_PORT, INPUT); // Sets the echoPort as the input
 Serial.begin(9600); //Connects to the Arduino
}
void loop() {
 
digitalWrite(TRIG_PORT, LOW); //Gets the low byte of the trig port
delayMicroseconds(2); //Delays for 2 Microseconds
digitalWrite(TRIG_PORT, HIGH); //Gets the high byte of the trig port
delayMicroseconds(10); //Delays for 10 Microseconds
digitalWrite(TRIG_PORT, LOW); // Gets the low byte of the trig port
duration = pulseIn(ECHO_PORT, HIGH); // Sends the pulse  from the echoPort as the High Byte
distance = duration*0.034/2; //Convertion formula to Centimeters
Serial.print("Distance: "); //Displays the word "Distance"
Serial.println(distance); //Displays the distance we want
//Done on Arduino Side



//Communicating to RoboRIO 
/*if (Serial.available() > 0)
{
  String msg = Serial.readString();
  if (msg == "Requesting Sonar")
  {
    Serial.print(distance);
    }
  }
}
