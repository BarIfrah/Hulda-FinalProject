#pragma once
//============================ include section ===============================
#include "GameObject.h"
//========================== forward declarations ============================
/*============================================================================*/
class StaticObject : public GameObject
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	StaticObject(b2World&, const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0), char objectType = NOTHING,int ID=0);
};