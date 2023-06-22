#pragma once

#include <ArxContainer.h>
#include <Arduino.h>
#include "ServoMotor.hpp"



struct Leg {
  int base_pin;
  int sub_pin;
  int base_front_angle;
  int base_back_angle;
  int sub_down_angle;
  int sub_center_angle;
  int sub_up_angle;
};

enum RotateType {
  rightward,
  leftward,
  backward,
};

namespace {
  static const Leg leg0 = { 0, 3, 75, 95, 30, 90, 175 };
  static const Leg leg1 = { 4, 7, 75, 95, 30, 90, 175 };
  static const Leg leg2 = { 8, 11, 95, 70, 30, 90, 175 };
  static const Leg leg3 = { 12, 15, 95, 65, 30, 90, 175 }; 
  static const int time_sleep_leg = 200; 
}

class LegControll {
  public:
    LegControll();

    ~LegControll();

    void setup();

    void walk();

    void Rotate(RotateType direction);

    void reverse();

    void Test();


  private:

    arx::vector<Leg> legs;

    bool reverse_flg;

    ServoMotor servo_control;
};
