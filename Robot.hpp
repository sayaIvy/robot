#pragma once

#include "GlobalDef.hpp"
#include "LegControll.hpp"

namespace {
  static const RobotStatusType init_type = stop;
  static const int time_sleep = 300;
}

class Robot {
  public:

    Robot();

    ~Robot();

    void TestMove();

  private:

    LegControll legCT;

    RobotStatusType type_;
};