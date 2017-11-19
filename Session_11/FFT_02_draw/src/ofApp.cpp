#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	fft.setup();  //initilize our fft
	myFreqLevels.resize(12);
}

//--------------------------------------------------------------
void ofApp::update() {
	
	fft.update();  //call this once every draw loop
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0);
	
	for (std::size_t i = 0; i < 12; i++) {
		float whichFrequency = 100 * (i + 1);
		myFreqLevels[i] = fft.getIntensityAtFrequency(whichFrequency);  //getting the intensity
																	   // at 12 frequencies starting 100hz
																	  // and storing those intensities in avector
	}
	
	//try getting another value from out fft analiysis. Things to try ---
	// float getLoudBand();  //gets the loudest frequency band (the loudest bin)
	// float getSuperLowVal(); //
	// float getLowVal();
	// float getMidVal();
	// float getHighVal();
	
	// float getNoisiness(); //not currently implemented
	// bool  getNormalized();
	// float getSpectralCentroid(); //this is not currently implemented
	
	// float getDelta();
	// float getUnScaledLoudestValue();
	// float getSmoothedUnScaledLoudestValue();
	//Take a look the ofxProcessFft.h and ofxProcess.cpp files for more info
	
	
	//lets use those frequency levels to draw some circles to the screen
	for (std::size_t i = 0; i < myFreqLevels.size(); i++) {
		
		ofSetColor(255, 0, 255 - (myFreqLevels[i]*255, 100));
		ofPushMatrix();
			ofTranslate(200, 0); //is everything centered? I'm not sure, but tis close
			ofDrawCircle(50 * (i+1), ofGetHeight()/2, ofClamp(myFreqLevels[i] * 500, 0, 300));
		ofPopMatrix();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}


