#pragma once

#include <Arduino.h>

#define TEMPERATURE 25

class Ultrasonic {
  public:

    Ultrasonic();   

    Ultrasonic(int trig_pin, int echo_pin);                                                                                                                                                                                                                                                                                                                                                                                                                       

    ~Ultrasonic();

    double Distance();  // 距離測定

  private:

    double duration_;
    double distance_;
    double sound_speed_ = 331.5 + 0.6 * TEMPERATURE;

    int trig_pin_;
    int echo_pin_;
};