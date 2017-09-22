#pragma once


#include "ofMain.h"

class LedSet
{
public:
    LedSet():
        _leds(DEFAULT_NUM_LEDS, 0)
    {
    }

    virtual std::string name() const = 0;
    virtual void update() = 0;

    void draw() const
    {
        ofPushStyle();
        ofPushMatrix();

        ofSetColor(ofColor::gray);
        ofNoFill();
        ofDrawRectangle(0, 0, width(), HEIGHT );
        ofDrawRectangle(0, 0, width(), height());
        ofDrawBitmapStringHighlight(name(), 3, height() - 5, ofColor::gray, ofColor::white);

        ofPushMatrix();
        ofTranslate(WIDTH / 2, HEIGHT / 2);

        for (std::size_t i = 0; i < _leds.size(); ++i)
        {
            ofPushMatrix();
            ofTranslate(i * WIDTH, 0);
            ofFill();
            ofSetColor(ofColor::yellow, _leds[i]);
            ofDrawEllipse(0, 0, LED_WIDTH, LED_HEIGHT);
            ofNoFill();
            ofSetColor(ofColor::yellow);
            ofDrawEllipse(0, 0, LED_WIDTH, LED_HEIGHT);
            ofPopMatrix();
        }
        ofPopMatrix();

        ofPopMatrix();
        ofPopStyle();
    }

    float width() const
    {
        return _leds.size() * WIDTH;
    }

    float height() const
    {
        return TOTAL_HEIGHT;
    }

    uint64_t now() const
    {
        return ofGetElapsedTimeMillis();
    }

    enum
    {
        WIDTH = 50,
        HEIGHT = 50,
        LED_WIDTH = 30,
        LED_HEIGHT = 30,
        DEFAULT_NUM_LEDS = 6, 
        TEXT_HEIGHT = 19,
        TOTAL_HEIGHT = HEIGHT + TEXT_HEIGHT
    };

protected:
    uint64_t _lastUpdated = 0;
    int64_t _updateInterval = 1000;
    std::string _name;
    std::vector<int> _leds;
};

class RisingLedSet: public LedSet
{
public:
    using LedSet::LedSet;

    virtual std::string name() const { return "rising/falling"; };

    virtual void update()
    {
        for (std::size_t i = 0; i < _leds.size(); ++i)
        {
            if (i < _leds.size() / 2)
            {
                _leds[i]++;
                if (_leds[i] > 255) _leds[i] = 0;
            }
            else
            {
                _leds[i]--;
                if (_leds[i] < 0) _leds[i] = 255;
            }
        }
    }

};


class ChasingLedSet: public LedSet
{
public:
    using LedSet::LedSet;

    virtual std::string name() const { return "chasing"; };

    virtual void update()
    {
        auto _now = now();

        if (_lastUpdated + _updateInterval < _now)
        {
            for (std::size_t i = 0; i < _leds.size(); ++i)
            {
                _leds[i] = (i == activeLed) ? 255 : 0;
            }

            activeLed = (activeLed + 1) % _leds.size();

            _lastUpdated = _now;
        }
    }
    
    std::size_t activeLed = 0;
    
};


class ChasingLedSetI: public LedSet
{
public:
    using LedSet::LedSet;

    virtual std::string name() const { return "chasing inverted"; };

    virtual void update()
    {
        auto _now = now();

        if (_lastUpdated + _updateInterval < _now)
        {
            for (std::size_t i = 0; i < _leds.size(); ++i)
            {
                _leds[i] = (i == activeLed) ? 0 : 255;
            }

            activeLed = (activeLed + 1) % _leds.size();

            _lastUpdated = _now;
        }
    }

    std::size_t activeLed = 0;
    
};


class ChaseAndFadeLedSet: public LedSet
{
public:
    using LedSet::LedSet;

    virtual std::string name() const { return "chase and fade"; };

    virtual void update()
    {
        auto _now = now();

        for (std::size_t i = 0; i < _leds.size(); ++i)
        {
            _leds[i] = (i == activeLed) ? 255 : (_leds[i] - 2);
        }

        if (_lastUpdated + _updateInterval < _now)
        {
            activeLed = (activeLed + 1) % _leds.size();
            _lastUpdated = _now;
        }
    }
    
    std::size_t activeLed = 0;
    
};



class Palindrome: public LedSet
{
public:
    using LedSet::LedSet;

    virtual std::string name() const { return "palindrome"; };

    virtual void update()
    {
        _updateInterval = 250;

        auto _now = now();

        for (std::size_t i = 0; i < _leds.size(); ++i)
        {
            _leds[i] = (i == activeLed) ? 255 : 0;
        }

        if (_lastUpdated + _updateInterval < _now)
        {
            activeLed += increment;

            if (activeLed == 0 || activeLed == _leds.size() - 1)
            {
                increment *= -1;
            }

            _lastUpdated = _now;
        }
    }

    int increment = 1;
    std::size_t activeLed = 0;
    
};


class PalindromeSpeeder: public LedSet
{
public:
    using LedSet::LedSet;

    virtual std::string name() const { return "palindrome speeder"; };

    virtual void update()
    {
        auto _now = now();

        for (std::size_t i = 0; i < _leds.size(); ++i)
        {
            _leds[i] = (i == activeLed) ? 255 : 0;
        }

        if (_lastUpdated + _updateInterval < _now)
        {
            activeLed += increment;

            if (activeLed == 0 || activeLed == _leds.size() - 1)
            {
                increment *= -1;
            }

            _updateInterval *= 0.8;

            if (_updateInterval < 1 && activeLed == 0)
            {
                _updateInterval = 1000;
            }

            _lastUpdated = _now;
        }
    }
    
    int increment = 1;
    std::size_t activeLed = 0;
    
};


class BinaryLeds: public LedSet
{
public:
    using LedSet::LedSet;

    virtual std::string name() const { return "mystery!"; };

    virtual void update()
    {
        auto _now = now();

        for (std::size_t i = 0; i < _leds.size(); ++i)
        {
            _leds[i] = 255 * ((num >> i) & 1);
        }


        if (_lastUpdated + _updateInterval < _now)
        {
            num = (num + 1) % 64;
            _lastUpdated = _now;
        }
    }

    std::size_t num = 0;
    
};


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    enum
    {
        OFFSET_X = 10,
        OFFSET_Y = 10
    };

    std::vector<std::unique_ptr<LedSet>> leds;

//    int leds[DEFAULT_NUM_SETS][DEFAULT_NUM_LEDS];

//    bool goingUp_0 = true;
//
//    int goingUp_1[DEFAULT_NUM_LEDS] = { true, true, true, true, true, true };
//    int increments_1[DEFAULT_NUM_LEDS] = { 1, 2, 3, 4, 5, 6 };
//
//    int value_2 = 0;
//    int lastUpdate_2 = 0;
//    int updateInterval_2 = 1000;

};
