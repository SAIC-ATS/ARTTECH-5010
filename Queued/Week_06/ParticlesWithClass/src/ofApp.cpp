#include "ofApp.h"


void ofApp::setup()
{

//    myFirstParticle.position.x = 100;
//    myFirstParticle.position.y = 100;
//
//    myFirstParticle.velocity.x = 2;
//    myFirstParticle.velocity.y = 2;
//
//    mySecondParticle.position.x = 500;
//    mySecondParticle.position.y = 100;
//
//    mySecondParticle.velocity.x = -2;
//    mySecondParticle.velocity.y = 2;

    int numParticles = 500;

    for (int i = 0; i < numParticles; i++)
    {
        BaseParticle particle;

        particle.position.x = ofGetWidth() / 2;//ofRandom(0,ofGetWidth());  // random x position
        particle.position.y = ofGetHeight() / 2;//ofRandom(0,ofGetHeight()); // random y position

        particle.velocity.x = ofRandom(-5, 5);  // random x velocity
        particle.velocity.y = ofRandom(-5);  // random y velocity

        particle.acceleration.y = .4;

        myParticles.push_back(particle); // add it to our vector
    }


}


void ofApp::update()
{
//    myFirstParticle.update();
//    mySecondParticle.update();

    for(int i = 0; i < myParticles.size(); i++)
    {
        myParticles[i].update();
    }

}


void ofApp::draw()
{
    ofBackground(0);

//    myFirstParticle.draw();
//    mySecondParticle.draw();

    for (int i = 0; i < myParticles.size(); i++)
    {
        myParticles[i].draw();
    }

}
