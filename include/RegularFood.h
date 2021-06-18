//============================ include section ===============================
#pragma once
#include "Food.h"
//========================== forward declarations ============================
class Controller;
/*============================================================================*/
class RegularFood : public Food
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	RegularFood(b2World&, const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0), int ID = 0);
	//=========================== method section ==============================
	//========================= private section ===============================
private:
};