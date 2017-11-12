//This includes the "Adafruit_NeoPixel" library that you can download in the folder or at https://github.com/adafruit/Adafruit_NeoPixel and click download from that site

int LED_PIN = 2;



void setup() {
Serial.begin(9600);

}

void loop() {
  
pinMode(LED_PIN, HIGH);
delay(500);
pinMode(LED_PIN, LOW);
delay(500);
}
