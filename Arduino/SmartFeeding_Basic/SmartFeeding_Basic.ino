/******************************************************************************************
 * FileName     : SmartFeeding_Basic
 * Description  : 스마트모이공급 코딩 키트 (기본)
 * Author       : 이승찬
 * CopyRight    : (주)한국공학기술연구원(www.ketri.re.kr)
 * Warning      : Arduino IDE에서 ESP32Servo 라이브러리를 추가해서 컴파일 해야힘
 * Created Date : 2022.01.04 : LSC : 최초 작성
 * Modified     : 2022.01.12 : SCS : 소스 크린징
 * Modified     : 2022.02.10 : SCS : 소스 크린징
 * Modified     : 2022.10.03 : SCS : support arduino uno with ET-Upboard
******************************************************************************************/

#include "pins_arduino.h"           // support arduino uno with ET-Upboard

// 서보모터 제어를 위한 라이브러리 불러오기
#if defined(ARDUINO_AVR_UNO)   
  #include <Servo.h>
#else 
  #include <ESP32Servo.h>
#endif
  
Servo servo;

const int touch_sensor     = D2;        // 터치센서 핀
const int servo_motor      = D5;        // 서보모터 핀

//==========================================================================================
void setup()
//==========================================================================================
{
  Serial.begin(115200);                 // 시리얼 통신 준비

  servo.attach(servo_motor);            // 서보모터 제어 시작
  servo.write(50);                      // 서보모터를 기본(닫힘) 상태로 초기화

  pinMode(touch_sensor, INPUT);
}

//==========================================================================================
void loop()
//==========================================================================================
{
  int touch_sensor_result = digitalRead(touch_sensor);

  if(touch_sensor_result == HIGH)       // 터치센서가 눌러졌으면
  {
    servo.write(0);                     // 서보모터를 열림 상태로 만듦
    delay(2000);                        // 모이가 내려가길 2초동안 기다림
  }
  else
  {
    servo.write(50);                    // 서보모터를 기본(닫힘) 상태로 초기화
  }
}

//==========================================================================================
//
// (주)한국공학기술연구원 http://et.ketri.re.kr
//
//==========================================================================================
