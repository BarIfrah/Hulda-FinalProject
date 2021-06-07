#include "MovingObject.h"
//==================== Constructors & destructors section ====================
MovingObject::MovingObject(const sf::Vector2f& location,
    const sf::Vector2f& size/*,
    char objectType*/)
    : GameObject(location, size,/*objectType*/true) /*,
    m_initialLoc(location), m_lookingState(WALK_RIGHT), m_isAnimated(true), m_state(IDLE)*/
{};

void MovingObject::move(const float, const float) {
    ;
}

void MovingObject::updatePhysics() {
    /// taking care of acceleration

}