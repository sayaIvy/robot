#include "ServoMotor.hpp"


// コンストラクタ
  ServoMotor::ServoMotor() {
    pwm.begin();         // 初期設定
    pwm.setPWMFreq(50);  // PWM周期を50Hzに設定
    Serial.println("ServoMotor constructor");
  }

// デストラクタ
  ServoMotor::~ServoMotor() {
    Serial.println("ServoMotor destructor");
  }

  void ServoMotor::move(int pin, int angle) {
   angle = map(angle, 0, 180, SERVOMIN, SERVOMAX);
   pwm.setPWM(pin, 0, angle);
  }

