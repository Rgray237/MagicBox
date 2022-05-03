#pragma once


class mbIO
{
  float val_;
  int pin_;
  public:
  float V(){return val_;}
  int Pin(){return pin_;}
  
  void SetV(float v){val_=v;}
  void Setup(int pin){pin_ = pin; val_=0;}
};
