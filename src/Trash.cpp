//============================= include section ==============================
#include "Trash.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Trash::Trash(b2World& world,const sf::Vector2f& location, const sf::Vector2f& size, int ID)
	: StaticObject(world, location, size, TRASH_T, ID) {}
//============================== gets section ================================
//============================ methods section ===============================