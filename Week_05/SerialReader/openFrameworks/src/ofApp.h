#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    ofSerial serial;

    int potValue = 0;

    std::string buffer;

};