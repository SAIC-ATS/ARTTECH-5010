#pragma once

#include "ofMain.h"
#include "ofxEasyFft.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
	
		//void plotFFT(std::vector<float> &fftBuffer, float scale);
	
		std::vector<float> fftBufferV;
		std::vector<ofPolyline> polys;  //an array of polylines which will store the plots of our fft
	
		unsigned int binSize;  //actual bin size is binSize/2
		ofxEasyFft fft;
	
		int fftMagnitudeScale;  //this is what we will multiply the reults of out fft by
	
		int loudestBin;
		float loudest;
		int windowWidth;
		
};
