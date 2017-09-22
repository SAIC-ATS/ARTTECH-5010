#pragma once


#include "ofMain.h"


// this is the header file
class ofApp: public ofBaseApp // ofApp "extends" the ofBaseApp class, which defines basic program functionality
{
public:
    void setup() override;
    void draw() override;

    int delayOne = 500;
    int delayTwo = 500;

    bool isOn = true;
};
