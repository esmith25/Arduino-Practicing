#include <Wire.h>

static const int LIDAR_ADDRESS = 0x62;
static const int REGISTER_ADDRESS = 0x00;
static const int MEASURE_VALUE = 0x04;

static const int UPPER_BYTE_ADDRESS = 0x0f;
static const int LOWER_BYTE_ADDRESS = 0x10;

static const int UPPER_AND_LOWER_BYTE_ADDRESS = 0x8f;

int shiftedUpperByte = 0;
int finalValue;
int uppervalue;
int lowervalue;
int distance = 0;

int LidarRange(void)
  {
    int val = -1;
    
    Wire.beginTransmission((int)LIDAR_ADDRESS);
    Wire.write((int)REGISTER_ADDRESS);
    Wire.write((int)MEASURE_VALUE);
    Wire.endTransmission();

    delay(30);

    Wire.beginTransmission((int)LIDAR_ADDRESS);
    Wire.write((int)UPPER_AND_LOWER_BYTE_ADDRESS);
    Wire.endTransmission();

    delay(30);

    Wire.requestFrom((int)LIDAR_ADDRESS, 2);
    if(2 <= Wire.available()) 
  {
    val = Wire.read(); 
    val = val << 8; 
    val |= Wire.read(); 
  }
  
  return val;
  
    }
void setup() {
  Serial.begin(9600);
  Wire.begin();

}

void loop() {
  distance = LidarRange();
  Serial.print("Distance:");
  Serial.println(distance);

}
