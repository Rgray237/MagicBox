//#include "MagicBox.h"
#include "mbPlugin.h"
#include "mbProgram.h"
#include <iostream>
#include <string>
#include <vector>



int main()
{
  MagicBox mb = MagicBox();
  mb.addProgram(Program(0,0,0,0,0));
  mb.addProgram(Program(1,1,2,3,5));
  mb.printPrograms();
  mb.printCurrentProgram();
  mb.nextProgram();
  mb.printCurrentProgram();
}
