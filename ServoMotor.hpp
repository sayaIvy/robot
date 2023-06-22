#pragma once

#include <Wire.h>                      // ライブラリのインクルード
#include <Adafruit_PWMServoDriver.h>
 
#define SERVOMIN 100    // 最小パルス幅(~4096の範囲)
#define SERVOMAX 550    // 最大パルス幅(~4096の範囲)

namespace {
  Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);  // PCA9685のI2Cアドレスを指定(デフォルト値は0x40)
}

class ServoMotor {
  public:
  // コンストラクタ
    ServoMotor();

  // デストラクタ
    ~ServoMotor();

    void move(int pin, int angle);

  private:

};
