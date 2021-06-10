#pragma once
//============================ include section ===============================
#include "Food.h"
//========================== forward declarations ============================
//class Controller;
/*============================================================================
* Class: SpecialFood.
* This class represent the gift in the game that give a life bonus to the 
* player. this class derivred from the gift class.
 ============================================================================*/
class SpecialFood : public Food
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	SpecialFood(b2World& ,const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	//=========================== method section ==============================
	//virtual void handleColision(Controller&) override;
	//virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
	//========================= private section ===============================
private:
};