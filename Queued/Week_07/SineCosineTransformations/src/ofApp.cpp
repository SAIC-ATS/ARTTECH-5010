#include "ofApp.h"


//------------------------------------------------------------------------------
void ofApp::setup()
{
    angleDegrees = 0;
    radius = 100;
}

//------------------------------------------------------------------------------
void ofApp::update()
{
    angleDegrees += 2;

    radius -= 1;

    if(radius < 0) {
        radius = 100;
    }
}

//------------------------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);

    float centerX = ofGetWidth() / 2;
    float centerY = ofGetHeight() / 2;

    ofEllipse(centerX,centerY,10,10);

    float angleRadians = ofDegToRad(angleDegrees);

    // SOH (where opposite == Y and H is our radius)
    // sin(angleRadians) == Y / radius
    // Y = radius * sin(angleRadians)

    float otherY = radius * sin(angleRadians) + centerY;

    // CAH (where adjacent == X and H is our radius)
    // cos(angleRadians) == X / radius
    // X = radius * cos(angleRadians)

    float otherX = radius * cos(angleRadians) + centerX;


    ofLine(centerX,centerY,otherX,otherY);

    ofEllipse(otherX,otherY,10,10);

}

//------------------------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//------------------------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//------------------------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//------------------------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//------------------------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//------------------------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//------------------------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//------------------------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//------------------------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
