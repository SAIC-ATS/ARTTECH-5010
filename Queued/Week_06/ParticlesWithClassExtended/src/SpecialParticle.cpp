#include "SpecialParticle.h"


SpecialParticle::SpecialParticle()
{
}

SpecialParticle::~SpecialParticle()
{
}

// this is a custom method that draws a yello box instead of a circle
void SpecialParticle::draw()
{
    // we can calculate the heading of the
    // particle by looking at the velocity vector.
    float heading = ofRadToDeg(atan2(velocity.y, velocity.x));

    // we will change the color based on the age
    ofSetColor(255,255,0,ofMap(age,0,maxAge,127,0));
    ofFill();

    // ofPushMatrix + ofTranslate + ofRotateZ ... + ofPopMatrix
    ofPushMatrix();
    ofTranslate(position);
    ofRotateZDeg(heading); // rotate z angle

    // draw the filled circle
    ofDrawRectangle(-20,-20,40,40);

    // draw the outline of the circle
    ofNoFill();
    ofSetColor(255,255,0,ofMap(age,0,maxAge,255,0));
    ofDrawRectangle(-20,-20,40,40);

    // draw a heading line (this is pointing in the right direction
    // because we used ofRotateZ above ...
    ofDrawLine(0,0,20,0);

    // pop the transformation matrix
    ofPopMatrix();
}
