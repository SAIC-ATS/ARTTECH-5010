#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mouseDragged(int x, int y, int button);

	
		ofSoundPlayer leftSound;
		ofSoundPlayer rightSound;
	
		ofxPanel gui;
		ofParameter<float> leftVolume;
		ofParameter<float> rightVolume;
		ofParameter<float> leftSpeed;
		ofParameter<float> rightSpeed;
		ofParameter<bool> playSounds;
	
};
