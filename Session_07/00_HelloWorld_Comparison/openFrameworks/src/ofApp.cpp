#include "ofApp.h"


void ofApp::setup()
{
    // set our refresh / frame rate to 1 frame / second.
    ofSetFrameRate(1);
}


void ofApp::draw()
{
    // set the background to black
    ofBackground(0);

    // tell the program that the next `ofSetColor` will set the FILL color
    ofFill();

    if(isOn)
    {
        // set the color to yellow if `isOn` is TRUE
        ofSetColor(255, 255, 0);
    }
    else
    {
        // set the color to red if `isOn` is FALSE
        ofSetColor(255, 0, 0);
    }

    ofDrawCircle(200,200,100); // draw a circle at x = 200, y = 200 with a radius of 100 pixels.

    // toggle `isOn`.  In this case, "!" means "not".
    // So this can be read: isOn is equal to the opposite of what it is currently equal to.
    isOn = !isOn;
}
