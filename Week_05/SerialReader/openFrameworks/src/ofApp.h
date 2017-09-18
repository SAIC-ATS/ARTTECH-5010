#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    ofSerial serial;

    int potValue = 0;

    std::string buffer;

};