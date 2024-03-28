#include <ESP32Servo.h>
Servo servm;//instance mel class servo
Servo servh;
int servpinmin=21;
int servpinh=19;
int mi=0,h=0;
void setup() {
  // put your setup code here, to run once:
  servm.attach(servpinmin,1000,2000);//attach a servo motor to a specific GPIO pin of the ESP32
  servh.attach(servpinh,1000,2000);
  Serial.begin(115200);
}

void loop() {
  servm.write(mi);
  delay(90);
  if(!(mi%45)){
  h+=20;
  servh.write(h);}
  mi++;
}


// You just forgot to attach a range to servo motor because servo motors work in angle so it need a specific range 1000 to 2000, or maybe 0 to 180
