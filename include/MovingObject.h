#pragma once
//============================ include section ===============================
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Physics.h"
//========================== forward declarations ============================
class Road;
class Board;
class StaticObject;
/*============================================================================
* Class: MovingObject.
* This class represent all the dynamic objects in the game: player or enemies.
* handle collisions with static objects, manage animations, reset the objects,
* update hte states of the objects & manage their movements.
 ============================================================================*/
class MovingObject : public GameObject
{
	//========================== public section ==============================
public:
	//================= constructors and destructors section =================
    MovingObject(const sf::Vector2f &, const sf::Vector2f &, char objectType, Physics m_Physics);
	//============================ gets section ===============================
	sf::Vector2f getInitialLoc()const;
		//============================ sets section ===============================
		//=========================== method section ==============================
///	virtual void playTurn(const sf::Time&, Board&) = 0;
	virtual void move(const float, const float) = 0;
	virtual void updatePhysics() = 0;

	virtual void resetAnimationTime() = 0;
	void updateAnimation(const sf::Time&);

		//========================= protected section ==============================
protected:
//	virtual void setState(int);
	//========================= private section ===============================
private:
	//========================= members section ===============================
	//general
	sf::Sprite m_objectSprite;
///	sf::Vector2f m_initialLoc;
///	int m_lookingState;
///	int m_state;

	//animation
	bool m_isAnimated;
	sf::IntRect m_intRect;
	sf::Time m_animationTime;

	//Physics
	Physics m_physics;
};