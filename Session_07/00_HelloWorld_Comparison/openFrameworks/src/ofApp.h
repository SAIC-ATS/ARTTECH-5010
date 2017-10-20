#pragma once


#include "ofMain.h"


// this is the header file
class ofApp: public ofBaseApp // ofApp "extends" the ofBaseApp class, which defines basic program functionality
{
public:
    // override means that we are inheriting setup() from ofBaseApp and defining this method ourselves.
    void setup() override;
    void draw() override;

    int delayOne = 500;
    int delayTwo = 500;

    bool isOn = true;
};
