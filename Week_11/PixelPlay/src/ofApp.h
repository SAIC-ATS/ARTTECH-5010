#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    ofPixels myPixels;
    ofTexture myTexture;

    float angle = 0;

    // ofImage = ofPixels + ofTexture

};
