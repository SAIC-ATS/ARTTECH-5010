#include "Particle.h"


void Particle::update()
{
    // Update velocities.
    xVelocity = xVelocity + xAcceleration;
    yVelocity = yVelocity + yAcceleration;

    // Modify velocity by the drag.
//    xVelocity = xVelocity * (1 - drag);
//    yVelocity = yVelocity * (1 - drag);

    // Update positions.
    xPosition = xPosition + xVelocity;
    yPosition = yPosition + yVelocity;

    // Update the age.
    age++;

//    if (xPosition > ofGetWidth())
//    {
//        xPosition = ofGetWidth();
//        xVelocity = xVelocity * -1.0;
//    }
//
//    if (xPosition < 0)
//    {
//        xPosition = 0;
//        xVelocity = xVelocity * -1.0;
//    }

    if (yPosition < -100 or yPosition > ofGetHeight() + 100 or xPosition < - 100 || xPosition > ofGetWidth() + 100)
    {
        reset();
    }
}


void Particle::draw()
{
    float scale = ofMap(age, 0, 100, 0, 2, true);
    float alpha = ofMap(age, 0, 100, 75, 0, true);

    ofColor tint;

    if (yAcceleration > 0)
    {
        tint = ofColor(ofColor::lightBlue, alpha);
    }
    else
    {
        tint = ofColor(alpha);
    }

    ofPushStyle();
    ofSetColor(tint);

    ofPushMatrix();
    ofTranslate(xPosition, yPosition);
    ofRotate(rotation);
    ofScale(scale, scale);
    texture.draw(-texture.getWidth() / 2,
                 -texture.getHeight() / 2);
    ofPopMatrix();

    ofPopStyle();
}


void Particle::reset()
{
    rotation = ofRandom(0, 360);

    xPosition = ofGetMouseX() + ofRandom(-30, 30);
    yPosition = ofGetMouseY();

    xVelocity = ofRandom(-3, 3);
    yVelocity = ofRandom(-2, 2);

    float randomNumber = ofRandom(1);

    if (randomNumber > 0.4)
    {
        yAcceleration = 0.05;
    }
    else
    {
        yAcceleration = -0.08;
    }

    drag = 0.1;
    age = 0;
}




















