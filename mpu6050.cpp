#include <Wire.h>//I2C communication
#include <MPU6050.h> //interface m3a l sensor mtaa l mpu

int scl_pin =16; // SCL:serial clck
int sda_pin= 17; // SDA :serial data

MPU6050 mpu;// instance mel class mpu

void setup() {
  Serial.begin(9600);
  Wire.begin(sda_pin, scl_pin);// initialisation lel I2C bus bel sda wel scl pins
  mpu.initialize();

  // Test MPU6050 connection
  Serial.println(mpu.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}

void loop() {

  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);//Read acclrmtr gyrscp data mel mpu

  // hedhi l conversion mel int(rq:l mpu6050 aandah 16-bit resolution good!!) le g(unit:gravity)
  //The MPU6050 sensor has a full-scale range of ±2g, ±4g, ±8g, or ±16g, depending on the sensitivity setting.
  // li nekhdem bih f sim aandah range ±2g aa heka ne9sem aala  16384.0((2^16=)65536 / 4(=2*2 2eqal ranges aal pos w neg kol wa7da bou zoz g ) = 16384)
  float accel_x = (float)ax / 16384.0;
  float accel_y = (float)ay / 16384.0;
  float accel_z = (float)az / 16384.0;

  //hedhi mtaa e gyro
  //The MPU6050 sensor has a full-scale range of ±250°/s, ±500°/s, ±1000°/s, or ±2000°/s, depending on the sensitivity setting.
  // // li nekhdem bih f sim aandah range ±250°/s
  // ((2^16=)65536 /500(=250*2 )=131
  float gyro_x = (float)gx / 131.0;
  float gyro_y = (float)gy / 131.0;
  float gyro_z = (float)gz / 131.0;

  Serial.print("Acceleration");
  Serial.print("X = "); Serial.print(ax);
  delay(1000);
  Serial.print(", Y = "); Serial.print(ay);
  delay(1000);
  Serial.print(", Z = "); Serial.println(az);
  delay(1000);
  Serial.print("Gyroscope");
  Serial.print("X = "); Serial.print(gx);
  delay(1000);
  Serial.print(", Y = "); Serial.print(gy);
  delay(1000);
  Serial.print(", Z = "); Serial.println(gz);
  delay(1000);
  Serial.println();
  delay(1000);}
