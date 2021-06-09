//============================= include section ==============================
#include "Road.h"
#include "Utilities.h"
//#include "MovingObject.h"
#include <iostream>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Road::Road(const sf::Vector2f& location, const sf::Vector2f& size)
	: StaticObject(location, size, ROAD_T) {}
//============================== gets section ================================
//============================ methods section ===============================
/*this method return the object itself to the dynamic object that collided with
this wall or floor for double dispatch.*/
//void Road::handleCollision(MovingObject& obj, const sf::Vector2f& movement) {
//	obj.handleCollision(*this, movement);
//}