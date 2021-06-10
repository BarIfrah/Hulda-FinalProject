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
	//using GameObject::GameObject;
	StaticObject(b2World&, const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0), char objectType = NOTHING);
	//=========================== method section ==============================
	//virtual void handleCollision(MovingObject&, const sf::Vector2f&) = 0;
	//========================= private section ===============================
private:
};