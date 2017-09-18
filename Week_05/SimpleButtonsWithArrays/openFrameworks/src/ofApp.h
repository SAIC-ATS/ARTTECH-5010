#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    void mousePressed(int x, int y, int button) override;

    std::vector<ofRectangle> buttons;
    std::vector<ofColor> onColors;
    std::vector<ofColor> offColors;
    std::vector<bool> buttonState;

};
