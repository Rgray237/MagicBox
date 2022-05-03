#pragma once

#include "mbIO.hpp"
#include <utility>

class mbIOXLR : public mbIO
{
float val_;
  int negPin_;
  int posPin_;
  public:
  float V(){return val_;}
  std::pair<int,int> Pin(){return std::pair<int,int>(posPin_,negPin_);}
  
  void SetV(float vPos,float vNeg){val_=vNeg-vPos;}
  void Setup(int posPin,int negPin){negPin_ = negPin; posPin_ = posPin; val_ = 0;}
};
