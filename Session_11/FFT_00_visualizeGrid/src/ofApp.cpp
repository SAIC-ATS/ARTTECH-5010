#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(ofGetScreenWidth(), ofGetScreenHeight());
	
	ofBackground(0);
	windowWidth = ofGetWidth();
	
	binSize = 512;			//512 divisions form 0 - sampling rate (44100)
						   // to get the freq of the bin -> (samplingrate/binSize) * index of the bin
						  //this also means our frequency resolution is samplingrate/binSize.
	

	
	//setup the fft using 512 bins
	fft.setup(binSize);
	
	polys.resize(binSize/2);	//although we are using 512 bins, only the first half of the bins are going
								//to be meaningful to us here.
								//the reasons are bit technical (but have to do with the Nyquist frequency & complex numbers).
								// think of the second half of our fft as the dark mirror image of out first half, as 'bizzaro world' fft.
								//in any case, the second half of out fft is thrown out (bins 257- 512)
								//& the results or our fft will only deal with the first half (bins 0-256, 257 values).
	
	std::cout << ofGetWidth() << "/" << ofGetHeight() << std::endl;
	
	fftScale = 128; //
}

//--------------------------------------------------------------
void ofApp::update(){
	
	fft.update();  //all this once per update() loop to update our fft values
	
	fftBuffer = fft.getBins();  // by calling .getBins() returns an array of the magnitudes of each bin.
							   // so, the first value in fft.getBins() is the magnitude of the first bin
							  // every value will be  float betwwen 0 - 1.
							 // what we usually want to do is put the reults of .getBins() into a std::vector
	
	int n = MIN(1024, fftBuffer.size());
	
	for(std::size_t i = 1; i < n; i++) {
		
		float phase =0.0;
		float phaseAddr;
		
		polys[i-1].clear();
		for(std::size_t j = 0; j < windowWidth/2.5; j++) {
			phaseAddr = (TWO_PI * (44100/binSize) * i)/(float)44100; //we need to get the freq that the bin corresponds to
			//to get the freq of the bin -> samplingrate/512 * nbin -> 44100/512 * i
			polys[i-1].addVertex(j, sin(phase) * (fftBuffer[i] * fftScale));	// here is where we stuff out polyline array
																			   // We will make a ploy line for each bin, that will hold the points
																			// of sine wave that is the frequency of that bin.
																		   // the large we draw the sine wave (its y-value) will be determined
																	     //  by the bins magnitude
																		// sice the magnitude will be between 0-1, we scale it (here by 256)
			phase += phaseAddr;
		}
		
		//find the loudest frequency
		//cycle though all the bins and figure out which one as the highest magnitude, store that index
		int binTest = fftBuffer[i];
		int highBin = 0;
		
		if (binTest > highBin) {
			highBin = binTest;
			loudestBin = i;
		}
	}
	
	loudestFreq = (44100/binSize) * loudestBin;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	
	//for laying out the grid. forogt that i set the window to the size of the computer screen
	//so these numbers might not work for you  ..ohwell \_()_/
	int index = 0;
	int xoff = 144;
	int yoff = 64;
	
	for (std::size_t x = 0; x < 10 * xoff; x += xoff) {
		for (std::size_t y = 0; y < 13 * yoff; y += yoff) {
			
			ofPushMatrix();
				ofTranslate(x, y + 30);
				ofScale(0.2, 0.2);
			
				ofSetColor(255, 255, 255, 100);
				polys[index].draw();
			ofPopMatrix();
			index ++;
		}
	}

	ofSetColor(255);
	std::string loudStr = "My Fantastic Frequency= ~" + ofToString(loudestFreq);
	ofDrawBitmapString(loudStr, 200, 710);
	
}


