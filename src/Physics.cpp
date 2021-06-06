#include "Physics.h"
#include <SFML/Graphics.hpp>

const float Physics::getAccel(const float) {
    return m_acceleration;
}

const float Physics::getDrag(const float) {
    return m_drag;
}

const sf::Vector2f Physics::getVelocity(const sf::Vector2f) {
    return m_velocity;
}