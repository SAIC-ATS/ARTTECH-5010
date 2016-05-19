// =============================================================================
//
// Copyright (c) 2013 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#include "ofApp.h"


//------------------------------------------------------------------------------
void ofApp::setup()
{
    ofEnableAlphaBlending();

    perlinOffset = 0;

    font.loadFont("cooperBlack.ttf", FONT_SIZE, true, true, true);

    std::vector<ofTTFCharacter> shapes = font.getStringAsPoints("Hello world!");

    for(std::size_t i = 0; i < shapes.size(); ++i)
    {
        std::vector<ofPolyline>& outlines = shapes[i].getOutline();
        polylines.insert(polylines.end(), outlines.begin(), outlines.end());
    }
}

//------------------------------------------------------------------------------
void ofApp::update()
{
    perlinOffset += 0.01;

    std::vector<ofVec3f>& vertices = mesh.getVertices();

    std::vector<ofFloatColor>& colors = mesh.getColors();

//    std::random_shuffle(vertices.begin(), vertices.end());

    ofVec3f centroid = mesh.getCentroid();

    for(ofIndexType i = 0; i < mesh.getNumIndices(); ++i)
    {
        ofFloatColor color = mesh.getColor(i);
        ofVec3f position = mesh.getVertex(i);

        float z = ofNoise(position.x + perlinOffset,
                          position.y + perlinOffset);

        position.z = z * 10;

        mesh.setVertex(i, position);

        float alpha = ofNoise(position.x + perlinOffset / 2,
                              position.y + perlinOffset / 2,
                              position.z + perlinOffset / 2);


        color.a = alpha / 4.0f;

        mesh.setColor(i,color);
    }


}

//------------------------------------------------------------------------------
void ofApp::draw()
{
    ofBackgroundGradient(ofColor::gray, ofColor::black);

    cam.begin();

    ofPushMatrix();
    ofScale(1, -1);
    ofTranslate(-FONT_SIZE/2, FONT_SIZE/2);

//    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    mesh.draw();
    //    mesh.draw(OF_MESH_POINTS);
////    mesh.draw(OF_MESH_WIREFRAME);

    ofPopMatrix();

    cam.end();

}

//------------------------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//------------------------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//------------------------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//------------------------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//------------------------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//------------------------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//------------------------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//------------------------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//------------------------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
