#pragma once


#include "ofVec3f.h"
#include "ofGraphics.h"
#include "of3dGraphics.h"
#include "AbstractTypes.h"


class BaseParticle
{
public:
    BaseParticle();
    virtual ~BaseParticle();

    virtual void update();
    virtual void draw();

    virtual void kill();

    float getLife() const;

    glm::vec3 position;
    glm::vec3 lastPosition;
    
    glm::vec3 velocity;
    glm::vec3 acceleration;

    float heading;
    
    int age;
    int maxAge;
    bool isDead;

    std::shared_ptr<AbstractParticleSystem> particleSystem;


};