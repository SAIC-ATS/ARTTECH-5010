#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    // We have no need for setup, so it's not here.
    // We have no need for update, so it's not here.
    void draw() override;

    // This position will change over time.
	float xPosition = 0;

};
