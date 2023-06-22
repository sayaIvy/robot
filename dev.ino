#include <Arduino.h>

#include "Robot.hpp"


void setup() {
  Serial.begin(115200);
  Serial.println("setup");
}




void loop() {
  static Robot robot;

  robot.TestMove();
  delay(30000);

}
