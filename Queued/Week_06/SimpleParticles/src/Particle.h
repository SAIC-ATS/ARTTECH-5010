#pragma once


#include "ofMain.h"


class Particle
{
public:
    void update();
    void draw();
    void reset();

    float xPosition = 0;
    float yPosition = 0;

    float xVelocity = 0;
    float yVelocity = 0;

    float xAcceleration = 0;
    float yAcceleration = 0;

    // Drag slows the velocity.
    // Drag of 0 means, no drag.  Drag of 1 means full drag.
    float drag = 0.0;

    ofTexture texture;
    float rotation = 0;

    int age = 0;
};
