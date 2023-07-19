#pragma once 

#include <Arduino.h>

namespace {
  float axis_offset_x = 30.0;
  float axis_offset_y = 29.0;
  float axis_offset_z = 44.0;  
  float axis_sensitivity_x = 1.0;
  float axis_sensitivity_y = 1.0;
  float axis_sensitivity_z = 1.0;
}


class Acceleration {
  public:

    enum AxisType {
      axisX,
      axisY,
      axisZ,
    };


    Acceleration();

    ~Acceleration();

    float ReadAngle(AxisType type);


  private:

    const int x_pin_ = 0;
    const int y_pin_ = 1;
    const int z_pin_ = 2;
    
};