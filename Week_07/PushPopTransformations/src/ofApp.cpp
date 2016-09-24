#include "ofApp.h"


//------------------------------------------------------------------------------
void ofApp::setup()
{
    angleDegrees = 0;
    radius = 100;
    scaleX = 1;
    scaleY = 1;
}

//------------------------------------------------------------------------------
void ofApp::update()
{
    angleDegrees += 2;

    scaleX += ofRandom(-1,1);
    scaleY += ofRandom(-1,1);
}

//------------------------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);


    float centerX = ofGetWidth() / 2;
    float centerY = ofGetHeight() / 2;

    ofPushMatrix();
    ofTranslate(centerX,centerY); // create a new origin @ centerX, centerY
    ofEllipse(0,0,10,10);

    ofRotateZDeg(angleDegrees);
    ofLine(0,0,radius,0);

    // this push matrix will inherit the existing transformations
    ofPushMatrix();
    ofTranslate(radius,0);
    ofEllipse(0,0,10,10);

    ofRotateZDeg(angleDegrees);
    ofLine(0,0,radius,0);

    ofPushMatrix();
    ofTranslate(radius,0);
    ofScale(scaleX,scaleY);
    ofEllipse(0,0,10,10);

    ofPopMatrix();

    ofPopMatrix();

    ofPopMatrix();




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
