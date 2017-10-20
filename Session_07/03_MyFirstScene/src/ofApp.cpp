#include "ofApp.h"


void ofApp::setup()
{
    ofSetCircleResolution(60);

    cricketsSound.load("crickets.mp3");
    cricketsSound.setLoop(true);
    cricketsSound.play();

    owlSound.load("owl.mp3");
}


void ofApp::draw()
{
    uint64_t now = ofGetElapsedTimeMillis();

    if (now > nextOwlHoot)
    {
        owlSound.play();
        nextOwlHoot = now + ofRandom(10000, 15000);
    }

    // Create a vertical gradient.
    for (int y = 0; y < ofGetHeight(); y++)
    {
        float blue = ofMap(y, 0, ofGetHeight(), 0, 255);
        ofSetColor(0, 0, blue);
        ofDrawLine(0, y, ofGetWidth(), y);
    }

    float middleX = ofGetWidth() / 2;
    float middleY = ofGetHeight() / 2;
    float radius = 200;

    ofSetColor(255, 255, 0);
    ofFill();
    ofDrawCircle(middleX, middleY, 200);

    float blurRadius = radius + 10 + std::abs(sin(ofGetElapsedTimef() / 4)) * 20;

    // Create a circular gradient with the alpha values.
    for (int r = radius; r < blurRadius; r++)
    {
        float alpha = ofMap(r, radius, blurRadius, 255, 0);
        ofSetColor(255, 255, 0, alpha);
        ofNoFill();
        ofDrawCircle(middleX, middleY, r);
    }

    float mx = ofGetMouseX();
    float my = ofGetMouseY();

    if (ofGetMousePressed())
    {
        for (int i = 0; i < 10; i++)
        {
            if (i % 2 == 0)
            {
                // i is even
                ofFill();
                ofSetColor(0, 0, 0);
            }
            else
            {
                // i is odd
                ofNoFill();
                ofSetColor(255, 0, 0);
            }

            ofDrawRectangle(mx + (i * 10), my + (i * 10), 30, 50);
        }
    }
}
