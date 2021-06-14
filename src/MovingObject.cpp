#include "MovingObject.h"
#include "Resources.h"
//==================== Constructors & destructors section ====================
MovingObject::MovingObject(b2World& world, const sf::Vector2f& location,
    const sf::Vector2f& size, char objectType)
    : GameObject(DYNAMIC, world, location, size, objectType, true),
m_direction(RIGHT),
m_state(IDLE) {
    m_objectSprite = getSpritePtr();
}
//===========================================================================

void MovingObject::updateAnimation(const sf::Time& deltaTime) {
	m_animationTime += deltaTime;
	int spritesNum = (int)(this->m_animationTime.asSeconds() / ANIMATIONS_RATE);
	if (Resources::instance().getNumOfSprites(this->m_state) <= spritesNum)
		resetAnimationTime();
	else {
		sf::IntRect updatedRect = getIntRect();
		updatedRect.left = spritesNum * CHARACTER_WIDTH;
		if (updatedRect.width < 0)
			updatedRect.left += CHARACTER_WIDTH;
		//m_objectSprite->setOrigin(float(x) / 2, float(y) / 2);
		setIntRect(updatedRect);
	}
}
//===========================================================================
void MovingObject::setState(int state) {
	if (m_state != state) {
		sf::IntRect updatedRect = getIntRect();
		updatedRect.top = state * CHARACTER_HEIGHT;
		updatedRect.left = 0;
		if (updatedRect.width < 0)
			updatedRect.left += CHARACTER_WIDTH;
		setIntRect(updatedRect);
	}
	m_state = state;
}
//===========================================================================
int MovingObject::getState()const {
    return this->m_state;
}
//===========================================================================
void MovingObject::setDirection(int direction) {
    m_direction = direction;
}
//===========================================================================
int MovingObject::getDirection()const {
    return m_direction;
}
//===========================================================================
void MovingObject::resetAnimationTime() {
    m_animationTime = sf::seconds(0);
}
//===========================================================================