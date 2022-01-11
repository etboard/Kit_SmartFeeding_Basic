#include <ESP32Servo.h>

int touch_sensor = D2;
static const int servoPin = D5;
Servo servo;

void setup() {
  Serial.begin(115200);
  servo.attach(servoPin);
  servo.write(50);
  pinMode(touch_sensor, INPUT);
}

void loop() {
  int touch_sensor_result = digitalRead(touch_sensor);
  
  
  if(touch_sensor_result == 1){
    servo.write(0);
    delay(2000);
  }
   else {
    servo.write(50);
   }
  
}
