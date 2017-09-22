#pragma once


#include "ofMain.h"
#include "BaseParticle.h"
#include "SpecialParticle.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void addRandomParticle();

    std::size_t maxNumParticles = 500;

    std::vector<std::shared_ptr<BaseParticle>> myParticles;

    ofEasyCam cam;

};
