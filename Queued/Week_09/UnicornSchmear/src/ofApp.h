#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    void keyPressed(int key) override;
    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;

    ofPolyline polyline;

    bool drawVertexIndicies = false;

    std::size_t maxPoints = 100;

    bool useAlphaImage = false;

    ofImage image;
    ofImage alphaImage;
};
