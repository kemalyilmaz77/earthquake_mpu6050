#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
 
MPU6050 ivme_sensor;
int16_t ax, ay, az;
int16_t gx, gy, gz;

int16_t kx,ky,kz;

void setup() {
Wire.begin();
pinMode(4, OUTPUT);
ivme_sensor.initialize();

}
 
void loop() {
ivme_sensor.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

int x=map(ax,-32768,32768,0,50);
int y=map(ay,-32768,32768,0,50);
int z=map(az,-32768,32768,0,50); 

if(kx!=x){
digitalWrite(4,HIGH);
Serial.println("Alarm");
  kx=x;
}else{
digitalWrite(4,LOW);
}


delay(10);
}
