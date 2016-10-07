#include "ofApp.h"


void ofApp::setup()
{
	mySerial.setup(0, 9600);
    // mySerial.setup("/dev/tty.usbmodem620711", 9600);
}


void ofApp::update() {
    readSerialData();
    writeSerialData();
}


void ofApp::draw()
{
}


void ofApp::readSerialData()
{
   	while (mySerial.available() > 0)
	{
	    int myByte = mySerial.readByte(); // Read the byte.
            
        if (myByte != '\n') // End of line character.
        {
            // If it's not the end of the line character. 
    	    buffer += (char)myByte;
        }
        else 
        {
            // Do something with our buffer.
            // In cases where there are several values seperated by commas
            // (for instance), you would parse them seperately using 
            // std::vector<std::string> tokens = ofSplitString(buffer).
            //
            // Then, depending on how many tokens you have, you would convert 
            // them to integers or floats, etc using ofToInt / ofToFloat, etc
            // and assign them to your variables.
            potValue = ofToInt(buffer); 
            
            // Clear the buffer!            
            buffer = "";
        }
	} 
}


void ofApp::writeSerialData()
{
	// Map the pot value to brightness.
	int brightness = ofMap(potValue, 0, 1023, 0, 255);
	
	// Set the background color.
	ofBackground(brightness);
	
    int ledValue = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255);
    
    std::string outBuffer = ofToString(ledValue);
    outBuffer += '\n';

    mySerial.writeBytes((unsigned char*)outBuffer.data(), outBuffer.length());
}
