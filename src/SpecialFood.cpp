//============================= include section ==============================
#include "SpecialFood.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
SpecialFood::SpecialFood(const sf::Vector2f& location,
	const sf::Vector2f& size)
	:Food(location, size, SPECIAL_FOOD_T) {}
//============================================================================