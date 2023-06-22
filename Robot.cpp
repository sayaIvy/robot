#include "Robot.hpp"

  Robot::Robot() 
  : type_(init_type) {
    Serial.print("Robot constructor");
    legCT.setup();
    delay(1000);
  }

  Robot::~Robot() {
    Serial.print("Robot destructor");
    type_ = stop;
  }

  void Robot::TestMove() {
    // legCT.Test();
    // delay(time_sleep);
    legCT.walk();
    delay(time_sleep);
    legCT.walk();
    delay(time_sleep);
    legCT.Rotate(rightward);
    delay(time_sleep);
    legCT.walk();
    delay(time_sleep);
    legCT.walk();
    delay(time_sleep);

  }
