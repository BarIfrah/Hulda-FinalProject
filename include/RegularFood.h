//============================ include section ===============================
#pragma once
#include "Food.h"
//========================== forward declarations ============================
class MovingObject;
class Controller;
/*============================================================================*/
class RegularFood : public Food
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	RegularFood(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	//=========================== method section ==============================
	//void handleColision(Controller&)override;
	virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
	//========================= private section ===============================
private:
};