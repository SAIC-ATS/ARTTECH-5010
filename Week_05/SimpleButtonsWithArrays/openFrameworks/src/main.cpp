#include "ofApp.h"

int main()
{
	ofSetupOpenGL(340, 130, OF_WINDOW);
	return ofRunApp(std::make_shared<ofApp>());
}
