#pragma once
#include <SFML/Graphics.hpp>


// Physics engine to our game:
class Physics {
public:
    Physics();
    ~Physics() = default;

    void setVelocity(const sf::Vector2f);
    void setAccel(const float);
    void setDrag(const float);


    const sf::Vector2f getVelocity(const sf::Vector2f);
    const float getAccel(const float);
    const float getDrag(const float);



private:
    sf::Vector2f m_velocity;
    float m_acceleration;
    float m_drag;

};