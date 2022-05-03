#pragma once

#include "mbIO.hpp"

class mbIOKnob : public mbIO
{
	
	
  float val_;
  int pin_;
  public:
  float V(){return val_;}
  int Pin(){return pin_;}
  
  void SetV(float v){val_=1-v;}
  void Setup(int pin){pin_ = pin; val_=0;}

};