//============================ include section ===============================
#pragma once
#include "MovingObject.h"
#include <vector>
//========================== forward declarations ============================
class Board;
class Wall;
/*============================================================================
* Class: Player.
* This class represent the player in the game. Derives from MovingObject
* class. manage the turns,animations,movements of the player and handle on 
* the dig action of the player.
 ============================================================================*/
class Player : public MovingObject
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	Player(const sf::Vector2f & = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0));
	//=========================== method section ==============================
	virtual void playTurn(const sf::Time&, Board&) override;
	//========================= private section ===============================
private:
	//========================= members section ===============================
	std::vector<Wall*> m_diggedWalls;
	//====================== privete methods section ==========================
	void updateDiggedWalls(const sf::Time& deltaTime);
	void dig(Board&, const sf::Vector2f&, const sf::Time&);
};