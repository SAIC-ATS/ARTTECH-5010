#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	samplerate = 44100;
	buffSize = 1024;
	
	//setup the soundstrem settings
	ofSoundStreamSettings s;
	s.setOutListener(this);
	s.numOutputChannels = 1;
	s.numInputChannels = 0;
	s.sampleRate = samplerate;
	s.bufferSize = buffSize;//512; //this sets the number of FRAMES in the buffer (not individual samples)
	s.numBuffers = 2;
	
	stream.setup(s);
	
	//This soundBUffer will hold the the sample values that we will pass to our
	//audio buffer (which will be read by our sound card
	//our 'soundbuffer' will be a consistant size of our bufferSize
	soundBuffer.resize(buffSize);
	
	//fill it with zeros to initialize
	for( int i = 0; i < soundBuffer.size(); i++) {
		soundBuffer[i] = 0.0;
	}

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	
	ofFill();
	ofSetColor(0,100, 200);
	ofDrawRectangle(200, 200, 512, 256);
	
	//draw the middle line
	ofSetColor(25);
	ofDrawLine(200, 200 + 128, 200+512, 200+ 128);
	
	//draw out the soundBuffer to the screen
	ofPolyline wave;
	ofNoFill();
	ofSetColor(200);
	for (int i = 0; i < soundBuffer.size(); i+=2) {
		wave.addVertex(i/2, soundBuffer[i]*128);
	}
	
	ofPushMatrix();
		ofTranslate(200, 200 + 128);
		wave.draw();
	ofPopMatrix();
	

}

//--------------------------------------------------------------

void ofApp::drawSine(float m) {
	
	float phase = 0.0;
	float add = TWO_PI/(float)soundBuffer.size();
	
	for (std::size_t i = 0; i < soundBuffer.size(); i++) {
		soundBuffer[i] = sin(phase);
		phase += add * m;
	}
}

void ofApp::drawTriangle(float m) {
	
	float phase = TWO_PI/4;
	float add = TWO_PI/(float)soundBuffer.size();
	
	for (std::size_t i = 0; i < soundBuffer.size(); i++) {
		float index = phase/TWO_PI;
		float point = index < 0.5 ? ofMap(index, 0, 0.5, -1, 1) : ofMap(index, 0.5, 1.0, 1, -1);
		
		soundBuffer[i] = point;
		
		phase += add * m;
		if( phase > TWO_PI ) phase = 0.0;
	}
}

void ofApp::drawRSaw(float m) {
	float phase = 0.0;
	float add = TWO_PI/(float)soundBuffer.size();
	
	for(std::size_t i =0; i < soundBuffer.size(); i++) {
		float index = phase/TWO_PI;
		float point = ofMap(index, 0, 1, -1, 1);
		
		soundBuffer[i] = point;
		phase += add * m;
		if( phase > TWO_PI ) phase = 0.0;
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
	if (x>=200 && x<712 && y >= 200 && y <= 456) {
		
		//int bufferIndex = x - 200; if I'm not interpolating use this
		int bufferIndex = (x - 200) * 2;
		
		float sample = ofMap(y, 200.0, 456.0, -1.0, 1.0, true);
		float sample32 = ofLerp(sample, soundBuffer[bufferIndex+2], 0.5);
		
		soundBuffer[bufferIndex] = sample;
		soundBuffer[bufferIndex + 1] = sample32;
		
		std::cout << sample << " " << sample32 << std::endl;
		
	}
}

void ofApp::audioOut(ofSoundBuffer &outBuffer) {
	
	for (std::size_t i = 0; i < outBuffer.size(); i++) {
		
		outBuffer[i] = soundBuffer[i];
	}
}
//----
void ofApp::keyPressed(int key){
	
	float mult = 1.0;
	
	switch (key) {
		case ' ':
			for(std::size_t i = 0; i < soundBuffer.size(); i++) {
				soundBuffer[i] = 0.0;
			}
			break;
		case '/':
			for (std::size_t i = 0; i < soundBuffer.size(); i++) {
				soundBuffer[i] = ofRandom(-1.0, 1.0);
			}
			break;
// sine-- brute force here
		case 'q':
			mult = 1;
			drawSine(mult);
			break;
			
		case 'w':
			mult = 2;
			drawSine(mult);
			break;
			
		case 'e':
			mult = 3;
			drawSine(mult);
			break;
			
		case 'r':
			mult = 4;
			drawSine(mult);
			break;
			
		case 't':
			mult = 5;
			drawSine(mult);
			break;
			
		case 'y':
			mult = 6;
			drawSine(mult);
			break;
			
//triangle
		case 'a':
			mult = 1;
			drawTriangle(mult);
			break;
			
		case 's':
			mult = 2;
			drawTriangle(mult);
			break;
			
		case 'd':
			mult = 3;
			drawTriangle(mult);
			break;
			
		case 'f':
			mult = 4;
			drawTriangle(mult);
			break;
			
		case 'g':
			mult = 5;
			drawTriangle(mult);
			break;
			
		case 'h':
			mult = 6;
			drawTriangle(mult);
			break;
//reverse saw
		case 'z':
			mult = 1;
			drawRSaw(mult);
			break;
		case 'x':
			mult = 2;
			drawRSaw(mult);
			break;
		case 'c':
			mult = 3;
			drawRSaw(mult);
			break;
		case 'v':
			mult = 4;
			drawRSaw(mult);
			break;
		case 'b':
			mult = 5;
			drawRSaw(mult);
			break;
		case 'n':
			mult = 6;
			drawRSaw(mult);
			break;
		case 'm':
			mult = 7;
			drawRSaw(mult);
			break;
	}
}
