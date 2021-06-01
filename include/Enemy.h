//============================ include section ===============================
#pragma once
#include "MovingObject.h"
#include <SFML/Graphics.hpp>
/*============================================================================
* Class: Enemy.
* This class is the base class of the diff types of the enemies. 
 ============================================================================*/
class Enemy: public MovingObject
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	using MovingObject::MovingObject;
	//=========================== method section =============================
//	virtual bool physicsTurn(const sf::Time&, Board&)override;
	//========================= private section ==============================
private:
	float m_distanceLimit;
};