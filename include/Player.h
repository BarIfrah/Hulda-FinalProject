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
	Player(b2World&, const sf::Vector2f & = { 0,0 },
		const sf::Vector2f & = { 0,0 },int ID=0);
	virtual void move(const sf::Time&,Board&) override;
	void updateAnimation(const sf::Time&) override;
	void playerJump(const b2Vec2&);
	int getScore() const;
	void setScore(const int&);
	int getLife() const;
	void setLife(const int&);
	void resetLife(const int& life);
	void resetScore();
//	void resetAnimationTime() override;
//	sf::FloatRect getGlobalBounds()const;
	//=========================== method section ==============================

	//========================= private section ===============================
private:
	int m_score = 0;
	int m_life = 3;
	int m_lifeAdder = 100;
	//========================= members section ===============================
	//====================== private methods section ==========================
};