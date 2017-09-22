#include "ofApp.h"


void ofApp::setup()
{
}


void ofApp::update()
{
    xPosition = xPosition + 1;

    if (xPosition > ofGetWidth())
    {
        xPosition = 0;
    }
}


void ofApp::draw()
{
    ofBackground(0);

    ofSetColor(255, 255, 0);
    ofDrawEllipse(xPosition, 20, 20, 20);

    int xMouse = ofGetMouseX();
    int yMouse = ofGetMouseY();

    if (ofGetMousePressed() == true)
    {
        ofSetColor(255, 0, 0);
    }
    else
    {
        ofSetColor(0, 255, 0);
    }

    ofDrawEllipse(xMouse, yMouse, 20, 20);

}
