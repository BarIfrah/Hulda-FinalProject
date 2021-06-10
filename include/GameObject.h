#pragma once
//============================ include section ===============================
#include <SFML/Graphics.hpp>
#include "Macros.h"
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
		const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0),
		char objectType = NOTHING,
		bool isAnimated = false);
	virtual ~GameObject() = 0;
	//============================ gets section ===============================
	/*sf::Vector2f getAbove()const;
	sf::Vector2f getLeft()const;
	sf::Vector2f getBelow()const;
	sf::Vector2f getRight()const;
	sf::Vector2f getCenter()const;
	sf::Vector2f getBotLeft()const;
	sf::Vector2f getBotRight()const;*/
	const sf::Vector2f& getLocation()const;
	sf::Vector2f getSize()const;
	const sf::Sprite& getSprite()const;
	sf::Sprite* getSpritePtr();
	const sf::IntRect& getIntRect()const;
	void setIntRect(const sf::IntRect&);
	void flipSprite(const sf::Vector2f&);
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
	//========================= members section ===============================
};