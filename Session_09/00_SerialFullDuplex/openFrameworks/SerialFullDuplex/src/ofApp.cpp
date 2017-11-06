#include "ofApp.h"


void ofApp::setup()
{
    // Choosing '0' here will connect to the first available serial device.
    // It is recommended to connect to a specific device to avoid problems, e.g.
    //
    // serial.setup("/dev/tty.usbmodem620711", 9600);
    //
    // You can list available devices like this.
    //
    // for (auto device: serial.getDeviceList())
    // {
    //      std::cout << "Device: " << device.getDeviceID() << ": " << device.getDevicePath() << std::endl;
    // }
    //
    // For now, chosing '0' is a good place to start.
    
    serial.setup(0, 9600);
}


void ofApp::update()
{
    // As long as there is serial data available to read, repeat.
    while (serial.available() > 0)
    {
        // Read the byte.
        char b = serial.readByte();
        
        // End of line character.
        if (b == '\n')
        {
            // Split the buffer on the commas.
            std::vector<std::string> tokens = ofSplitString(buffer, ",");
            
            // The number of tokens in our packet is 3, here we check to make
            // sure that our packet is correctly formed.
            if (tokens.size() == 3)
            {
                potValue = ofToInt(tokens[0]);
                buttonValue_0 = ofToBool(tokens[1]);
                buttonValue_1 = ofToBool(tokens[2]);
            }
            
            // Clear the buffer.
            buffer.clear();
        }
        else
        {
            // If it's not the line feed character, add it to the buffer.
            buffer += b;
        }
    }
    
    // Create some LED values to send.
    ledValue_0 = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);
    ledValue_1 = ofMap(std::sin(ofGetElapsedTimef()), -1, 1, 0, 255);
    ledValue_2 = ofMap(std::cos(ofGetElapsedTimef()), -1, 1, 0, 255);

    // Send our LED values.
    std::string writeBuffer;
    
    // Collect our buffer to send.
    writeBuffer += ofToString(ledValue_0);
    writeBuffer += ",";
    writeBuffer += ofToString(ledValue_1);
    writeBuffer += ",";
    writeBuffer += ofToString(ledValue_1);
    writeBuffer += "\n";
    
    serial.writeBytes(writeBuffer.data(), writeBuffer.size());
    
}


void ofApp::draw()
{
    // The potentiometer values range from 0 - 1023.
    // We mape these from 0 - 255, which is a valid grayscale range.
    //
    // This will always use the last valid `potValue` that we received from
    // the Arduino.
    int color = ofMap(potValue, 0, 1023, 0, 255);
    
    // Draw a background color that corresponds to the potentiometer.
    ofBackground(color);
    
    ofSetColor(ofColor::yellow);
    ofFill();
    
    if (buttonValue_0 != true)
    {
        ofDrawRectangle(0, 0, ofGetWidth() / 2, ofGetHeight());
    }
    
    ofSetColor(ofColor::green);
    ofFill();

    if (buttonValue_1 != true)
    {
        ofDrawRectangle(ofGetWidth() / 2, 0, ofGetWidth() / 2, ofGetHeight());
    }
}
