#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	windowWidth = ofGetWidth();
	
	binSize = 512;      //512 divisions form 0 - sampling rate (44100)
											// to get the freq of the bin -> (samplingrate/binSize) * index of the bin
											//this also means our frequency resolution is samplingrate/binSize.
	//setup the fft using 512 bins
	fft.setup(binSize);
	
	polys.resize(binSize/2 + 1);  //although we are using 512 bins, only the first half of the bins are going to be meaningful to us here.
								  //the reasons are bit technical (but have to do with the Nyquist frequency).
								 // think of the second half of our fft as the dark mirror image of out first half, as 'bizzaro world' fft.
								//in any case, the second half of out fft is thrown out (bins 257- 512)
								//& the results or our fft will only deal with the first half (bins 0-256, 257 values).
	
	fftMagnitudeScale = 256;
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	fft.update();
	
	fftBufferV = fft.getBins();	 // plot the results of our fft. by calling .getBins() returns an array of the magnitudes of each bin.
								// so, the first value in fft.getBins() is the magnitude of the first bin
							   // every value will be  float betwwen 0 - 1.
							  // what we usually want to do is put the reults of .getBins() into a std::vector
	
	int n = MIN(1024, fftBufferV.size());
	
	for(std::size_t i = 0; i < n; i++) {  //iterate through our fftBuffer
		
		float phase =0.0;  //I'm going to use a sine wave to create verticies for out polylines
		float phaseAddr;
		
		polys[i].clear(); //clear all the polylines verticies
		
		for(std::size_t j = 0; j < windowWidth; j++) {  //time to create the verticies. we will add a vertex from 0-windowWidth and set our x-value
			phaseAddr = (TWO_PI * (44100/binSize) * i)/(float)44100; //we need to get the freq that the bin corresponds to
																	//to get the freq of the bin -> samplingrate/binsize * nbin
																   // 44100/512 * i
			
			polys[i].addVertex(j, sin(phase) * (fftBufferV[i] * fftMagnitudeScale)); // here is where we stuff out polyline array
																			     // We will make a ploy line for each bin, that will hold the points
																				// of sine wave that is the frequency of that bin.
																			   // the large we draw the sine wave (its y-value) will be determined
																			  //  by the bins magnitude
																			 // sice the magnitude will be between 0-1, we scale it (here by 256)
			phase += phaseAddr;
		}
		
		//find the loudest frequency
		//cycle though all the bins and figure out which one has the highest magnitude, store that index
		int binTest =fftBufferV[i];
		int highBin = 0;
		
		if (binTest > highBin) {
			highBin = binTest;
			loudestBin = i;
		}					//this will actuallt find only the loudest bin closest to bin 0.
		
	}
	
	loudest = (44100/binSize) * loudestBin;  //what the frequency of the loudest bin.
	
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	
	ofPushMatrix();
		ofTranslate(0,ofGetHeight()/2);
		for (std::size_t i  = 0; i < polys.size(); i++) {  //iterate through our polyline array and draw it to the screen
			
			if( i == loudestBin) {
				//i want to draw that loudest bin blue
				ofSetColor(50, 100, 255, 200);
				polys[i].draw();
			} else if ( i >= 1 ){
				//i want to draw other polylines as purple
				ofSetColor(255, 100, 255, 100);
				polys[i].draw();
			} else {
				//the only thing that is left is the polyline for bin 0, which is for frequency 0, which will most likely just remain at 0 magnitude
				//so it will be a straight line... forever.  a nice grid line
				ofSetColor(255, 255, 255, 200);
				polys[i].draw();
			}
		}
	ofPopMatrix();
	
	//Still, there are going to be 256 polylines drawn on top of eachother, so its going to look like a beautiful mess.
	//try changing the binSize variable to see what happens
	//use a power of two though!! ie 128, 256, 512, 1024
	
	//print that loudest frequency
	ofSetColor(255);
	std::string loudStr = "my Fantastic Frequency= ~" + ofToString(loudest);
	ofDrawBitmapString(loudStr, 200, 700);

}

void ofApp::keyPressed(int key){

}
