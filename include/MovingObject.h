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
	MovingObject(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	//============================ gets section ===============================
//	int getLookState()const;
	//sf::Vector2f getInitialLoc()const;
	//	int getState()const;
		//============================ sets section ===============================
	//	virtual void setLocation(const sf::Vector2f&);
	//	void setLookState(int);
		//=========================== method section ==============================
///	virtual void playTurn(const sf::Time&, Board&) = 0;
	virtual void speedUp(float, float) = 0;
	virtual void slowDown() = 0;
    virtual void move() = 0;
    //	virtual void resetAnimationTime() = 0;
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


};