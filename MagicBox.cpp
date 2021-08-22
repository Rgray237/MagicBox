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

int main()
{
  MagicBox mb = MagicBox();
  mb.addProgram(mbProgram("Program 1"));
  mb.addProgram(mbProgram("Program 2"));
  mb.printPrograms();
  mb.printCurrentProgram();
  mb.nextProgram();
  mb.printCurrentProgram();
}
