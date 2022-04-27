#pragma once

#include "mbIO.hpp"

class mbIOBtn : public mbIO
{
<<<<<<< HEAD
=======
	int val_=0;
	int state_=stOpen;
	int debounceCounter_=0;
	int debounceInterval_=50;
	int prevState_ = stOpen;
	bool toggle = false;
	enum
	{
		stOpen,stJustClosed,stClosed,stJustOpened
	};
	public:
	int V(){return val_;}
	
	bool Toggle(){
		return toggle;
	}
	
	void setToggleFalse()
	{
		toggle = false;
	}
	
	void SetV(int v){
		val_=v;
		prevState_ = state_;
		if(state_ == stOpen) 
			{
				if (v==1)
				{
				state_=stJustClosed;
				}
			}
		else if(state_ == stJustClosed)
			{
				debounceCounter_++;
				if (debounceCounter_>debounceInterval_ && v==1)
				{
					state_ = stClosed;
					debounceCounter_=0;
					toggle = true;
				}
			}
		else if(state_ == stClosed)
			{
				if (v==0)
				{
				state_ = stJustOpened;
				}
				
			}
		else if(state_ == stJustOpened)
			{
				debounceCounter_++;
				if (debounceCounter_>debounceInterval_ && v==0)
				{
					state_ = stOpen;
				}

			}
	}
	
>>>>>>> 965ef2c (new pc. Added delay effect.)

};
