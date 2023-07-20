#pragma once
#include "RobotControll.hpp"

RobotControll robot;

void setup() {
  Serial.begin(9600);
  Serial.println("setup");
  robot.setup();
  delay(3000);
  
  robot.setStatusType(RobotStatusType::Walk);
}

void loop() {
  robot.stateHandler();



  // Serial.print("axis X: ");
  // Serial.print(acceleration.ReadAngle(Acceleration::AxisType::axisX));
  // Serial.print(" Y: ");
  // Serial.print(acceleration.ReadAngle(Acceleration::AxisType::axisY));
  // Serial.print(" Z: ");
  // Serial.println(acceleration.ReadAngle(Acceleration::AxisType::axisZ));

}
