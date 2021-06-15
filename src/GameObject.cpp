//============================= include section ==============================
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Board.h"
#include "Utilities.h"
#include <iostream>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
//============================================================================
GameObject::GameObject(const bool isDynamic, b2World& world ,const sf::Vector2f& location,
                       const sf::Vector2f& size, char objectType, bool isAnimated, int ID)
        : m_intRect(0, 0, CHARACTER_WIDTH, CHARACTER_HEIGHT),
          m_objectSprite(Resources::instance().getTexture(objectType),this->m_intRect),
          m_isAnimated(isAnimated), m_physicsObject(world, location, isDynamic, size),m_ID(ID)
{
    this->m_objectSprite.setPosition(location);
    /*float x = m_objectSprite.getTexture()->getSize().x;
    float  y = m_objectSprite.getTexture()->getSize().y;*/

    if (!isAnimated) {
        m_intRect.width = m_objectSprite.getTexture()->getSize().x;
        m_intRect.height = m_objectSprite.getTexture()->getSize().y;
        /*m_intRect.width = x;
        m_intRect.height = y;*/
    }
    /* m_objectSprite.setScale(size.x / x, size.y / y);
     m_objectSprite.setOrigin(x / 2, y / 2);
     m_objectSprite.setPosition(location);*/
    m_objectSprite.setTextureRect(m_intRect);
    setSize(sf::Vector2u(size));
    updateLoc();
    m_physicsObject.setID(m_ID);
}
//============================================================================
GameObject::~GameObject() {}
//============================== gets section ================================
const sf::Vector2f& GameObject::getLocation()const {
	return m_objectSprite.getPosition();
}
//============================================================================
//int GameObject::getState()const {
//	return this->m_state;
//}
//============================================================================
sf::Vector2f GameObject::getSize()const {
	return sf::Vector2f(this->getSprite().getGlobalBounds().width,
		this->getSprite().getGlobalBounds().height);
}
//============================================================================
const sf::Sprite& GameObject::getSprite() const {
	return (this->m_objectSprite);
}
//============================================================================
sf::Sprite* GameObject::getSpritePtr() {
	return &m_objectSprite;
}
//============================================================================
void GameObject::updateLoc()
{
	auto pos = m_physicsObject.getPosition();
	setLocation(sf::Vector2f(pos.x * PPM, pos.y *PPM));
}
//============================ methods section ===============================
void GameObject::draw(sf::RenderWindow& window) {
	this->m_objectSprite.setTextureRect(this->m_intRect);
	window.draw(this->m_objectSprite);
}
//============================================================================
const sf::IntRect& GameObject::getIntRect()const { return this->m_intRect; }
//============================================================================
void GameObject::setPhysicsObjectPos(sf::Vector2f newPos, b2Vec2 velocity)
{
    updateLoc();
	m_physicsObject.setPosition(newPos, velocity);

}
//============================================================================
void GameObject::setIntRect(const sf::IntRect& rect){
	m_intRect = rect;
}
//============================================================================
/*This method change the direction of the sprite.*/
void GameObject::flipSprite(const sf::Vector2f& scale) {
	m_objectSprite.scale(scale);
	m_objectSprite.setOrigin(m_objectSprite.getGlobalBounds().width / 2,
		m_objectSprite.getGlobalBounds().height / 2);
}
//============================================================================
/*This method get an another game object and return true if the object
itself collide with the object it got.*/
//bool GameObject::CollidesWith(const GameObject& obj)const {
//	return m_objectSprite.getGlobalBounds().intersects
//	(obj.getSprite().getGlobalBounds());
//}
//=========================== protected section ==============================
//============================== sets section ================================
/*this method get the direction movement and set it to the sprite of the
object.*/
void GameObject::setLocation(const sf::Vector2f& movment) {
	//this->m_objectSprite.move(movment);
	m_objectSprite.setPosition(movment);
}
//============================================================================
void GameObject::setSize(const sf::Vector2u size)
{
	m_objectSprite.scale((size.x / m_objectSprite.getGlobalBounds().width),
		(size.y / m_objectSprite.getGlobalBounds().height));

	//m_objectSprite.setOrigin(float(m_objectSprite.getTexture()->getSize().x / 2), float(m_objectSprite.getTexture()->getSize().y / 2));
}


void GameObject::applyForce(b2Vec2 force) {
    m_physicsObject.applyForce(force);
}

b2Vec2 GameObject::getLinearVelocity() {
    return m_physicsObject.getLinearVelocity();
}