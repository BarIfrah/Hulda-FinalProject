//============================ include section ===============================
#pragma once
#include "MovingObject.h"
/*============================================================================
* Class: Enemy.
* This class is the base class of the diff types of the enemies. 
 ============================================================================*/
class Enemy: public MovingObject
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
    explicit Enemy(b2World&, const sf::Vector2f & = { 0,0 }, const sf::Vector2f & = { 0,0 }, float s = 5);
    virtual void move(const sf::Time&) override;
	//=========================== method section =============================
//	virtual bool physicsTurn(const sf::Time&, Board&)override;
	//========================= private section ==============================
private:
	float m_distanceLimit;
};