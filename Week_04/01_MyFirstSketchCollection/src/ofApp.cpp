#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

    myPositions = { 0, 0, 0, 0, 0 };
    myIncrements = { 1, 2, 3, 4, 5};
}

//--------------------------------------------------------------
void ofApp::update(){

    for (std::size_t i = 0; i < myPositions.size(); i++)
    {
        myPositions[i] = myPositions[i] + myIncrements[i];

        if (myPositions[i] > ofGetWidth())
        {
            myPositions[i] = 0;
        }

    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

    for (float position: myPositions)
    {
        ofDrawEllipse(position, 20, 20, 20);
    }
}





















