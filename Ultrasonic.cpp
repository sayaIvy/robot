#include "Ultrasonic.hpp"

Ultrasonic::Ultrasonic() 
: duration_(0)
, distance_(0)
, trig_pin_(3)
, echo_pin_(2) {
  Serial.println("Ultrasonic Constructor");
}

Ultrasonic::Ultrasonic(int trig_pin, int echo_pin) 
: duration_(0)
, distance_(0)
, trig_pin_(trig_pin)
, echo_pin_(echo_pin) {
  Serial.println("Ultrasonic Constructor!");
}

Ultrasonic::~Ultrasonic() {
  duration_ = 0;
  distance_ = 0;
  trig_pin_ = 3;
  echo_pin_ = 2;
  Serial.println("Ultrasonic Constructor!");  
}

double Ultrasonic::Distance() {  // 距離測定
  digitalWrite(trig_pin_, LOW); 
  delayMicroseconds(2); 
  digitalWrite( trig_pin_, HIGH ); //超音波を出力
  delayMicroseconds( 10 );
  digitalWrite( trig_pin_, LOW );
  duration_ = pulseIn( echo_pin_, HIGH ); //センサからの入力
  if (duration_ > 0) {
    duration_ = duration_/2; //往復距離を半分にする
    distance_ = duration_*340*100/1000000; // 音速を340m/sに設定
    
    return distance_;
  }
  return -1;
}