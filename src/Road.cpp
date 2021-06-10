//============================= include section ==============================
#include "Road.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Road::Road(b2World& world, const sf::Vector2f& location, const sf::Vector2f& size)
	: StaticObject(world, location, size, ROAD_T) {}
//============================== gets section ================================
//============================ methods section ===============================
/*this method return the object itself to the dynamic object that collided with
this wall or floor for double dispatch.*/
//void Road::handleCollision(MovingObject& obj, const sf::Vector2f& movement) {
//	obj.handleCollision(*this, movement);
//}