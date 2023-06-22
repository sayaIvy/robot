#include "LegControll.hpp"

LegControll::LegControll() 
: reverse_flg(false) {
  legs.clear();
  legs.push_back(leg0);
  legs.push_back(leg1);
  legs.push_back(leg2);
  legs.push_back(leg3);

  Serial.println("leg constructor!");
}

LegControll::~LegControll() {
  legs.clear();
  reverse_flg = false;

  Serial.println("leg destructor!");
}

void LegControll::setup() {  
  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].sub_pin, legs[i].sub_center_angle);
    delay(100);
    servo_control.move(legs[i].base_pin, legs[i].base_front_angle);
    delay(100);
    servo_control.move(legs[i].sub_pin, legs[i].sub_down_angle);
  }
}

void LegControll::walk() {
  // 足上げる
  servo_control.move(legs[0].sub_pin, legs[0].sub_center_angle);
  servo_control.move(legs[2].sub_pin, legs[2].sub_center_angle);
  delay(time_sleep_leg);
  servo_control.move(legs[0].base_pin, legs[0].base_front_angle);
  servo_control.move(legs[2].base_pin, legs[2].base_front_angle);
  servo_control.move(legs[1].base_pin, legs[1].base_back_angle);
  servo_control.move(legs[3].base_pin, legs[3].base_back_angle);
  delay(time_sleep_leg);
  // 足下げる
  if(!reverse_flg) {
    servo_control.move(legs[0].sub_pin, legs[0].sub_down_angle);
    servo_control.move(legs[2].sub_pin, legs[2].sub_down_angle);
  } else {
    servo_control.move(legs[0].sub_pin, legs[0].sub_up_angle);
    servo_control.move(legs[2].sub_pin, legs[2].sub_up_angle);
  }
  delay(time_sleep_leg);
  // 足上げる
  servo_control.move(legs[1].sub_pin, legs[1].sub_center_angle);
  servo_control.move(legs[3].sub_pin, legs[3].sub_center_angle);
  delay(time_sleep_leg);
  servo_control.move(legs[0].base_pin, legs[0].base_back_angle);
  servo_control.move(legs[2].base_pin, legs[2].base_back_angle);
  servo_control.move(legs[1].base_pin, legs[1].base_front_angle);
  servo_control.move(legs[3].base_pin, legs[3].base_front_angle);
  delay(time_sleep_leg);
  // 足下げる
  if(!reverse_flg) {
    servo_control.move(legs[1].sub_pin, legs[1].sub_down_angle);
    servo_control.move(legs[3].sub_pin, legs[3].sub_down_angle);
  } else {
    servo_control.move(legs[1].sub_pin, legs[1].sub_up_angle);
    servo_control.move(legs[3].sub_pin, legs[3].sub_up_angle);
  }
  delay(time_sleep_leg);
}


void LegControll::Rotate(RotateType direction) {
  Leg tmp;
  switch (direction) {
    case rightward: // leg0 → leg1 右足
      // tmp = legs[0];

      // for(int i = 0; i < legs.size() - 1; i++) {
      //   legs[i] = legs[i+1];
      // }
      // legs[legs.size() - 1] = tmp;

      legs.clear();
      legs.push_back(leg1);
      legs.push_back(leg2);
      legs.push_back(leg3);
      legs.push_back(leg0);


      break;
    case leftward: // leg0 → leg3 右足
      tmp = legs[legs.size() - 1];

      for(int i = legs.size() - 1; i > 0; i++) {
        legs[i] = legs[i-1];
      }
      legs[0] = tmp;
      break;
    case backward:
      //
      break;
  }
}

void LegControll::reverse() {
  if(reverse_flg) {
    Serial.print("reverse true");
    reverse_flg = true;
  } else {
    Serial.print("reverse false");
    reverse_flg = false;
  }
}

void LegControll::Test() {
  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].base_pin, legs[i].base_front_angle);
  }
  delay(time_sleep_leg);
  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].base_pin, legs[i].base_back_angle);
  }
  delay(time_sleep_leg);
  
}

