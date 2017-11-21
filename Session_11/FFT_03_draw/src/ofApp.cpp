#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	//number of bind we will get from our fft
	nBins = 1024;
	
	//load a sound file into our player
	player.load("Sud1.mp3");
	
	if (player.isLoaded()) {
		std::cout << "player has loaded the file!" << std::endl;
	}
	
	//We will set the song to loop, play it, but set it to PAUSE right away
	player.setLoop(true);
	player.play();
	player.setPaused(true);
	
	//our fft valuse will be changing drastially every frame
	//so we need to smooth out the transitions
	smoothedFft = new float [nBins];
	for (int i= 0; i < nBins; i++) {
		smoothedFft[i] = 0;
	}
	
	//we can't use .isPlaying() to check if our file is playing
	//because technically a paused track is still playing
	//so we create out own check to see if our file is paused
	isPaused = true;
	
	//used for spinning out fft plot
	phase = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	
	//gets called once per update() loop
	ofSoundUpdate();
	
	//lets get the fft of our track
	//ofSoundGetSpectrum will do an fft on the ENTIRE audio out, not on individual tracks/files
	//so if  you have two tracks playing, you would be doing an fft on both
	float * fft = ofSoundGetSpectrum(nBins);
	for (int i =0; i < nBins; i++) {
		smoothedFft[i] *= 0.6;				 //we will interate through our raw fft arrray
										    //and compare it to out smoothedFft values
		if (smoothedFft[i] < fft[i]) {	   //if the raw fft is greater than we will use that value
			smoothedFft[i] = fft[i];	  //it not, then we will use the smoothed value which is
		}								 //decrimenting to 0
	}									//thi s'smoothing' technique is used in the
}								 	   // sound/fft example in the openFrameworks examples folder

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofBackgroundGradient(ofColor(40, 35, 30), ofColor(0, 0, 0), OF_GRADIENT_CIRCULAR);
	
	//for ploting the position of each individual band
	float rotation = 360/((float)nBins/2);
	
	ofSetColor(200, 255, 0);
	//we'll pick up and move the whole plot to the center of the screen
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	
	//lets rotate the whole plot by the running phase amount
	// to make the whole thing spin... because spinning is cool
	ofRotate(phase % 360);
	
	for (std::size_t i=0; i < nBins/2; ++i) {
		
		ofRotate(rotation);
		ofDrawRectangle(100, 0, smoothedFft[i]* 600, 5);
	}
	
	phase += 1;
	while (phase > 360) phase -= 360;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	switch (key) {
		case ' ':
			isPaused = !isPaused;
			
			if (isPaused) {
				player.setPaused(true);
				std::cout <<"Paused" << std::endl;
			} else {
				player.setPaused(false);
				std::cout <<"Play" << std::endl;
			}
		break;
			
	}

}

