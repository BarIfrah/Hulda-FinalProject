#include "Enemy.h"
#include "iostream"
Enemy::Enemy(float distanceLim, b2World& world ,const sf::Vector2f& location, 
    const sf::Vector2f& size, char objectType, int ID)
        : MovingObject(world, location, size, objectType, ID), m_distanceLimit(distanceLim){
}

void Enemy::updateAnimation(const sf::Time& deltaTime) {
    setAnimationTime(deltaTime);
    int spritesNum = (int)(getAnimationTime().asSeconds() / ANIMATIONS_RATE);
    std::cout << Resources::instance().getNumOfSprites(getState())<< "\n";
    std::cout << spritesNum << "\n";
    if (Resources::instance().getNumOfSprites(ENEMY) <= spritesNum) {
        //std::cout << Resources::instance().getNumOfSprites(getState());
        resetAnimationTime();
    }
    else {
        sf::IntRect updatedRect = getIntRect();
        updatedRect.left = spritesNum * 598;
        if (updatedRect.width < 0)
            updatedRect.left += 598;
        setOrigin();
        setIntRect(updatedRect);
    }
}