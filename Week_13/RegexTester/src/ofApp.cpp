#include "ofApp.h"

#include "Poco/RegularExpression.h"


//--------------------------------------------------------------
void ofApp::setup(){

    std::string buffer = "hello \n\n\n\n:\n\n\n\nworld!";

    cout << buffer << endl;

    Poco::RegularExpression regex("[\n:]+");

    std::string output = buffer;

    regex.subst(output,"",Poco::RegularExpression::RE_GLOBAL); // replace with nothing


    cout << output << endl;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
