//Limit Switch code using an LED light to test to see if it is working
static const int LIMIT_SWITCH_INPUT = 0;
static const int LIMIT_SWITCH_OUTPUT = 3;

void setup() {
  Serial.begin(9600);
 // pinMode(LIMIT_SWITCH_INPUT, INPUT);
  analogRead(LIMIT_SWITCH_INPUT);
}

void loop() {
/*if(digitalRead(LIMIT_SWITCH_INPUT) == HIGH)
{
digitalWrite(LIMIT_SWITCH_OUTPUT, HIGH);
  }
else
{
  digitalWrite(LIMIT_SWITCH_OUTPUT, LOW);

  }
  */
  
}
