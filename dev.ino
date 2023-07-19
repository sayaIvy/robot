#pragma once
#include "RobotControll.hpp"
#include "Ultrasonic.hpp"
#include "Acceleration.hpp"

#include "ServoMotor.hpp"
#include "LegControll.hpp"

ServoMotor servo;
LegControll leg;
RobotControll robot;


// Acceleration acceleration;
Ultrasonic ultrasonic1(3,2);
double distance_ultrasonic1 = 0;
// Ultrasonic ultrasonic2(5,4);

void setup() {
  Serial.begin(9600);
  Serial.println("setup");
  // robot.Setup();
  servo.Setup();
  leg.Setup();
  delay(3000);
}

void loop() {
  //robot.Move();
  leg.Test3();

  // if(ultrasonic1.Distance() > DISTANCE) {
  //   Serial.println("1:75m!");
  // }

  distance_ultrasonic1 = ultrasonic1.Distance();
  Serial.println(distance_ultrasonic1);


  // Serial.print("axis X: ");
  // Serial.print(acceleration.ReadAngle(Acceleration::AxisType::axisX));
  // Serial.print(" Y: ");
  // Serial.print(acceleration.ReadAngle(Acceleration::AxisType::axisY));
  // Serial.print(" Z: ");
  // Serial.println(acceleration.ReadAngle(Acceleration::AxisType::axisZ));

}
