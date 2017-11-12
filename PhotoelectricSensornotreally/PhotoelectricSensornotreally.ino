const int SENSOR_PORT = 3;
const int LED_PIN = 4;
boolean state1 = LOW;
void setup() {
  Serial.begin(9600);
pinMode(SENSOR_PORT,INPUT);
pinMode(LED_PIN,OUTPUT);
}

void loop() {
  state1 = digitalRead(SENSOR_PORT);
if (state1 == HIGH)
{
  digitalWrite(SENSOR_PORT, HIGH);
  }
else {
    digitalWrite(SENSOR_PORT, LOW);  
}
Serial.print("Soem: ");
Serial.println();
}
