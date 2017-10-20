#include "ofApp.h"


void ofApp::draw()
{
    // Update the xPosition.
    xPosition = xPosition + 1;

    // When the xPosition gets too big, we reset it to zero.
    if (xPosition > ofGetWidth())
    {
        xPosition = 0;
    }

    // Drawing below!

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
