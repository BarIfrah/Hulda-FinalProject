//============================ include section ===============================
#pragma once
#include "MovingObject.h"
#include <vector>
//========================== forward declarations ============================
//class Board;
//class Road;
/*============================================================================
* Class: Player.
* This class represent the player in the game. Derives from MovingObject
* class. manage the turns,animations,movements of the player and handle on 
* the jump action of the player.
 ============================================================================*/
class Player : public MovingObject
{
	//========================== public section ==============================
public:
	//================= constructors and destructors section =================
	explicit Player(b2World&, const sf::Vector2f & = { 0,0 },
		const sf::Vector2f & = { 0,0 },int ID=0);
	virtual void move(const sf::Time&) override;
	void updateAnimation(const sf::Time&) override;
//	void resetAnimationTime() override;
	sf::FloatRect getGlobalBounds()const;
	//=========================== method section ==============================
	//virtual void playTurn(const sf::Time&, Board&) override;
	//========================= private section ===============================
private:
 //   sf::Time m_animationTime;
	//========================= members section ===============================
	//====================== private methods section ==========================
	//void jump(Board&, const sf::Vector2f&, const sf::Time&);
};