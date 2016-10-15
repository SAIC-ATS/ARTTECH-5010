#pragma once


// #include "ofMain.h" // or be more specific
#include "ofVec3f.h"
#include "ofGraphics.h"


class BaseParticle
{
public:
    BaseParticle();

    void update();
    void draw();

    ofVec3f position;
    ofVec3f velocity;
    ofVec3f acceleration;

    int age;

}; // Don't forget the semi-colon after your class definition.
