#pragma once

#include "ofMain.h"
#include "ofxFft.h"
#include "ofxSoundFile.h"

#define NOISE 0
#define MIC 1

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mouseDragged(int x, int y, int button);
	
		ofRectangle rect;

		void audioIn(ofSoundBuffer &inBuffer);
		void audioOut(ofSoundBuffer &outBuffer);
	
		ofSoundStream stream;
		unsigned int samplerate;
		unsigned int buffSize;
	
		ofxFft* fft;
		std::vector<float> binBuffer;
		std::vector<float> passBuffer;
		std::vector<float> audioBinBuffer;
		std::vector<float> noiseBuffer;
	
		float *fftOutput;
		float *processedOutput;
		float *ifftOutput;
	
		ofSoundBuffer song;
	
		ofMutex soundMutex;
	
		int mode;
	
	
		
		
};
