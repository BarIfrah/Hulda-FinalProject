#pragma once
#include "Resources.h"
#include <box2d/box2d.h>

class PhysicsObject
{
private:

    b2Body* m_body;
    b2FixtureDef    m_fixtureDef;
    b2Fixture* m_fixture;
  //  Type_t          m_type;

public:
    PhysicsObject() = default;
    PhysicsObject(b2World&, const sf::Vector2f&, const bool, const sf::Vector2f&/*, const Type_t*/);
    ~PhysicsObject();

    b2Vec2 getPosition() const { return  m_body->GetPosition(); }
    void setPosition(const sf::Vector2f, const b2Vec2);
    b2Body* getBody()const;
    b2Vec2 getLinearVelocity();
    b2Vec2 getForceApplied();
    void setForceApplied();
    //void setSize(const sf::Vector2f);
    void applyForce(const b2Vec2&);
    //int randomNumber(const int min, const int max);
    void setID(const int);
};
