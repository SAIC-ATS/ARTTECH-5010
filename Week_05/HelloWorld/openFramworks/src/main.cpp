#include "ofApp.h"

// main.cpp is the entry point for the application.

int main()
{
	ofSetupOpenGL(1024, 768, OF_WINDOW); // you can set your initial window size here.
	return ofRunApp(std::make_shared<ofApp>());
}
