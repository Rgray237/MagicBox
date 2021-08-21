//Magic Box :)
#include "mbPlugin.h"
#include "mbProgram.h"
#include <iostream>
#include <string>
#include <vector>

class MagicBox
{
  enum {stInit,stScroll,stPlay};

  int         currentProgram_;
  int         state_;
  std::string currentProgramName_;
  std::string catchPhrase_;
  std::vector<mbProgram> programs_;
  std::vector<float> inBuf_;
  std::vector<float> outBuf_;
public:
  MagicBox(){
    currentProgram_ = 0;
  }

  void          addProgram(mbProgram stng){programs_.push_back(stng);}
  void          printPrograms(){for(int i=0;i<programs_.size();i++) std::cout<<programs_[i].getPrintable()<<std::endl;}
  void          printCurrentProgram(){std::cout<<programs_[currentProgram_].getPrintable()<<std::endl;}

  void          nextProgram(){if (currentProgram_ < programs_.size()-1)    currentProgram_++;  }
  void          prevProgram(){if (currentProgram_>0)    currentProgram_--;  }

  void          render();
};
