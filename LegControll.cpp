#include "LegControll.hpp"

LegControll::LegControll() 
: is_reverse(false) {
  legs.clear();
  legs.push_back(leg0);
  legs.push_back(leg1);
  legs.push_back(leg2);
  legs.push_back(leg3);

  Serial.println("leg constructor!");
}

LegControll::~LegControll() {
  legs.clear();
  is_reverse = false;

  Serial.println("leg destructor!");
}

void LegControll::setup() {  
  servo_control.Setup();
  delay(LEG_DELAY_TIME);
  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].sub_pin, legs[i].sub_center_angle);
    delay(100);
    servo_control.move(legs[i].base_pin, 90);
    delay(100);
    servo_control.move(legs[i].sub_pin, legs[i].sub_down_angle);
  }
}

void LegControll::walk() {
  UpAndDownOneLeg_(1);
  delay(LEG_DELAY_TIME);  
  UpAndDownOneLeg_(0);

  servo_control.move(legs[1].base_pin, legs[1].base_back_angle);
  servo_control.move(legs[3].base_pin, legs[3].base_back_angle);
  delay(LEG_DELAY_TIME);

  UpAndDownOneLeg_(2);
  delay(LEG_DELAY_TIME);  
  UpAndDownOneLeg_(3);

  servo_control.move(legs[2].base_pin, legs[2].base_back_angle);
  servo_control.move(legs[0].base_pin, legs[0].base_back_angle);

}

void LegControll::oldWalk() {
  // 足上げる
  servo_control.move(legs[0].sub_pin, legs[0].sub_center_angle);
  servo_control.move(legs[2].sub_pin, legs[2].sub_center_angle);
  delay(COMMON_DELAY_TIME);
  servo_control.move(legs[0].base_pin, legs[0].base_front_angle);
  servo_control.move(legs[2].base_pin, legs[2].base_front_angle);
  servo_control.move(legs[1].base_pin, legs[1].base_back_angle);
  servo_control.move(legs[3].base_pin, legs[3].base_back_angle);
  delay(COMMON_DELAY_TIME);
  // 足下げる
  if(!is_reverse) {
    servo_control.move(legs[0].sub_pin, legs[0].sub_down_angle);
    servo_control.move(legs[2].sub_pin, legs[2].sub_down_angle);
  } else {
    servo_control.move(legs[0].sub_pin, legs[0].sub_up_angle);
    servo_control.move(legs[2].sub_pin, legs[2].sub_up_angle);
  }
  delay(COMMON_DELAY_TIME);
  // 足上げる
  servo_control.move(legs[1].sub_pin, legs[1].sub_center_angle);
  servo_control.move(legs[3].sub_pin, legs[3].sub_center_angle);
  delay(COMMON_DELAY_TIME);
  servo_control.move(legs[0].base_pin, legs[0].base_back_angle);
  servo_control.move(legs[2].base_pin, legs[2].base_back_angle);
  servo_control.move(legs[1].base_pin, legs[1].base_front_angle);
  servo_control.move(legs[3].base_pin, legs[3].base_front_angle);
  delay(COMMON_DELAY_TIME);
  // 足下げる
  if(!is_reverse) {
    servo_control.move(legs[1].sub_pin, legs[1].sub_down_angle);
    servo_control.move(legs[3].sub_pin, legs[3].sub_down_angle);
  } else {
    servo_control.move(legs[1].sub_pin, legs[1].sub_up_angle);
    servo_control.move(legs[3].sub_pin, legs[3].sub_up_angle);
  }
}


void LegControll::rotate(RotateType direction) {
  Leg tmp;
  switch (direction) {
    case rightward: // leg0 → leg1 右足
      // tmp = legs[0];

      // for(int i = 0; i < legs.size() - 1; i++) {
      //   legs[i] = legs[i+1];
      // }
      // legs[legs.size() - 1] = tmp;

      legs.clear();
      legs.push_back(leg1); // b
      legs.push_back(leg2); // a
      legs.push_back(leg3); // c
      legs.push_back(leg0); // d
      break;
    case leftward: // leg0 → leg3 右足
      tmp = legs[legs.size() - 1];

      for(int i = legs.size() - 1; i > 0; i--) {
        legs[i] = legs[i-1];
      }
      legs[0] = tmp;
      break;
    case backward:
      //
      break;
  }
}

