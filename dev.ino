#pragma once
#include "RobotControll.hpp"

RobotControll robot;

int counter = 2;

void setup() {
  Serial.begin(9600);
  Serial.println("setup");
  robot.setup();
  delay(3000);
  
  robot.setStatusType(RobotStatusType::Walk);
}

void loop() {
  // robot.test();

  // 障害物
  robot.setStatusType(RobotStatusType::Walk);
  for(int i = 0; i < counter; i++) {
    robot.stateHandler();
  }

  delay(1000);
  for(int i = 0; i < 3; i++) {
    robot.test();
    delay(500);
  }

  for(int i = 0; i < counter; i++) {
    robot.stateHandler();
  }



  // Serial.println("RotateRight");
  // robot.setStatusType(RobotStatusType::RotateRight);
  // robot.stateHandler();

  // robot.setStatusType(RobotStatusType::Walk);
  // for(int i = 0; i < counter; i++) {
  //   robot.stateHandler();
  // }

  // Serial.println("RotateLeft");
  // robot.setStatusType(RobotStatusType::RotateLeft);
  // robot.stateHandler();
  // for(int i = 0; i < counter; i++) {
  //   robot.setStatusType(RobotStatusType::Walk);
  //   robot.stateHandler();
  // }
}
