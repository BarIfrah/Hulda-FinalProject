#pragma once
//============================ include section ===============================
#include "StaticObject.h"
//========================== forward declarations ============================
class MovingObject;
/*============================================================================*/
class Adanit : public StaticObject
{
public:
	//========================== public section ==============================
	 //================= constractors and destractors section =================
	Adanit(b2World&, const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0), int ID = 0);
	//=========================== method section ==============================
	//virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
	//============================ gets section ===============================
	//========================= private section ===============================
private:
	//========================= members section ===============================

};