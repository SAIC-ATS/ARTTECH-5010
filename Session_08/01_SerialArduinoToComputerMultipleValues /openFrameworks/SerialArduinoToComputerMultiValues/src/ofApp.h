#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    // An instance of the serial object. One instance is needed for each active
    // serial connection.
    ofSerial serial;

    // A buffer to store our buffered data.
    std::string buffer;
    
    // The value of the potentiometer.
    int potValue = 0;

    // The value of the first button.
    bool buttonValue_0 = false;
    
    // The value of the second button.
    bool buttonValue_1 = false;
    
};
