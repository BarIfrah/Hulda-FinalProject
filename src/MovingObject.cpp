#include "MovingObject.h"
//==================== Constructors & destructors section ====================
MovingObject::MovingObject(const sf::Vector2f& location,
    const sf::Vector2f& size, char objectType)
    : GameObject(location, size, objectType, true),
m_direction(RIGHT),
m_state(IDLE){}

//===========================================================================

void MovingObject::updateAnimation(sf::Vector2f whereToMove) {
    this->setLocation(whereToMove);
}
/*,
m_initialLoc(location), m_lookingState(WALK_RIGHT), m_isAnimated(true), m_state(IDLE)*/
//===========================================================================
void MovingObject::setState(int state) {
    this->m_state = state;
}
//===========================================================================
int MovingObject::getState()const {
    return this->m_state;
}
//===========================================================================
void MovingObject::setDirection(int direction) {
    this->m_direction = direction;
}
//===========================================================================
int MovingObject::getDirection()const {
    return this->m_direction;
}