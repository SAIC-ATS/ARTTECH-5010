#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void mousePressed(int x, int y, int button);

    float x;
    float y;

    float velocityX;
    float velocityY;

    float accelerationX;
    float accelerationY;
    
};
