#include <math.h>

const int trigPort = 5;
const int echoPort = 6;
int i;
long duration;
double distance[10];
double addedTotal = 0;
double Mean;
static const double DEGREES_TO_RADIANS_CONSTANT = (M_PI/180.0);
void setup() {
 pinMode(trigPort, OUTPUT);
 pinMode(echoPort, INPUT);
 Serial.begin(9600);
}

void loop() {
  if (i < 10)
  {
digitalWrite(trigPort, LOW);
delayMicroseconds(2);
digitalWrite(trigPort, HIGH);
delayMicroseconds(10);
digitalWrite(trigPort, LOW);
duration = pulseIn(echoPort, HIGH);
distance[i] = duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance[i]);

}
i++;
  if (i == 11)
  {
    for (int i = 0; i < 10; i++)
    {
      addedTotal += distance[i];
    }
        Mean = addedTotal/10;
    Serial.print("Mean: ");
    Serial.println(Mean);
  }
}