void LegControll::turning() {
  servo_control.move(legs[0].sub_pin, legs[0].sub_center_angle);
  servo_control.move(legs[2].sub_pin, legs[2].sub_center_angle);
  delay(COMMON_DELAY_TIME);
  servo_control.move(legs[0].base_pin, legs[0].base_front_angle);
  servo_control.move(legs[2].base_pin, legs[2].base_back_angle);
  servo_control.move(legs[1].base_pin, legs[1].base_back_angle);
  servo_control.move(legs[3].base_pin, legs[3].base_front_angle);
  delay(COMMON_DELAY_TIME);
  // 足下げる
  if(!is_reverse) {
    servo_control.move(legs[0].sub_pin, legs[0].sub_down_angle);
    servo_control.move(legs[2].sub_pin, legs[2].sub_down_angle);
  } else {
    servo_control.move(legs[0].sub_pin, legs[0].sub_up_angle);
    servo_control.move(legs[2].sub_pin, legs[2].sub_up_angle);
  }
  delay(COMMON_DELAY_TIME);
  // 足上げる
  servo_control.move(legs[1].sub_pin, legs[1].sub_center_angle);
  servo_control.move(legs[3].sub_pin, legs[3].sub_center_angle);
  delay(COMMON_DELAY_TIME);
  servo_control.move(legs[0].base_pin, legs[0].base_back_angle);
  servo_control.move(legs[2].base_pin, legs[2].base_front_angle);
  servo_control.move(legs[1].base_pin, legs[1].base_front_angle);
  servo_control.move(legs[3].base_pin, legs[3].base_back_angle);
  delay(COMMON_DELAY_TIME);
  // 足下げる
  if(!is_reverse) {
    servo_control.move(legs[1].sub_pin, legs[1].sub_down_angle);
    servo_control.move(legs[3].sub_pin, legs[3].sub_down_angle);
  } else {
    servo_control.move(legs[1].sub_pin, legs[1].sub_up_angle);
    servo_control.move(legs[3].sub_pin, legs[3].sub_up_angle);
  }
  delay(COMMON_DELAY_TIME);
}

void LegControll::reverse() {
  if(is_reverse) {
    Serial.print("reverse true");
    is_reverse = true;
  } else {
    Serial.print("reverse false");
    is_reverse = false;
  }
}

void LegControll::test() {
  UpAndDownOneLeg_(1);
  UpAndDownOneLeg_(2);
  UpAndDownOneLeg_(0);
  UpAndDownOneLeg_(3);

  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].base_pin, legs[i].base_back_angle);
  }

}

void LegControll::test2() {
  // 右後ろ
  servo_control.move(legs[2].sub_pin, legs[2].sub_center_angle);
  servo_control.move(legs[2].base_pin, legs[2].base_front_angle);
  delay(LEG_DELAY_TIME);
  servo_control.move(legs[2].base_pin, legs[2].base_back_angle);
  delay(LEG_DELAY_TIME);
  servo_control.move(legs[2].sub_pin, legs[2].sub_down_angle);
  delay(LEG_DELAY_TIME);  

  // 右前
  servo_control.move(legs[1].sub_pin, legs[1].sub_center_angle);
  servo_control.move(legs[1].base_pin, legs[1].base_back_angle);
  delay(LEG_DELAY_TIME);
  servo_control.move(legs[1].base_pin, legs[1].base_front_angle);
  delay(LEG_DELAY_TIME);
  servo_control.move(legs[1].sub_pin, legs[1].sub_down_angle);

  servo_control.move(legs[2].base_pin, legs[2].base_front_angle);
  servo_control.move(legs[0].base_pin, legs[0].base_front_angle);
  delay(LEG_DELAY_TIME);

  servo_control.move(legs[3].sub_pin, legs[3].sub_center_angle);
  servo_control.move(legs[3].base_pin, legs[3].base_back_angle);
  delay(LEG_DELAY_TIME);
  servo_control.move(legs[3].base_pin, legs[3].base_front_angle);
  delay(LEG_DELAY_TIME);
  servo_control.move(legs[3].sub_pin, legs[3].sub_down_angle);
  delay(LEG_DELAY_TIME);  

  servo_control.move(legs[0].sub_pin, legs[0].sub_center_angle);
  servo_control.move(legs[0].base_pin, legs[0].base_front_angle);
  delay(LEG_DELAY_TIME);
  servo_control.move(legs[0].base_pin, legs[0].base_back_angle);
  delay(LEG_DELAY_TIME);
  servo_control.move(legs[0].sub_pin, legs[0].sub_down_angle);


  servo_control.move(legs[1].base_pin, legs[1].base_back_angle);
  servo_control.move(legs[3].base_pin, legs[3].base_back_angle);

}


void LegControll::UpAndDownOneLeg_(int leg_num) {
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_center_angle);
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_back_angle);
  delay(LEG_DELAY_TIME);
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_front_angle);
  delay(LEG_DELAY_TIME);
  if(!is_reverse) {
    servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_down_angle);
  } else {
    servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_up_angle);
  }
}


