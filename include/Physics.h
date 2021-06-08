#pragma once
#include <SFML/Graphics.hpp>


// Physics engine to our game:
class Physics {
public:
    Physics();
    Physics(sf::Vector2f, float, float );
    ~Physics() = default;

    void setVelocity(sf::Vector2f);
    void setAccel(float);
    void setDrag(float);


    sf::Vector2f getVelocity(sf::Vector2f);
    float getAccel(float) const;
    float getDrag(float) const;


    /// may move it to "MovingObject"
    void updatePhysics();
    void move(float x, float y);

private:
    sf::Vector2f m_velocity;
    float m_acceleration;
    float m_drag;

};