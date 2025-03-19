#include<Wire.h>
#include<SPI.h>
#include<SD.h>
#include<Adafruit_MPU6050.h>
#include<Adafruit_BMP085.h>

// objects
Adafruit_BMP085 bmp;
Adafruit_MPU6050 mpu;
File rocketData;

// pins
const int chipSelect = 10;
const int statePin = 4;
const int MOS = 5;

// data
float a_x=0,a_y=0, a_z=0; // m/s^2
float Apg = 0; // m
float curAlt = 0; // m
float launchThreshold = 10; // m
float paraThreshold = 6;
bool para = false;
bool launched = false;

void setup() {
    Serial.begin(9600);

    if(!SD.begin()){
    Serial.println("SD not working");
  }

  
  rocketData = sd.open("data.txt", FILE_WRITE);

    if(!bmp.begin()){
      Serial.println("Could not find BMP");
    }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  pinMode(statePin, OUTPUT);
  pinMode(MOS, OUTPUT);

  delay(1000);
}

void loop() {
  curAlt = bmp.readAltitude();
  sensors_event_t a, temp;
  mpu.getEvent(&a, &temp);

  if(rocketData) {
      rocketData.print("Alti: ");
      rocketData.print(curAlt);
      rocketData.print("m\n");

      rocketData.print("Acce: ");
      rocketData.print(a.acceleration.x);
      rocketData.print(" ");
      rocketData.print(a.acceleration.y);
      rocketData.print(" ");
      rocketData.print(a.acceleration.z);
      rocketData.print(" ");

      rocketData.print("Temp: ");
      rocketData.print(temp.temperature);
      rocketData.print("deg C\n\n");
  }
  else {
    Serial.println("SD not working";)
  }

  // para
  if (curAlt > launchThreshold) {
    launched = true;
  }

  if(launched) {
    if(((curAlt+paraThreshold)<Apg) && (para==false)){
      digitalWrite(MOS, HIGH);
      delay(6000);
      digitalWrite(MOS, LOW);
      para=true;
    }

    if(para==true){
      digitalWrite(statePin, HIGH);
      delay(500);
      digitalWrite(statePin, LOW);
      delay(500);
  }

    if(curAlt<30){
      rocketData.close();
    }
  }

  
}
