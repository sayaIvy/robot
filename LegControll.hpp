#pragma once

#include <ArxContainer.h>
#include <Arduino.h>
#include "ServoMotor.hpp"
#include "GlobalDef.hpp"

struct Leg {
  int base_pin;
  int sub_pin;
  int base_front_angle;
  // int base_center_angle;
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
  const Leg leg0 = { 0, 3, 65, 130, 20, 90, 145 };
  const Leg leg1 = { 4, 7, 60, 120, 20, 90, 145 };
  const Leg leg2 = { 8, 11, 110, 45, 20, 90, 145 };
  const Leg leg3 = { 12, 15, 100, 55, 20, 90, 145 }; 
  // const Leg leg0 = { 0, 3, 65, 90, 20, 90, 145 };
  // const Leg leg1 = { 4, 7, 65, 90, 20, 90, 145 };
  // const Leg leg2 = { 8, 11, 115, 90, 20, 90, 145 };
  // const Leg leg3 = { 12, 15, 115, 90, 20, 90, 145 }; 

}

class LegControll {
  public:
    LegControll();

    ~LegControll();

    void Setup();

    void Walk();

    void Rotate(RotateType direction);

    void Turning();

    void Reverse();

    void Test();

    void Test2();

    void Test3();

  private:

    arx::vector<Leg> legs;

    bool reverse_flg;

    ServoMotor servo_control;

    int delaytime = 500;

};
