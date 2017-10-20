#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    uint64_t nextOwlHoot = 0;

    ofSoundPlayer owlSound;
    ofSoundPlayer cricketsSound;
};
