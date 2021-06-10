#include "StaticObject.h"

//==================== Constructors & destructors section ====================
StaticObject::StaticObject(b2World& world, const sf::Vector2f& location,
    const sf::Vector2f& size, char objectType)
    : GameObject(STATIC, world, location, size, objectType, true)
 {}
//===========================================================================