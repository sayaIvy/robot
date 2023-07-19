#include "Acceleration.hpp"

Acceleration::Acceleration() {
  Serial.println("Acceleration Constructor!");
}

Acceleration::~Acceleration() {
  Serial.println("Acceleration Destructor");
}

float Acceleration::ReadAngle(AxisType type) {
  float x = analogRead(x_pin_);
	float y = analogRead(y_pin_);
	float z = analogRead(z_pin_);

  // ゼロ点キャリブレーション
  x -= axis_offset_x;
  y -= axis_offset_y;
  z -= axis_offset_z;

  x /= axis_sensitivity_x;
  y /= axis_sensitivity_y;
  z /= axis_sensitivity_z;

  switch(type) {
    case axisX:
      return atan2(x, sqrt(y * y + z * z)) * (180.0 / PI);
    case axisY:
      return atan2(y, sqrt(x * x + z * z)) * (180.0 / PI);
    case axisZ:
      return atan2(z, sqrt(x * x + y * y)) * (180.0 / PI);
  }

  Serial.println("Please select AxisType");
  return -1.0;
}