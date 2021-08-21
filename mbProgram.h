#include <string>
#include <vector>


class mbProgram
{
  int  padMode_;  //0 - pass-through, 1 - sampler, 2 - Effects Chain, 3 - programmed
  int  micMode_;  //0 - pass-through, 1 - Effects Chain, 2 - programmed
  int  jackMode_; //0 - pass-through, 1 - Effects Chain, 2 - programmed
  int  knob1Mode_; //0 - Volume, 1 - Twiddle variable in effects chain. 2- programmed
  int  knob2Mode_;  //0 - Volume, 1- Twiddle, 2- programmed
  int  led1Mode_; //0 - On  1- pulsing, 2 - programmed

  std::string printable(){
    std::string str="";
    str+= std::to_string(padMode_);
    str+= "," + std::to_string(micMode_);
    str+= "," + std::to_string(jackMode_);
    str+= "," + std::to_string(knob1Mode_);
    str+= "," + std::to_string(knob2Mode_);
    str+= "," + std::to_string(led1Mode_);
    return str;
  }

public:
  mbProgram(int padMode,int micMode,int jackMode, int knob1Mode,int knob2Mode) :
  padMode_(padMode), micMode_(micMode),jackMode_(jackMode),knob1Mode_(knob1Mode),knob2Mode_(knob2Mode)
  {}
  std::string getPrintable(){return printable();}
};
