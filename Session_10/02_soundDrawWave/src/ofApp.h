#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);

		void audioOut(ofSoundBuffer &outBuffer);
	
		ofSoundStream stream;
		float phase;
		int sampleRate;
	
		std::vector<float> soundBuffer;
		float freq, vol;
	
};
