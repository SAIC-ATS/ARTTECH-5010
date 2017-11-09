#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		void audioOut( ofSoundBuffer &outBuffer );
	
		//out sound stream, out connection to out hardware interface
		ofSoundStream stream;
	
		//the phase of out sine wave
		float phase;
		float freq;
		int sampleRate;
		float volume;
	
};
