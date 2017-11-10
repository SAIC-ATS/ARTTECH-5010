#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	//get a list of out available audio devices
	auto devices = stream.getDeviceList();
	//print it out
	for (int i=0; i< devices.size(); i++) {
		std::cout << devices[i] << std::endl;
	}
	
	//set our sample rate
	sampleRate = 44100;
	
	//setup out sound settings
	ofSoundStreamSettings settings;
	
	//settings.setInListener(this);  //dont need an in listener because we have no audio in
	settings.setOutListener(this);
	settings.numOutputChannels = 2;
	settings.numInputChannels = 0;
	settings.sampleRate = sampleRate;
	settings.bufferSize = 256;
	settings.numBuffers = 4;
	
	//another way to do above but is deprecated
		//soundStreamSetup(int nOutputs, int nInputs, sampleRate, buffersize, nBuffers)
		//ofSoundStreamSetup(2, 0, 44100, 512, 4);
	
	stream.setup(settings);
	
	phase = 0.0;
	freq = 441.0;
}

//--------------------------------------------------------------
void ofApp::update(){
	
	freq = ofMap(ofGetMouseX(), 0, ofGetWidth(), 100.0, 2000.0, true);
	volume = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0.0, 1.0, true);
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0);
	
	string freqString = "Frequency: " + ofToString(freq);
	ofDrawBitmapString(freqString, ofGetWidth()/2, ofGetHeight()/2);
	
	string volString = "Volume: " + ofToString(volume);
	ofDrawBitmapString(volString, ofGetWidth()/2, ofGetHeight()/2+ 24);

}

void ofApp::audioOut( ofSoundBuffer &outBuffer) {
	
	//this sets our phase step, or how much we advance the phase by
	//each time through our loop
	//larger phase steps will give us higher pitches
	
	float phaseStep = (float)(freq*TWO_PI)/(float)sampleRate;
	
	for (std::size_t i = 0; i < outBuffer.size(); i+=2 ) {
		phase += phaseStep;
		
		//sin() has trouble handling large numbers
		//so we will clamp the value of phase to 2Pi (one full rotation)
		while (phase >= TWO_PI) {
			phase -= TWO_PI;  //when phase gets to 2pi, send it back to 0
		}
		
		float sample = sin(phase) * volume;
		outBuffer[i] = sample;
		outBuffer[i+1] = sample;
		
	}
}
//--------------------Thats--It-------------------------------------//
