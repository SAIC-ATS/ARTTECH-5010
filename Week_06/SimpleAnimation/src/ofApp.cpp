#include "ofApp.h"


void ofApp::setup()
{
}


void ofApp::update()
{
    xPosition = xPosition + xVelocity;
    xPosition0 = xPosition0 + xVelocity0;
    xPosition1 = xPosition1 + xVelocity1;
}


void ofApp::draw()
{
    ofBackground(0);
    ofDrawCircle(xPosition, ofGetHeight() * 1 / 3, 20);
    ofDrawCircle(xPosition0, ofGetHeight() * 2 / 3, 20);
    ofDrawCircle(xPosition1, ofGetHeight() * 3 / 3, 20);
}
