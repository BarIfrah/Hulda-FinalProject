#include "Enemy.h"
#include <cstdlib>
#include <ctime>
#include <chrono>
Enemy::Enemy(b2World& world ,const sf::Vector2f& location, const sf::Vector2f& size, float speed)
        : MovingObject(world, location, size, EXTERMINATOR_T), m_distanceLimit(speed){};


void Enemy::move(const sf::Time &) {
//    srand(time(nullptr));
//    float dir;
//    int xDirection = rand() % 2; // 0 left 1 right
//    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    updateLoc();


}