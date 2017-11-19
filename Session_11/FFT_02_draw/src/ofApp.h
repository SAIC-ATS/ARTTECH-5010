#pragma once

#include "ofMain.h"
#include "ofxProcessFft.h"
							//using ProcessFft
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
	
	
		ProcessFFT fft;
		std::vector<float> myFreqLevels;
		
};
