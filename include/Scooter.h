//============================ include section ===============================
#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>
/*============================================================================*/
class Scooter: public Enemy
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	Scooter(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	//=========================== method section ==============================
	virtual void playTurn(const sf::Time&, Board&) override;
	//========================= private section ===============================
private:
	//========================= members section ===============================
	sf::Time m_randTime;
	int m_rand_move;
};