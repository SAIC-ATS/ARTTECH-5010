#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	samplerate = 44100;
	buffSize = 1024;
	
	ofSoundStreamSettings settings;
	
	settings.setInListener(this);
	settings.setOutListener(this);
	settings.numOutputChannels = 1;
	settings.numInputChannels = 1;
	settings.sampleRate = samplerate;
	settings.bufferSize = buffSize;
	settings.numBuffers = 8;
	
	stream.setup(settings);
	
	fft = ofxFft::create(buffSize, OF_FFT_WINDOW_BARTLETT);
	
	int binSize = fft->getBinSize();
	binBuffer.resize(fft->getBinSize());
	
	for(std::size_t i=0; i < binBuffer.size(); i++) {
		binBuffer[i] = 0;
	}
	
	noiseBuffer.resize(buffSize);
	passBuffer.resize(buffSize);
	audioBinBuffer.resize(buffSize);
	
	fftOutput = new float[fft ->getBinSize()];
	processedOutput = new float[fft ->getBinSize()];
	ifftOutput = new float[buffSize];
	
	ofxLoadSound(song, "AdagioNorm.wav");
	if (ofxLoadSound ) {
		std::cout << "song loaded" << endl;
	}
	
	
	rect.set(200, 200, fft->getBinSize(), 255);
	
	mode = NOISE;
}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	
	soundMutex.lock();
	passBuffer = binBuffer;
	soundMutex.unlock();
	
	ofSetColor(100, 0, 200);
	ofDrawRectangle(rect);
	
	ofPolyline drawBins;

	for (std::size_t i = 0; i < binBuffer.size(); i++) {
		drawBins.addVertex(i,  255 - binBuffer[i] * 255.0);
	}
	
	ofSetColor(200);
	ofPushMatrix();
		ofTranslate(200, 200);
		drawBins.draw();

		ofSetColor(100, 100, 50);
		ofBeginShape();
		for (std::size_t i = 0; i < fft->getBinSize(); i++) {
			ofVertex(i,  255 - processedOutput[i] * 1000);
		}
		ofEndShape();
	ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	switch (key) {
		case 'm':
			mode = MIC;
			break;
			
		case 'n':
			mode = NOISE;
			break;
			
//		case 'm':
//			mode = MIC;
//			break;
			
		case ' ':
			std::fill(binBuffer.begin(), binBuffer.end(), 0);
			break;
		case 'q':
			std::fill(binBuffer.begin(), binBuffer.end(), 1);
			break;
	}

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
	if (rect.inside(x, y)) {
		int bufferIndex = x - 200;
		
		float magnitude = ofMap(y, 200.0, 455.0, 1.0, 0.0, true);
		
		std::cout << magnitude << std::endl;
		binBuffer[bufferIndex] = magnitude;
		
	}

}

//--------------------------------------------------------------

void ofApp::audioIn(ofSoundBuffer &inBuffer) {
	if (mode == MIC) {
		
		for(std::size_t i = 0; i < stream.getBufferSize(); i++) {
			noiseBuffer[i] = inBuffer[i];
		}
		
	} else if (mode == NOISE) {
		
		for (std::size_t i=0; i < noiseBuffer.size(); i++) {
			noiseBuffer[i] = ofRandom(-0.9, 0.9);
		}
	}
	
	fft->setSignal(noiseBuffer);
	std::memcpy(fftOutput, fft->getAmplitude(), sizeof(float) *fft ->getBinSize());
	
	soundMutex.lock();
	audioBinBuffer = passBuffer;
	soundMutex.unlock();
	
	for (std::size_t i = 0; i < fft->getBinSize(); i++) {
		processedOutput[i] = fftOutput[i] * audioBinBuffer[i];
	}
	
	fft->setPolar(processedOutput, fft->getPhase());
	fft-> clampSignal();
	
	std::memcpy(ifftOutput, fft->getSignal(), sizeof(float) *fft->getSignalSize());
	
}

void ofApp::audioOut(ofSoundBuffer &outBuffer) {
	
	outBuffer.copyFrom(ifftOutput, outBuffer.getNumFrames(), 1, 44100);
	//std::memcpy(&outBuffer, fft->getSignal(), sizeof(float) *fft->getSignalSize());
//	for (std::size_t i=0; i < outBuffer.size(); i++) {
//		outBuffer[i] = ifftOutput[i];//ifftOutput[i];
//	}
}


