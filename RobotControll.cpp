#include "RobotControll.hpp"

  RobotControll::RobotControll() 
  : type_(stop) {
    Serial.print("RobotControll constructor!");
  }

  RobotControll::~RobotControll() {
    Serial.print("RobotControll destructor!");
    type_ = stop;
  }

  void RobotControll::Setup() {
    leg_controll.Setup();
  }

  void RobotControll::Move() {
    leg_controll.Walk(); 
  }


  void RobotControll::Senser() {
    // acceleration1.ReadAngle();
    ultrasonic1.Distance();
  }

