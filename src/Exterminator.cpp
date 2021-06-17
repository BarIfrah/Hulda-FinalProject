#include "Exterminator.h"

Exterminator::Exterminator(b2World & world, const sf::Vector2f &loc, const sf::Vector2f & size, float speed)
                            : Enemy(world, loc, size, speed) {};





void Exterminator::updateAnimation(const sf::Time &deltaTime ) {
    setAnimationTime(deltaTime);
    int spritesNum = (int)(getAnimationTime().asSeconds() / ANIMATIONS_RATE);
    if (Resources::instance().getNumOfSprites(getState()) <= spritesNum)
        resetAnimationTime();
    else {
        sf::IntRect updatedRect = getIntRect();
        updatedRect.left = spritesNum * PLAYER_BOX_WIDTH;
        if (updatedRect.width < 0)
            updatedRect.left += PLAYER_BOX_WIDTH;
        //m_objectSprite->setOrigin(float(x) / 2, float(y) / 2);

        //	std::cout << m_objectSprite->getGlobalBounds().width << " " << m_objectSprite->getTextureRect().height << '\n';
        setObjectSpriteOrigin(sf::Vector2f (getObjectSprite().getTextureRect().width / 1.f, 0));
        setIntRect(updatedRect);
    }
}