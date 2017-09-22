#pragma once


#include "ofMain.h"
#include "BaseParticle.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

//    BaseParticle myFirstParticle;
//    BaseParticle mySecondParticle;

    std::vector<BaseParticle> myParticles;

};
