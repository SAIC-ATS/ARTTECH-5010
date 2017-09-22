#include "ofApp.h"


void ofApp::setup()
{
    std::vector<ofTexture> textures;

    ofTexture texture0;
    ofLoadImage(texture0, "s0.png");
    textures.push_back(texture0);

    ofTexture texture1;
    ofLoadImage(texture1, "s1.png");
    textures.push_back(texture1);

    ofTexture texture2;
    ofLoadImage(texture2, "s2.png");
    textures.push_back(texture2);

    ofTexture texture3;
    ofLoadImage(texture3, "s3.png");
    textures.push_back(texture3);

    int numParticles = 300;

    for (int i = 0; i < numParticles; i++)
    {
        // Create a particle (instantiate it).
        Particle p;

        // Reset the particle.
        p.reset();

        // Drawing info.
        p.texture = textures[i % 4];

        // Add the particle to the collection of particles.
        particles.push_back(p);
    }
}


void ofApp::update()
{
    for (int i = 0; i < particles.size(); i++)
    {
        particles[i].update();
    }
}


void ofApp::draw()
{
    ofBackground(0);

    ofEnableBlendMode(OF_BLENDMODE_ADD);

    for (int i = 0; i < particles.size(); i++)
    {
        particles[i].draw();
    }

    ofDisableBlendMode();
}
