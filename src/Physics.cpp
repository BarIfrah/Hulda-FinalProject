#include "Physics.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Macros.h"

Physics::Physics(sf::Vector2f velo, float drag, float accel): m_velocity(velo),
                m_acceleration(accel), m_drag(drag) {};

float Physics::getAccel(const float) const {
    return m_acceleration;
}

float Physics::getDrag(const float) const {
    return m_drag;
}

sf::Vector2f Physics::getVelocity(const sf::Vector2f) {
    return m_velocity;
}

void Physics::updatePhysics() {
    /// Slow down on X axis
    if (std::abs(m_velocity.x) >= MIN_VELOCITY){
        m_velocity.x = 0.f; /// stop
    }
    /// Slow down on Y axis
    if (std::abs(m_velocity.y) >= MIN_VELOCITY) {
        m_velocity.y = 0.f; /// stop
    }
    m_velocity *= m_drag;
}

void Physics::move(const float x, const float y) {
    /// max speed reached:

    /// speed up
    m_velocity.x += (x * m_acceleration);
}