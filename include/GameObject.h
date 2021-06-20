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
		bool, b2World&, const sf::Vector2f & = { 0, 0 },
		const sf::Vector2f & = { 0, 0 },char objectType = NOTHING,
		bool isAnimated = false, int ID=0);

    GameObject();

    virtual ~GameObject() = 0;
	//============================ gets section ===============================
	const sf::Vector2f& getLocation()const;
	sf::Vector2f getSize()const;
	const sf::Sprite& getSprite()const;
	sf::Sprite* getSpritePtr();
	const sf::IntRect& getIntRect()const;
	PhysicsObject getPhysicsObj()const;
	int getID()const { return m_ID; }
	int getType()const { return m_objType; }
	sf::FloatRect getGlobalBounds()const;
	void setPhysicsObjectPos(sf::Vector2f, b2Vec2);
	void setIntRect(const sf::IntRect&);
	void flipSprite(const sf::Vector2f&);
	void updateLoc();
	void setSize(sf::Vector2u);
	void setOrigin();
	virtual void reset();

    b2Vec2 getLinearVelocity();
    b2Vec2 getForceApplied();
    void setForceApplied();
    void applyForce(b2Vec2);
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
	int m_ID;
	int m_objType;
	//========================= members section ===============================
};