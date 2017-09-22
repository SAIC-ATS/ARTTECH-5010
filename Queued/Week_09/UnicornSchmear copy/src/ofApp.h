#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override
    {
        ofPolyline polyline;

        polyline.addVertex(ofRandomWidth(), ofRandomHeight(), 0);
        polyline.addVertex(ofRandomWidth(), ofRandomHeight(), 0);
        polyline.addVertex(ofRandomWidth(), ofRandomHeight(), 0);

        for (std::size_t i = 0; i < polyline.size(); ++i)
        {
            ofVec3f tangentPoint = polyline.getTangentAtIndex(i);
            std::cout << "Tangent " << i << " : " << tangentPoint << " / " << tangentPoint.normalize() << std::endl;
            ofVec3f normalPoint = polyline.getNormalAtIndex(i);
            std::cout << "Normal  " << i << " : " << normalPoint << " / " << normalPoint.normalize() << std::endl;
        }
    }


};
