//============================ include section ===============================
#pragma once
#include "Enemy.h"
/*============================================================================*/
class Exterminator: public Enemy
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	Exterminator(b2World&, const sf::Vector2f & = { 0,0 },
                 const sf::Vector2f & = { 0,0 },  float speed = 6.f);
	//=========================== method section ==============================
	//========================= private section ===============================
private:
};