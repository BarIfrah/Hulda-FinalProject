#include "MovingObject.h"
////==================== Constructors & destructors section ====================
MovingObject::MovingObject(const sf::Vector2f &, const sf::Vector2f &, char objectType, Physics m_Physics)
        : m_physics(m_Physics), m_isAnimated(false) {

}
