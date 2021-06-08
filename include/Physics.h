#pragma once
#include <SFML/Graphics.hpp>


// Physics engine to our game:
class Physics {
public:
    Physics(sf::Vector2f, float, float );
    ~Physics() = default;

    void setVelocity(const sf::Vector2f);
    void setAccel(const float);
    void setDrag(const float);


    sf::Vector2f getVelocity(const sf::Vector2f);
    float getAccel(const float) const;
    float getDrag(const float) const;


    /// may move it to "MovingObject"
    void updatePhysics();
    void move(const float x, const float y);

private:
    sf::Vector2f m_velocity;
    float m_acceleration;
    float m_drag;

};