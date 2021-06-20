//============================ include section ===============================
#pragma once
#include "Enemy.h"
#include "Player.h"
/*============================================================================*/
class Exterminator: public Enemy
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	Exterminator(float distanceLim, b2World&, const sf::Vector2f & = { 0,0 },
		const sf::Vector2f & = { 0,0 }, int ID = 0);
	//=========================== method section ==============================
   
//    void resetAnimationTime() override;
	virtual void move(const sf::Time&,Board&) override;
	void setCollision();
	//========================= private section ===============================
private:
	bool m_collided = false;
};