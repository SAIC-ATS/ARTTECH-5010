#pragma once

#include "ofMain.h"

class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void readSerialData();


    void writeSerialData();

    ofSerial mySerial;

    // Our input buffer.
    std::string buffer;

    // The value of the potentiometer.
    int potValue = 0;

};
