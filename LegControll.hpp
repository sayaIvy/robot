#pragma once

#include <ArxContainer.h>
#include <Arduino.h>
#include "ServoMotor.hpp"
#include "DelayDef.hpp"

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
  const Leg leg0 = { 0, 3, 60, 120, 20, 90, 145 };
  const Leg leg1 = { 4, 7, 60, 120, 30, 90, 145 };
  const Leg leg2 = { 8, 11, 120, 60, 30, 90, 145 };
  const Leg leg3 = { 12, 15, 120, 50, 20, 90, 145 }; 
}

class LegControll {
  public:
    LegControll();

    ~LegControll();

    void setup();

    void walk();

    // 二本支持の歩行
    void oldWalk();

    void rotate(RotateType direction);

    void turning();

    void reverse();

    void test(); // experimental walk

    void test2(); // base move

  private:

    arx::vector<Leg> legs;

    bool is_reverse;

    ServoMotor servo_control;

    void UpAndDownOneLeg_(int leg_num);

};
