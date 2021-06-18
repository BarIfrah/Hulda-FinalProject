//============================= include section ==============================
#include "RegularFood.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
RegularFood::RegularFood(b2World& world, const sf::Vector2f& location,
	const sf::Vector2f& size, int ID)
	:Food(world, location, size, REGULAR_FOOD_T, ID) {}
//============================================================================