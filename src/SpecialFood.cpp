//============================= include section ==============================
#include "SpecialFood.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
SpecialFood::SpecialFood(b2World& world, const sf::Vector2f& location,
	const sf::Vector2f& size)
	:Food(world, location, size, SPECIAL_FOOD_T) {}
//============================================================================