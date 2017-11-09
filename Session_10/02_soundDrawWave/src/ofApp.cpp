#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//setup our audio
	sampleRate = 44100;
	
	ofSoundStreamSettings settings;

	settings.setOutListener(this);
	settings.numOutputChannels = 2;
	settings.numInputChannels = 0;
	settings.sampleRate = sampleRate;
	settings.bufferSize = 512;
	settings.numBuffers = 4;
	
	stream.setup(settings);
	phase = 0.0;
	
	soundBuffer.resize(512);
	
	for (std::size_t i = 0; i < soundBuffer.size(); i++) {
		soundBuffer[i] = 0;
	}
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	
	ofFill();
	ofSetColor(200, 50, 50);
	ofDrawRectangle(200, 200, 512, 200);
	
	ofNoFill();
	ofSetColor(200);
	ofBeginShape();
	for (std::size_t i = 0; i < soundBuffer.size(); i++) {
		ofVertex(200 + i, 300 + 100 * soundBuffer[i]);
	}
	ofEndShape();
	
	string freqStr = "Frequency: " + ofToString(freq);
	ofDrawBitmapString(freqStr, 100, 100);
	
	string volStr = "Volume: " + ofToString(vol);
	ofDrawBitmapString(volStr, 100, 120);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------

void ofApp::audioOut(ofSoundBuffer &outBuffer) {
	
	for (std::size_t i = 0; i < outBuffer.size(); i +=2) {
		
		float frequency = ofMap(mouseY, 0, ofGetHeight(), 20.0, 2000.0, true);
		float volume = ofMap(mouseX, 0, ofGetWidth(), 0.0, 1.0, true);
		float phaseStep = (float)(frequency * TWO_PI)/(float)sampleRate;
		
		float sample = sin(phase) * volume;
			//test with white noise!
		//float sample = ofRandom(-1, 1) * volume;
		
		outBuffer[i] = sample;
		outBuffer[i + 1] = sample;
		soundBuffer[i] = sample;
		
		freq = frequency;
		vol = volume;
		
		phase += phaseStep;
		while (phase >= TWO_PI) phase -= TWO_PI;
	}
	
}
