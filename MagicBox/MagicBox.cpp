#include "MagicBox.hpp"

MagicBox mb;

void MagicBox::render(BelaContext* context)
{
  if (state_==stPlay)
  {
  	currentProgram_->render(context);
    
  }
  else if (state_==stScroll)
  {

  }
  else if (state_==stInit)
  {

  }
  if (btnRght_.Toggle())
  {
  	nextProgram();
  	btnRght_.setToggleFalse();
  }
  
  if (btnLft_.Toggle())
  {
  	prevProgram();
  	btnLft_.setToggleFalse();
  }
}

void MagicBox::setup(BelaContext* context)
{
	context_ = context;
	pad_.Setup(7);
	knob1_.Setup(6);
	knob2_.Setup(5);
	knob3_.Setup(4);
	btnLft_.Setup(1);
	btnRght_.Setup(0);
	XLR_.Setup(3,2);
	
	pinMode(context, 0, mb.btnLft_.Pin(), INPUT); //set input
	pinMode(context, 0, mb.btnRght_.Pin(), INPUT); //set input
	
	
	mbProgram* prog1 = new Program1();
	mbProgram* prog2 = new Program2();
	mbProgram* prog3 = new Program3();

	addProgram(prog1);
	addProgram(prog2);
	addProgram(prog3);

	currentProgram_ = prog1;
	prog1->setup(context_);
	std::cout<<"This many programs..."<<programs_.size()<<std::endl;
}


void MagicBox::addProgram(mbProgram* prog)
{
	prog->btnL_ = &btnLft_;
	prog->btnR_ = &btnRght_;
	prog->pad_ = &pad_;
	prog->knob1_ = &knob1_;
	prog->knob2_ = &knob2_;
	prog->knob3_ = &knob3_;
	prog->xlrIn_ = &XLR_;
	
  programs_.push_back(prog);
}


bool setup(BelaContext *context, void *userData)
{
	mb.setup(context);

	return true;
}

void render(BelaContext *context, void *userData)
{
	mb.render(context);
}

void cleanup(BelaContext *context, void *userData)
{

}