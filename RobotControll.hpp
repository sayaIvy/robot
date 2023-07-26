#pragma once

#include "DelayDef.hpp"
#include "LegControll.hpp"
#include "Acceleration.hpp"
#include "Ultrasonic.hpp"

// #define DISTANCE 75 壁判定距離

enum RobotStatusType {
  Stop,
  Walk,
  RotateRight, // 動かずに向きを変える
  RotateLeft,
  Turning, // その場で回転
};

namespace {
  static const int ultrasonic1_echo_pin = 2;
  static const int ultrasonic1_trig_pin = 3;
}

class RobotControll {
  public:

    RobotControll();

    ~RobotControll();

    void setup();

    void setStatusType(RobotStatusType type);

    void stateHandler();
    
    void readSenser();

    void test();

  private:

    RobotStatusType type_;
    double read_distance_cm_;
    int controll_walk_counter_;

    bool is_right_direction_;
    bool is_left_direction_;
  
    LegControll leg_;
    Acceleration acceleration_;
    Ultrasonic ultrasonic1_;

    void walk_();
    void turn_();
    void rotate_(RobotStatusType type);
};