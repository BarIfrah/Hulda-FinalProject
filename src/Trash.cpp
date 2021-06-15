//============================= include section ==============================
#include "Trash.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Trash::Trash(b2World& world,const sf::Vector2f& location, const sf::Vector2f& size, int ID)
	: StaticObject(world, location, size, TRASH_T, ID) {}
//============================== gets section ================================
//============================ methods section ===============================
/*this method return the object itself to the dynamic object that collided with
this wall or floor for double dispatch.*/
//void Trash::handleCollision(MovingObject& obj, const sf::Vector2f& movement) {
//	obj.handleCollision(*this, movement);
//}