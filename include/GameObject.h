#pragma once
//============================ include section ===============================
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "PhysicsObject.h"
//========================== forward declarations ============================
class Board;
/*============================================================================
* Class: GameObject.
* This is the base class of all the game objects in hte game.
* every object in the game is derived from this class.
 ============================================================================*/
class GameObject {
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	GameObject(
		const bool, b2World&,
		const sf::Vector2f & = { 0, 0 },
		const sf::Vector2f & = { 0, 0 },
		char objectType = NOTHING,
		bool isAnimated = false);
	virtual ~GameObject() = 0;
	//============================ gets section ===============================
	const sf::Vector2f& getLocation()const;
	sf::Vector2f getSize()const;
	const sf::Sprite& getSprite()const;
	sf::Sprite* getSpritePtr();
	const sf::IntRect& getIntRect()const;
	void setPhysicsObjectPos(sf::Vector2f);
	void setIntRect(const sf::IntRect&);
	void flipSprite(const sf::Vector2f&);
	void updateLoc();
	void setSize(const sf::Vector2u);
	//=========================== method section ==============================
	//bool CollidesWith(const GameObject&)const;
	virtual void draw(sf::RenderWindow&);
	//========================= protected section ==============================
protected:
	virtual void setLocation(const sf::Vector2f&);
	//========================= private section ===============================
private:
	sf::Sprite m_objectSprite;
	bool m_isAnimated;
	sf::IntRect m_intRect;
	PhysicsObject m_physicsObject;
	//========================= members section ===============================
};