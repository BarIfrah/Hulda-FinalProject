//============================= include section ==============================
#include "Trash.h"
#include "Utilities.h"
//#include "MovingObject.h"
#include <iostream>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Trash::Trash(const sf::Vector2f& location, const sf::Vector2f& size)
	: StaticObject(location, size, TRASH_T) {}
//============================== gets section ================================
//============================ methods section ===============================
/*this method return the object itself to the dynamic object that collided with
this wall or floor for double dispatch.*/
//void Trash::handleCollision(MovingObject& obj, const sf::Vector2f& movement) {
//	obj.handleCollision(*this, movement);
//}