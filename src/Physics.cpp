#include "Physics.h"
#include <SFML/Graphics.hpp>

float Physics::getAccel(const float) {
    return m_acceleration;
}

float Physics::getDrag(const float) {
    return m_drag;
}

sf::Vector2f Physics::getVelocity(const sf::Vector2f) {
    return m_velocity;
}