/*
 This is essentially the same as 00_FFT_visualize,
 but instead of drawing all the waveforms on top of eashother, they are drawn in a grid
*/

#pragma once

#include "ofMain.h"
#include "ofxEasyFft.h" //<-- using ofxEasyFft

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();

	std::vector<float> fftBuffer;
	std::vector<ofPolyline> polys;
	
	unsigned int binSize;  //actual bin size is binSize/2
	ofxEasyFft fft;
	
	float fftScale;
	int loudestBin;
	float loudestFreq;
	int windowWidth;
};

