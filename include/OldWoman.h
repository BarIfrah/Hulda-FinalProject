//============================ include section ===============================
#pragma once
#include "Enemy.h"
/*============================================================================
* Class: OldWoman.
* This class represent the Old Woman in the game.
* this class is derives from the class enemy.
 ============================================================================*/
class OldWoman: public Enemy
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	OldWoman(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	//=========================== methods section ============================
	virtual void playTurn(const sf::Time&, Board&)override;
	virtual void handleCollision(Road&, const sf::Vector2f&)override;
	//========================= private section ==============================
private:
	bool m_turn;
};