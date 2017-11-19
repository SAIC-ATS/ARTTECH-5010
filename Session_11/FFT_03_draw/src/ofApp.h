#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		ofSoundPlayer player;
	
		bool isPaused;
		unsigned int nBins;
		float * smoothedFft;
	
		int phase;
};
