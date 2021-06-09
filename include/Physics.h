#pragma once
#include <SFML/Graphics.hpp>


// Physics engine to our game:
class Physics {
public:
    Physics();
    Physics(sf::Vector2f, float, float);
    ~Physics() = default;

    void setVelocity(sf::Vector2f);
    void setAccel(float);
    void setDrag(float);


    sf::Vector2f getVelocity();
    float getAccel() const;
    float getDrag() const;


    /// may speedUp it to "MovingObject"
    void slowDownPhysicsObject();
    void speedUpPhysicsObject(const float x,const float y);

private:
    sf::Vector2f m_velocity;
    float m_acceleration;
    float m_drag;
    float m_gravity;

};