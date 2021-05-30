//============================ include section ===============================
#pragma once
#include "Enemy.h"
/*============================================================================*/
class Exterminator: public Enemy
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	Exterminator(const sf::Vector2f & = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0));
	//=========================== method section ==============================
	virtual void playTurn(const sf::Time&, Board&) override;
	//========================= private section ===============================
private:
};