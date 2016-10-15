#pragma once

#include "ofMain.h"

class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();


    float xPosition = 0;
    float xVelocity = 1;

    float xPosition0 = 0;
    float xVelocity0 = 2;

    float xPosition1 = 0;
    float xVelocity1 = 3;

    // Or we could do it with arrays ...
    // std::size_t numParticles = 3;
    // float positions[] = { 0, 0, 0 };
    // float velocities[] = { 1, 2, 3 };

};
