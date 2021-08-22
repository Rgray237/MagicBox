#pragma once

#include "mbIO.hpp"
#include "mbIOAux.hpp"
#include "mbIOBtn.hpp"
#include "mbIOInst.hpp"
#include "mbIOKnob.hpp"
#include "mbIOPad.hpp"
#include "mbIOXLR.hpp"

#include <string>
#include <vector>


class mbProgram
{
  enum {stInit,stScroll,stPlay};


public:
  mbProgram(){}
  std::string getPrintable(){return name_;}
  void render(){}
  int  getState(){return state_;}

protected:
  int           state_=stInit;
  std::string   name_="";
  mbIOBtn       btnL_;
  mbIOBtn       btnR_;
  mbIOKnob      volKnob_;
  mbIOKnob      knob1_;
  mbIOKnob      knob2_;
  mbIOPad       pad_;
  mbIOAux       auxIn_;
  mbIOAux       auxOut_;
  mbIOInst      instIn_;
  mbIOInst      instOut_;
  mbIOXLR       xlrIn_;
};
