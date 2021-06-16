#include "Exterminator.h"

Exterminator::Exterminator(b2World & world, const sf::Vector2f &loc, const sf::Vector2f & size, float speed)
                            : Enemy(world, loc, size, speed) {}