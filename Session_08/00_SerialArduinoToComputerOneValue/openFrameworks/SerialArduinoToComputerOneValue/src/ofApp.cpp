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
            // Since we are only receiving one value, we simply pass the entire
            // buffer to the ofToInt function.
            int tempValue = ofToInt(buffer);
            
            // Here we check to make sure that our parsed value is a reasonable
            // value that we expect. If it is not a reasonable value, then we
            // won't set use it and will simply move on.
            if (tempValue >= 0 and tempValue < 1024)
            {
                potValue = tempValue;
            }

            // Whether or not we used the data from the buffer, the buffer
            // must be cleared.
            buffer = "";
        }
        else
        {
            // If it's not the line feed character, add it to the buffer.
            buffer += b;
        }
    }
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
    
}
