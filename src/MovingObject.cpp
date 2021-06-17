#include "MovingObject.h"
#include "Resources.h"
#include <iostream>
//==================== Constructors & destructors section ====================
MovingObject::MovingObject(b2World& world, const sf::Vector2f& location,
    const sf::Vector2f& size, int objectType,int ID)
    : GameObject(DYNAMIC, world, location, size, objectType, true,ID),
	m_direction(RIGHT), m_state(IDLE), m_initialLocation(location)
{
    m_objectSprite = getSpritePtr();
}
//===========================================================================

//void MovingObject::updateAnimation(const sf::Time& deltaTime) {
//	m_animationTime += deltaTime;
//	int spritesNum = (int)(this->m_animationTime.asSeconds() / ANIMATIONS_RATE);
//	if (Resources::instance().getNumOfSprites(this->m_state) <= spritesNum)
//		resetAnimationTime();
//	else {
//		sf::IntRect updatedRect = getIntRect();
//		updatedRect.left = spritesNum * PLAYER_BOX_WIDTH;
//		if (updatedRect.width < 0)
//			updatedRect.left += PLAYER_BOX_WIDTH;
//		//m_objectSprite->setOrigin(float(x) / 2, float(y) / 2);
//
//	//	std::cout << m_objectSprite->getGlobalBounds().width << " " << m_objectSprite->getTextureRect().height << '\n';
//        m_objectSprite->setOrigin(m_objectSprite->getTextureRect().width / 2, 0);
//		setIntRect(updatedRect);
//	}
//}
//===========================================================================
void MovingObject::setState(int state, int height, int width) {
    int offset;
    switch (state) {
        case RUN:
            offset = height + PLAYER_OFFSET;
            break;
        case JUMP: /// Also applies to 'FALL' state
            offset = 2 * height + PLAYER_OFFSET + PLAYER_SPECIAL_OFFSET;
            break;
        case FALL: /// same operation but cant avoid this.
            offset = 2 * height + PLAYER_OFFSET + PLAYER_SPECIAL_OFFSET;
            break;
        default:
            offset = 0;
            break;
    }
    std:: cout << offset << " state: " << state << " mstate  " << m_state << '\n';

	if (m_state != state) {
		sf::IntRect updatedRect = getIntRect();
		updatedRect.top = offset;
		updatedRect.left = 0;
		if (updatedRect.width < 0)
			updatedRect.left += width;
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
sf::Vector2f MovingObject::getInitialLocation() const
{
	return m_initialLocation;
}
//===========================================================================
void MovingObject::resetAnimationTime() {
    m_animationTime = sf::seconds(0);
}
//===========================================================================
sf::Sprite MovingObject::getObjectSprite() {
    return *m_objectSprite;
}

void MovingObject::setObjectSpriteOrigin(const sf::Vector2f & origin) {
    m_objectSprite->setOrigin(origin);
}

void MovingObject::setAnimationTime(const sf::Time & deltaTime) {
    m_animationTime += deltaTime;
}

sf::Time MovingObject::getAnimationTime() const {
    return m_animationTime;
}