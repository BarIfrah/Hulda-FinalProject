#pragma once
//============================ include section ===============================
#include "GameObject.h"
#include <SFML/Graphics.hpp>
//========================== forward declarations ============================
class MovingObject;
/*============================================================================*/
class StaticObject : public GameObject
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	using GameObject::GameObject;
	//=========================== method section ==============================
	virtual void handleCollision(MovingObject&, const sf::Vector2f&) = 0;
	//========================= private section ===============================
private:
};