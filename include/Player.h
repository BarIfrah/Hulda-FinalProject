//============================ include section ===============================
#pragma once
#include "MovingObject.h"
#include <vector>
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
	//============================ get section ================================
	int getScore() const;
	int getLife() const;
	bool canLevelUP()const;
	//============================ set section ================================
	void setScore(const int&);
	void setLife(const int&);
	//=========================== method section ==============================
	virtual void move(const sf::Time&, Board&) override;
	void updateAnimation(const sf::Time&) override;
	void playerJump(const b2Vec2&);
	void resetLife(const int& life);
	void resetScore();
	void setLevelUp();
	//========================= private section ===============================
private:
	int m_score = 0;
	int m_life = 3;
	int m_lifeAdder = 100;
	bool m_canLevelUP=false;
};