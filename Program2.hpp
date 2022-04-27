#pragma once
#include "mbProgram.hpp"

class Program2 : public mbProgram
{
<<<<<<< HEAD

public:
  Program2(){
    name_ = "Program 2 a yeaauuuuhh..";
=======
int gAudioFramesPerAnalogFrame = 1;
	float	gInverseSampleRate =1;
	float gPhase=0;
	float gAmplitude = 0;
	float gFrequency = 0;
	Scope scope;
public:
  Program2(){
    name_ = "Program 2 babyyyy";
  }
  
  void setup(BelaContext* context)
  {
  	if(context->analogFrames)
		gAudioFramesPerAnalogFrame = context->audioFrames / context->analogFrames;
	gInverseSampleRate = 1.0 / context->audioSampleRate;
	
	// setup the scope with 3 channels at the audio sample rate
	scope.setup(4, context->audioSampleRate);
	std::cout<<"Program 2 is set up."<<std::endl;
	std::cout<< "SampleRate = "<<context->audioSampleRate<<std::endl;
	std::cout<< "gAudioFramesPerAnalogFrame = "<<gAudioFramesPerAnalogFrame<<std::endl;
	std::cout<< "audioFrames="<<context->audioFrames<<std::endl;
		std::cout<< "analogFrames="<<context->analogFrames<<std::endl;

  }
  
  void render(BelaContext* context){
  	for(unsigned int n = 0; n < context->audioFrames; n++) {

		if(gAudioFramesPerAnalogFrame && !(n % gAudioFramesPerAnalogFrame)) {
			
			ReadAllPins(n,context,gAudioFramesPerAnalogFrame);
			

			gAmplitude = pad_->V() * knob1_->V(); //+ mb.XLR_.V();
			gFrequency = map(knob2_->V(), 0, 1, 200, 2000);
		
			gPhase+= 2.0 * M_PI * gFrequency / context->audioSampleRate;
		}
		float out = 0.15*(gAmplitude*(sinf(gPhase)));
		
		// pass the MagicBox.out  to the audio outputs
		for(unsigned int channel = 0; channel < context->audioOutChannels; channel++) {
			audioWrite(context, n, channel, out);
		}
	}
>>>>>>> 965ef2c (new pc. Added delay effect.)
  }
};
