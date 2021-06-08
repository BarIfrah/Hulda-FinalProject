#include "Physics.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Macros.h"
//============================================================================

Physics::Physics() {
    /// set al Physics to match player settings.
    /// Enemies will change it in their constructors
    m_acceleration = PLAYER_ACCEL;
    m_velocity = sf::Vector2f (MAX_VELOCITY_X, MAX_VELOCITY_Y);
    m_drag = PLAYER_DRAG;
    m_gravity = GRAVITY;
}
//============================================================================

Physics::Physics(sf::Vector2f velo, float drag, float accel): m_velocity(velo),
                m_acceleration(accel), m_drag(drag), m_gravity(GRAVITY) {};

//============================================================================

float Physics::getAccel(const float) const {
    return m_acceleration;
}

//============================================================================
float Physics::getDrag(const float) const {
    return m_drag;
}

//============================================================================
sf::Vector2f Physics::getVelocity(const sf::Vector2f) {
    return m_velocity;
}

//============================================================================
void Physics::slowDownPhysicsObject() {

    ///Applies gravity: may want to put in a comment- to avoid object falling.
    m_velocity.y += 1.f * m_acceleration;
    if (std::abs(m_velocity.y) > MAX_VELOCITY_Y){
        m_velocity.y = MAX_VELOCITY_Y * ((m_velocity.y > 0.f) ? -1.f :1.f); /// going UP or DOWN
    }
    /// Decelerate Physics object
    m_velocity *= m_drag;

    /// Slow down on X axis
    if (std::abs(m_velocity.x) >= MIN_VELOCITY){
        m_velocity.x = 0.f; /// stop
    }
    /// Slow down on Y axis
    if (std::abs(m_velocity.y) >= MIN_VELOCITY) {
        m_velocity.y = 0.f; /// stop
    }

}

//============================================================================
void Physics::speedUpPhysicsObject(const float x, const float y) {
    /// speed up (side movements)
    m_velocity.x += (x * m_acceleration);

    /// max speed reached (X axis:
    if (std::abs(m_velocity.x) > MAX_VELOCITY_X){
        m_velocity.x = MAX_VELOCITY_X * ((m_velocity.x < 0) ? -1.f : 1.f); /// multiply by direction (-1: left, 1:right)
    }

    /// Jump- will happen when user press 'SPACE BAR'
    m_velocity.y += (y * m_acceleration);

    /// to reach max jump- reset vertical accel.
    if (m_velocity.y > MAX_VELOCITY_Y)
        m_velocity.y = 0.f; /// gravity will apply here.
}

//============================================================================

void Physics::setVelocity(sf::Vector2f velo) {
    m_velocity = velo;
}

//============================================================================
void Physics::setAccel(float accel) {
    m_acceleration = accel;
}

//============================================================================
void Physics::setDrag(float drag) {
    m_drag = drag;
}