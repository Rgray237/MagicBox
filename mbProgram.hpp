#pragma once
<<<<<<< HEAD

=======
#include <Bela.h>
>>>>>>> 965ef2c (new pc. Added delay effect.)
#include "mbIO.hpp"
#include "mbIOAux.hpp"
#include "mbIOBtn.hpp"
#include "mbIOInst.hpp"
#include "mbIOKnob.hpp"
#include "mbIOPad.hpp"
#include "mbIOXLR.hpp"
<<<<<<< HEAD

=======
#include <cmath>
#include <libraries/Scope/Scope.h>
#include <iostream>
>>>>>>> 965ef2c (new pc. Added delay effect.)
#include <string>
#include <vector>


class mbProgram
{
  enum {stInit,stScroll,stPlay};
<<<<<<< HEAD


public:
  mbProgram(){}
  std::string getPrintable(){return name_;}
  void render(){}
  int  getState(){return state_;}

protected:
  int           state_=stInit;
  std::string   name_="";
  mbIOBtn       btnL_;
  mbIOBtn       btnR_;
  mbIOKnob      volKnob_;
  mbIOKnob      knob1_;
  mbIOKnob      knob2_;
  mbIOPad       pad_;
  mbIOAux       auxIn_;
  mbIOAux       auxOut_;
  mbIOInst      instIn_;
  mbIOInst      instOut_;
  mbIOXLR       xlrIn_;
=======
	

public:


  mbProgram(){
  	
	}
  virtual void setup(BelaContext* context)
  {
	if(context->analogFrames)
		gAudioFramesPerAnalogFrame = context->audioFrames / context->analogFrames;
	gInverseSampleRate = 1.0 / context->audioSampleRate;
	
  }
  virtual void render(BelaContext* context){}
  
  
	void ReadAllPins(int n, BelaContext* context,float audioFramesPerAnalogFrame)
	{
		pad_->SetV(analogRead(context, n/audioFramesPerAnalogFrame, pad_->Pin()));
		knob1_->SetV(analogRead(context, n/audioFramesPerAnalogFrame, knob1_->Pin()));
		knob2_->SetV(analogRead(context, n/audioFramesPerAnalogFrame, knob2_->Pin()));
		knob3_->SetV(analogRead(context, n/audioFramesPerAnalogFrame, knob3_->Pin()));
		xlrIn_->SetV(analogRead(context, n/audioFramesPerAnalogFrame, xlrIn_->Pin().first),analogRead(context, n/audioFramesPerAnalogFrame, xlrIn_->Pin().second));
		btnL_->SetV(digitalRead(context,n,btnL_->Pin()));
		btnR_->SetV(digitalRead(context,n,btnR_->Pin()));
	}


int         	state_	=stInit;
  std::string   name_	="";
  mbIOBtn	*   btnL_;
  mbIOBtn	*   btnR_;
  mbIOKnob  *   volKnob_;
  mbIOKnob  *   knob1_;
  mbIOKnob  *	knob2_;
  mbIOKnob	*	knob3_;
  mbIOPad   *   pad_;
  mbIOAux   *	auxIn_;
  mbIOAux   *	auxOut_;
  mbIOInst  *	instIn_;
  mbIOInst  *	instOut_;
  mbIOXLR   *	xlrIn_;
  
  protected:
  int gAudioFramesPerAnalogFrame = 0;
	float	gInverseSampleRate =0;
	float gPhase=0;
  
>>>>>>> 965ef2c (new pc. Added delay effect.)
};
