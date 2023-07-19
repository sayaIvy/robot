#pragma once

#include "GlobalDef.hpp"
#include "LegControll.hpp"
#include "Acceleration.hpp"
#include "Ultrasonic.hpp"


class RobotControll {
  public:

    RobotControll();

    ~RobotControll();

    void Setup();
    
    void Move();

    void Senser();

    void test();

  private:
  
    LegControll leg_controll;

    Acceleration acceleration1;
    Ultrasonic ultrasonic1;

    RobotStatusType type_;
};