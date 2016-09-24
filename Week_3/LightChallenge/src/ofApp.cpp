#include "ofApp.h"


void ofApp::setup()
{
    leds.push_back(std::make_unique<RisingLedSet>());
    leds.push_back(std::make_unique<ChasingLedSet>());
    leds.push_back(std::make_unique<ChasingLedSetI>());
    leds.push_back(std::make_unique<ChaseAndFadeLedSet>());
    leds.push_back(std::make_unique<Palindrome>());
    leds.push_back(std::make_unique<PalindromeSpeeder>());
    leds.push_back(std::make_unique<BinaryLeds>());

    ofSetWindowShape(LedSet::DEFAULT_NUM_LEDS * LedSet::WIDTH + 2 * OFFSET_X,
                     leds.size() * (LedSet::TOTAL_HEIGHT + OFFSET_Y) + OFFSET_Y);

}


void ofApp::update()
{
    for (auto& led: leds) led->update();
}


void ofApp::draw()
{
    ofBackground(0);
    
    float x = OFFSET_X;
    float y = OFFSET_Y;

    for (auto& led: leds)
    {
        ofPushMatrix();
        ofTranslate(x, y);
        led->draw();

        y += (led->height() + OFFSET_Y);
        ofPopMatrix();
    }
}
