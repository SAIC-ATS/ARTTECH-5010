#include "ofApp.h"


void ofApp::setup()
{
    // Load the image into pixels.
    ofLoadImage(myPixels, "puppy.jpeg");

    // Uploading the raw, uncompressed pixels to the graphics card (as a texture).
    myTexture.loadData(myPixels);

}


void ofApp::update()
{
    angle += 1;
}


void ofApp::draw()
{
    ofPushMatrix();
    ofTranslate(100, 100);
    ofRotate(angle);

    myTexture.draw(-myTexture.getWidth() / 2,
                   -myTexture.getHeight() / 2);

    ofPopMatrix();

}
