#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	
	//really, ofSoundPlayer is a set of classes for CONTROLING the playback of sound
	
	//load the sound samples
	leftSound.load("DrumnBass.wav");
	rightSound.load("AdagioNorm.wav");
	
	if (leftSound.isLoaded() && rightSound.isLoaded()) {
		std::cout << "Files Loaded" << std::endl;
	}
	
	//set Pan: is bewtween -1(left) and 1 (right). 0 is center.
	leftSound.setPan(-1.0f);
	rightSound.setPan(1.0f);
	
	//play the right sound right away
	rightSound.play();
	
	//setup the GUI
	gui.setup();
	gui.add(leftVolume.set("Left Volume", 0.75f, 0.0f, 1.0f));
	gui.add(rightVolume.set("Right Volume", 0.75f, 0.0f, 1.0f));
	
	gui.add(leftSpeed.set("Left Speed", 1.0f, -1.0f, 2.0f));
	gui.add(rightSpeed.set("Right Speed", 1.0f, -1.0f, 2.0f));
	gui.add(playSounds.set("Play/Stop", false));
	
}

//--------------------------------------------------------------
void ofApp::update() {
	
	//It we have our "play/stop" button checked thenplay the sounds
	if ( playSounds ) {
		
		if(!leftSound.isPlaying()) {
			leftSound.play();
		}
	} else {
		if (leftSound.isPlaying()) {
			leftSound.stop();
		}
	}
	
	leftSound.setVolume(leftVolume);
	leftSound.setSpeed(leftSpeed);
	
	rightSound.setVolume(rightVolume);
	rightSound.setSpeed(rightSpeed);
	
	//this updates the sound players and needs to be called un update()
	ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	
	//draw a little rectangle where the fun happens
	ofSetColor(0, 200, 100);
	ofDrawRectangle(200, 200, 500, 400);
	
	gui.draw();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
	//If you drag in the green rectangle, then change the play position
	//of the right sound
	if (x > 200 && x < 700 && y > 200 && y < 600 ) {
		
		float prevPlayPosition = rightSound.getPosition();
		float playPosition = ofMap(x, 200, 700, 0.0, 1.0);
		rightSound.setPosition(playPosition);
		
	}

}

//------------------------Thats-it--------------------------------------

