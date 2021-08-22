#include "MagicBox.hpp"


void MagicBox::render()
{
  if (state_==stPlay)
  {
    programs_[currentProgram_].render();
  }
  else if (state_==stScroll)
  {

  }
  else if (state_==stInit)
  {

  }
}

void MagicBox::addProgram(mbProgram prog)
{
  programs_.push_back(prog);
}

int main()
{
  MagicBox mb = MagicBox();
  mb.addProgram(Program1());
  mb.addProgram(Program2());
  mb.printPrograms();
  mb.printCurrentProgram();
  mb.nextProgram();
  mb.printCurrentProgram();
}
