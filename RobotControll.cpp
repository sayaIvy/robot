#include "RobotControll.hpp"

RobotControll::RobotControll() 
: type_(Stop)
, read_distance_cm_(-1)
, ultrasonic1_(ultrasonic1_trig_pin, ultrasonic1_echo_pin) {
  Serial.print("RobotControll constructor!");
}

RobotControll::~RobotControll() {
  Serial.print("RobotControll destructor!");
  type_ = Stop;
  read_distance_cm_ = -1;
}

void RobotControll::setup() {
  leg_.setup();
}

void RobotControll::setStatusType(RobotStatusType type) {
  type_ = type;
}

void RobotControll::stateHandler() {
  switch(type_) {
    case Stop:
      Serial.println("Robot is stopping");
      break;
    case Walk:
      readSenser();
      if(read_distance_cm_ > 0.0 && read_distance_cm_ < 20.0) {
        type_ = RotateRight;
      } else {
        walk_();
      }
      Serial.println(read_distance_cm_);
      Serial.println("Robot is walking");
      break;
    case RotateRight:
      Serial.println("Robot is rotation right");
      // rotate_(RotateRight);
      break;
    case RotateLeft:
      Serial.println("Robot is rotation left");
      rotate_(RotateLeft);
      break;
    case Turning:
      Serial.println("Robot is turning");
      turn_();
      break;
    default:
     Serial.println("No status");
     break;
  }
}

void RobotControll::readSenser() {
  // acceleration1.ReadAngle();
  read_distance_cm_ = ultrasonic1_.Distance();
}

void RobotControll::test() {
  leg_.test2();
}

void RobotControll::walk_() {
  leg_.walk();
}

void RobotControll::rotate_(RobotStatusType type) {
  if(type == RotateRight) {
    leg_.rotate(rightward);
  } else if(type == RotateLeft) {
    leg_.rotate(leftward);
  } else {
    Serial.println("rotate faild!");
  }
}

void RobotControll::turn_() {
  leg_.turning();
}