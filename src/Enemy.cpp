#include "Enemy.h"

Enemy::Enemy(float distanceLim, b2World& world ,const sf::Vector2f& location, 
    const sf::Vector2f& size, char objectType, int ID)
        : MovingObject(world, location, size, objectType, ID), m_distanceLimit(distanceLim){}