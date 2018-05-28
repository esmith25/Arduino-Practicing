static const int LIMIT_SWITCH_PORT = 2;
static const int LED_PORT = 3;
int whocares = 0;
void setup() {
  Serial.begin(9600);
  pinMode(LIMIT_SWITCH_PORT, INPUT);
  pinMode(LED_PORT, OUTPUT);
}

void loop() {
  whocares = digitalRead(LIMIT_SWITCH_PORT);
  digitalWrite(LED_PORT, whocares);
}
