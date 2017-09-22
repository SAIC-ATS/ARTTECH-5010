#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
	void setup() override;
	void update() override;
	void draw() override;

	std::vector<float> myPositions;
	std::vector<float> myIncrements;

};
