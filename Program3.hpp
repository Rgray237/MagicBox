#pragma once
#include "mbProgram.hpp"
#include <libraries/AudioFile/AudioFile.h>
#include "MonoFilePlayer.h"

class Program3 : public mbProgram
{
	std::string filename="timenod.wav";
	MonoFilePlayer gPlayer_;

	std::vector<float> sampleBuf_;				// Buffer that holds the sound file
	std::vector<float> delayBuf_;
	unsigned int readPt_ = 0;							// Position of the last frame we played 
	unsigned int writePt_ = 0;
	
	int 	gAudioFramesPerAnalogFrame = 1;
	float	gInverseSampleRate =1;
	float	gAmplitude = 0;
	Scope	scope;
public:
  Program3(){
    name_ = "Program 3 babyyyy";
  }
  
  void setup(BelaContext* context)
  {
  	if(context->analogFrames)
		gAudioFramesPerAnalogFrame = context->audioFrames / context->analogFrames;
	gInverseSampleRate = 1.0 / context->audioSampleRate;
	
	std::cout<<"Program 3 is set upp."<<std::endl;
	std::cout<< "SampleRate = "<<context->audioSampleRate<<std::endl;
	std::cout<< "gAudioFramesPerAnalogFrame = "<<gAudioFramesPerAnalogFrame<<std::endl;
	std::cout<< "audioFrames="<<context->audioFrames<<std::endl;

	std::cout<< "analogFrames="<<context->analogFrames<<std::endl;

	delayBuf_.resize(2*context->audioSampleRate);
	
	gPlayer_.setup(filename);
  }
  
  void render(BelaContext* context){
  	
			gAmplitude = knob1_->V();
  			float delay = knob2_->V();
  			   delay = (int)(delay * 50);
  			   delay = delay / 50.0;
			
			
			
  			float feedback = pad_->V();
  			
  			int delayInSamples = delay*context->audioSampleRate;
  			
  			//Calculate read ptr based on diff from write ptr
  	  		readPt_ = (writePt_ - delayInSamples + delayBuf_.size()) % delayBuf_.size();

  	for(unsigned int n = 0; n < context->audioFrames; n++) {
  	  	
			ReadAllPins(n,context,gAudioFramesPerAnalogFrame);
			
			//Standard audio file process.
			float in = gPlayer_.process()*gAmplitude;
			
			//Read the output from the write ptr (oldest sample)
			float out = delayBuf_[readPt_];
			
			//Overwrite delaybuffer at write pointer
			delayBuf_[writePt_] = in+out*feedback;



			writePt_++;
			if (writePt_>=delayBuf_.size())
				writePt_=0;
			readPt_++;
			if(readPt_>=delayBuf_.size())
				readPt_=0;
				
			
				audioWrite(context, n, 0, in);
				audioWrite(context, n, 1, out);

	}
  }
};
