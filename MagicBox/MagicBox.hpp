#pragma once

#include "mbPlugin.hpp"
#include "mbProgram.hpp"
#include "mbLCD.hpp"
#include "mbIOBtn.hpp"
#include "mbIOKnob.hpp"
#include "mbIOXLR.hpp"
#include "mbIOPad.hpp"
#include "Program1.hpp"
#include "Program2.hpp"
#include "Program3.hpp"
#include <iostream>
#include <string>
#include <vector>

class MagicBox
{
  enum {stInit,stScroll,stPlay};

  int                     currentProgramInd_=0;
  int                     state_ = stPlay;
  std::string             currentProgramName_;
  std::vector<mbProgram*>  programs_;
  std::vector<float>      inBuf_;
  std::vector<float>      outBuf_;
  mbProgram *			  currentProgram_;
  BelaContext*			  context_;
  
  
public:
  mbIOBtn	btnLft_;
  mbIOBtn	btnRght_;
  mbIOKnob	knob1_;
  mbIOKnob	knob2_;
  mbIOKnob	knob3_;
  mbIOPad	pad_;
  mbIOXLR	XLR_;

  void          addProgram(mbProgram* prog);

  void          nextProgram(){if (currentProgramInd_ < programs_.size()-1)    currentProgramInd_++; currentProgram_ = programs_[currentProgramInd_]; currentProgram_->setup(context_); std::cout<<"Setting up "<<currentProgram_->name_<<std::endl;}
  void          prevProgram(){if (currentProgramInd_>0)    currentProgramInd_--; currentProgram_ = programs_[currentProgramInd_]; currentProgram_->setup(context_);}
  int           getState(){return state_;}
  void          render(BelaContext *render);
  void			setup(BelaContext *context);
};
