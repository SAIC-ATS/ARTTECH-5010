#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mouseDragged(int x, int y, int button);
	
		void drawSine(float m);
		void drawTriangle(float m);
		void drawRSaw(float m);
	
		void audioOut(ofSoundBuffer &outBuffer);
	
		ofSoundStream stream;
		int samplerate;
		unsigned int buffSize;
	
		std::vector<float> soundBuffer;
		
};
