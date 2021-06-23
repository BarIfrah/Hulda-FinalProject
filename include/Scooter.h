//============================ include section ===============================
#pragma once
#include "Enemy.h"
/*============================================================================*/
class Scooter: public Enemy
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	Scooter(float distanceLim, b2World&, const sf::Vector2f & = { 0,0 },
		const sf::Vector2f & = { 0,0 }, int ID = 0);
	//=========================== method section ==============================
    void move(const sf::Time &, Board &) override;

};