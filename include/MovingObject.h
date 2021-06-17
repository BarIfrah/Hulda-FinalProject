#pragma once
//============================ include section ===============================
#include "GameObject.h"
#include <SFML/Graphics.hpp>
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
	MovingObject(b2World&, const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0),int objectType = NOTHING,int ID=0);
	//============================ gets section ===============================
//	int getLookState()const;
	//sf::Vector2f getInitialLoc()const;
	//	int getState()const;
		//============================ sets section ===============================
	//	virtual void setLocation(const sf::Vector2f&);
	//	void setLookState(int);
		//=========================== method section ==============================
    virtual void move(const sf::Time&, Board&) = 0;
    void resetAnimationTime();
	void updateAnimation(const sf::Time&);
	void setState(int);
	int getState()const;
	void setDirection(int);
	int getDirection()const;
	sf::Vector2f getInitialLocation()const;
		//========================= protected section ==============================
protected:
//	virtual void setState(int);
	//========================= private section ===============================
private:
	//========================= members section ===============================
	//general
	sf::Sprite* m_objectSprite =nullptr;
	int m_state;
	int m_direction;
	sf::Time m_animationTime;
	sf::Vector2f m_initialLocation;
};