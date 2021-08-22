#pragma once

#include "mbPlugin.hpp"
#include "mbProgram.hpp"
#include "mbLCD.hpp"
#include "Program1.hpp"
#include "Program2.hpp"
#include <iostream>
#include <string>
#include <vector>

class MagicBox
{
  enum {stInit,stScroll,stPlay};

  int                     currentProgram_;
  int                     state_;
  std::string             currentProgramName_;
  std::vector<mbProgram>  programs_;
  std::vector<float>      inBuf_;
  std::vector<float>      outBuf_;
public:
  MagicBox(){
    currentProgram_ = 0;
  }

  void          addProgram(mbProgram prog);
  void          printPrograms(){for(int i=0;i<programs_.size();i++) std::cout<<programs_[i].getPrintable()<<std::endl;}
  void          printCurrentProgram(){std::cout<<programs_[currentProgram_].getPrintable()<<std::endl;}

  void          nextProgram(){if (currentProgram_ < programs_.size()-1)    currentProgram_++;  }
  void          prevProgram(){if (currentProgram_>0)    currentProgram_--;  }
  int           getState(){return state_;}
  void          render();
};
