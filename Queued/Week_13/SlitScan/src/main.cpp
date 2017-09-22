#line 1 "SlitScan"

#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:

#line 1 "SlitScan"
ofVideoGrabber grabber; // The camera we'll use.

ofPixels pixels; // Collect slits from the camera and accumulate them side by side in pixels.

int xPosition = 0; // The current x position of the slits in our pixels.

// Set up our sketch.
void setup() 
{
    ofSetWindowShape(1280, 720);  // Set the window size.
    grabber.initGrabber(1280, 720); // Set the grabber size.
    pixels.allocate(1280, 720, OF_PIXELS_RGB);	// Allocate memory for our pixels.
}


// Called every frame.
void update() {
    // Update our camera.
    grabber.update();
    
    // If the camera has a new frame to offer us ...
    if (grabber.isFrameNew())
    {
        // Get a reference (denoted by &) to the camera's pixels. Getting a 
        // reference means that we won't have to make a copy of all of the 
        // frame's pixels (since we only need one column anyway). This means our
        // program requires less processing power.
        //
        // const prevents us from accidentally modifying the cameras's pixels.
        const ofPixels& cameraPixels = grabber.getPixelsRef();
        
        // Choose a slit location. In this case we'll collect slits from the 
        // column in the middle of the camera feed.
        int slitPositionX = grabber.getWidth() / 2;
        
        // Cycle through each pixel in the selected column and place that pixel
        // at a position x = xPosition and y = to the same position as the 
        // oritinal.
        for (int y = 0; y < grabber.getHeight(); y++)
        {
            // Get the pixel as a color at x / y from the grabber.
            ofColor pixelFromGrabber = cameraPixels.getColor(slitPositionX, y);
            
            // Set that pixel color to the x / y position in the output pixels.
            pixels.setColor(xPosition, y, pixelFromGrabber);
        }
        
        // Increment our xPosition so next update we'll draw a colum shifted to 
        // the right by one pixel.
        xPosition = xPosition + 1;
        
        // If our xPosition is greater than or equal to the width of the display 
        // pixels, reset our x position to 0.
        if (xPosition >= pixels.getWidth())
        {
            xPosition = 0;   
        }
    }
}


// Draw it!
void draw() 
{
    // We must load our pixels into a texture to be displayed by the GPU.
    ofTexture texture;
    texture.loadData(pixels);
    
    // Draw the pixels on the graphics card.
    texture.draw(0, 0);
}


};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}

