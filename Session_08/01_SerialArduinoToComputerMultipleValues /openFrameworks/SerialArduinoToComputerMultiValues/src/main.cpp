#include "ofApp.h"


int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    return ofRunApp(std::make_shared<ofApp>());
}

