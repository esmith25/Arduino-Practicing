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

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  }


void ConfigureLidar()
{
  Wire.beginTransmission((int)LIDAR_ADDRESS);
    Wire.write((int)REGISTER_ADDRESS);
    Wire.write((int)MEASURE_VALUE);
    Wire.endTransmission();
  }

int GET_LIDAR_UPPER_BYTE()
{
  int val = -1;
  Wire.beginTransmission((int)LIDAR_ADDRESS);
  Wire.write((int)UPPER_BYTE_ADDRESS);
  Wire.endTransmission();
  Wire.requestFrom((int)UPPER_BYTE_ADDRESS, 1);
  if(2 <= Wire.available()) 
  {
    val = Wire.read(); 
    val = val << 8; 
    val |= Wire.read(); 
  }
  return val;
  }
int GET_LIDAR_LOWER_BYTE()
{
  int val = -1;
  Wire.beginTransmission((int)LIDAR_ADDRESS);
  Wire.write((int)LOWER_BYTE_ADDRESS);
  Wire.endTransmission();
  Wire.requestFrom((int)LOWER_BYTE_ADDRESS, 1);
  if(2 <= Wire.available()) 
  {
    val = Wire.read(); 
    val = val << 8; 
    val |= Wire.read(); 
  }
  return val;
  
  }

int GetLidarValue(int lowerByte, int upperByte)
{
  lowerByte = GET_LIDAR_LOWER_BYTE();
  upperByte = GET_LIDAR_UPPER_BYTE();
  shiftedUpperByte = upperByte << 8;
  finalValue = (shiftedUpperByte + lowerByte);
  return finalValue;
  }




  /*int LidarRange(void)
  {
    int val = -1;
    
    Wire.beginTransmission((int)LIDAR_ADDRESS);
    Wire.write((int)RegisterMeasure);
    Wire.write((int)MeasureValue);
    Wire.endTransmission();

    delay(30);

    Wire.beginTransmission((int)LIDAR_ADDRESS);
    Wire.write((int)HighAndLowByte);
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
 */
void loop()
{


 uppervalue = GET_LIDAR_UPPER_BYTE();
  lowervalue = GET_LIDAR_LOWER_BYTE();
  distance = GetLidarValue(uppervalue, lowervalue);
  
  Serial.print("Distance:");
  Serial.println(distance);
  }
