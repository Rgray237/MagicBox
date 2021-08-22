#include <string>
#include <vector>


class mbProgram
{
  std::string name_;

public:
  mbProgram(std::string name){name_ = name;
  std::string getPrintable(){return name_;}
  void render(){}
};
