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
GameObject::GameObject(const sf::Vector2f& location,
	const sf::Vector2f& size,
	char objectType,
	bool isAnimated) 
	: m_intRect(0, 0, CHARACTER_WIDTH, CHARACTER_HEIGHT),
	m_objectSprite(Resources::instance().getTexture(objectType),this->m_intRect),
	m_isAnimated(isAnimated) {
	this->m_objectSprite.setPosition(location);
	if (!isAnimated) {
		this->m_intRect.width =
			this->m_objectSprite.getTexture()->getSize().x;
		this->m_intRect.height =
			this->m_objectSprite.getTexture()->getSize().y;
	}
	this->m_objectSprite.setTextureRect(this->m_intRect);
	this->m_objectSprite.setScale(
		(float)size.x / this->m_intRect.width,
		(float)size.y / this->m_intRect.height);
	if (isAnimated)
	{
		this->m_objectSprite.scale(sf::Vector2f(2.0f, 2.0f));
	}
}
//============================================================================
GameObject::~GameObject() {}
//============================== gets section ================================
const sf::Vector2f& GameObject::getLocation()const {
	return this->m_objectSprite.getPosition();
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
//sf::Vector2f GameObject::getCenter() const {
//	return sf::Vector2f(this->getLocation().x + (this->getSize().x / 2),
//		this->getLocation().y + (this->getSize().y / 2));
//}
////============================================================================
//sf::Vector2f GameObject::getAbove()const {
//	return sf::Vector2f(this->getCenter().x, this->getLocation().y - 1);
//}
////============================================================================
//sf::Vector2f GameObject::getLeft()const {
//	return sf::Vector2f(this->getLocation().x - 1, this->getCenter().y);
//}
////============================================================================
//sf::Vector2f GameObject::getBelow()const {
//	return sf::Vector2f(this->getCenter().x,
//		this->getLocation().y + this->getSize().y + 1);
//}
////============================================================================
//sf::Vector2f GameObject::getRight()const {
//	return sf::Vector2f(this->getLocation().x + this->getSize().x + 1,
//		this->getCenter().y);
//}
////============================================================================
//sf::Vector2f GameObject::getBotLeft()const {
//	return sf::Vector2f(this->getCenter().x - this->getSize().x,
//		this->getCenter().y + this->getSize().y);
//}
////============================================================================
//sf::Vector2f GameObject::getBotRight()const {
//	return this->getCenter() + this->getSize();
//}
//============================ methods section ===============================
/*This method return the state og the object to the initial state.*/
//void GameObject::reset() { this->m_state = STAND; }
//============================================================================
//void GameObject::resetAnimationTime() {
//	this->m_animationTime = sf::seconds(0);
//}
//============================================================================
/*This method get a time. by this time the method update the sprites of the
object to create the animation. in other words, this method there is a line
of sprites this method run on this line.*/
//void GameObject::updateAnimation(const sf::Time& deltaTime) {
//	this->m_animationTime += deltaTime;
//	int spritesNum = (int)(this->m_animationTime.asSeconds() / ANIMATIONS_RATE);
//	if (Resources::instance().getNumOfSprites(this->m_state) <=
//		spritesNum)
//		this->resetAnimationTime();
//	else {
//		this->m_intRect.left = spritesNum * CHARACTER_WIDTH;
//		if (this->m_intRect.width < 0)
//			this->m_intRect.left += CHARACTER_WIDTH;
//	}
//}
//============================================================================
/*This method change the direction of the sprite.*/
//void GameObject::flipSprite() {
//	if (this->m_intRect.width > 0)
//		this->m_intRect.left -= CHARACTER_WIDTH;
//	else
//		this->m_intRect.left += CHARACTER_WIDTH;
//	this->m_intRect.width *= -1;
//}
//============================================================================
void GameObject::draw(sf::RenderWindow& window) {
	this->m_objectSprite.setTextureRect(this->m_intRect);
	window.draw(this->m_objectSprite);
}
//============================================================================
/*This method get an another game object and return true if the object
itself collide with the object it got.*/
//bool GameObject::CollidesWith(const GameObject& obj)const {
//	return m_objectSprite.getGlobalBounds().intersects
//	(obj.getSprite().getGlobalBounds());
//}
////============================================================================
/*this method update the state of the object according to his action.*/
//void GameObject::setState(int state) {
//	if (this->m_isAnimated && this->m_state != state) {
//		this->m_intRect.top = state * CHARACTER_HEIGHT;
//		this->m_intRect.left = 0;
//		if (this->m_intRect.width < 0)
//			this->m_intRect.left += CHARACTER_WIDTH;
//	}
//	this->m_state = state;
//}
//=========================== protected section ==============================
//============================== sets section ================================
/*this method get the direction movement and set it to the sprite of the
object.*/
void GameObject::setLocation(const sf::Vector2f& movment) {
	this->m_objectSprite.move(movment);
}