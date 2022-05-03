#pragma once


class mbLCD//i2c LCD screen class
{
  char line1Txt[16];
  char line2Txt[16];
public:
  mbLCD(){}
  void update(char line1[16],char line2[16])
  {
    for(int i=0;i<16;i++)
    {
      line1Txt[i]=line1[i];
      line2Txt[i]=line2[i];
    }

  }

};
