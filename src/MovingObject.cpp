#include "MovingObject.h"
//==================== Constructors & destructors section ====================
MovingObject::MovingObject(const sf::Vector2f& location,
    const sf::Vector2f& size)
    : GameObject(location, size, true) {}

//===========================================================================

void MovingObject::updateAnimation(sf::Vector2f whereToMove) {
    m_objectSprite.move(whereToMove);
}
/*,
m_initialLoc(location), m_lookingState(WALK_RIGHT), m_isAnimated(true), m_state(IDLE)*/


//void MovingObject::speedUp(const float, const float) {
//    ;
//}
//
//void MovingObject::slowDown() {
//    /// taking care of acceleration
//
//}