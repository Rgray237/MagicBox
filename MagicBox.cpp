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
  mb.addProgram(mbProgram(0,0,0,0,0));
  mb.addProgram(mbProgram(1,1,2,3,5));
  mb.printPrograms();
  mb.printCurrentProgram();
  mb.nextProgram();
  mb.printCurrentProgram();
}
