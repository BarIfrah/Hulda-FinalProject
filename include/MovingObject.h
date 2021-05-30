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
* This class reresent all the dynamic objects in the game: player or enemies.
* handle colisions with static objects, manage animations, reset the objects,
* update hte states of the objects & manage their movments.
 ============================================================================*/
class MovingObject : public GameObject
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	MovingObject(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0),
		char objectType = NOTHING);
	//============================ gets section ===============================
	int getLookState()const;
	sf::Vector2f getInitialLoc()const;
	//============================ sets section ===============================
	virtual void setLocation(const sf::Vector2f&);
	void setLookState(int);
	virtual void reset()override;
	virtual void setState(int)override;
	//=========================== method section ==============================
	virtual void playTurn(const sf::Time&, Board&) = 0;
	virtual bool physicsTurn(const sf::Time&, Board&);
	void moveUp(const sf::Time&, Board&);
	void moveDown(const sf::Time&, Board&);
	void moveLeft(const sf::Time&, Board&);
	void moveRight(const sf::Time&, Board&);
	virtual void nullMovement(const sf::Vector2f&);
	bool isFalling(const Board&);
	//========================= private section ===============================
private:
	//========================= members section ===============================
	sf::Vector2f m_initialLoc;
	int m_lookingState;
};