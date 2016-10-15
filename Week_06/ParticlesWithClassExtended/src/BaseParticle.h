#pragma once


#include "ofVec3f.h"
#include "ofGraphics.h"
#include "of3dGraphics.h"


class BaseParticle
{
public:
    BaseParticle();
    virtual ~BaseParticle();

    virtual void update();
    virtual void draw();

    ofVec3f position;
    ofVec3f lastPosition;
    
    ofVec3f velocity;
    ofVec3f acceleration;

    int age;
    int maxAge;
    bool isDead;

    int* myPointer;

}; // don't forget the semi-colon after your class definition
