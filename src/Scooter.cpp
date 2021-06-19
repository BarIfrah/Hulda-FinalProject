#include "Scooter.h"
#include "Macros.h"

Scooter::Scooter(float distanceLim, b2World& world, const sf::Vector2f& location,
	const sf::Vector2f& size, int ID)
	: Enemy(distanceLim, world, location, size, SCOOTER_T, ID) {}

void Scooter::move(const sf::Time& deltaTime, Board& board) {
	b2Vec2 dirFromKey = b2Vec2(0, 0);
	if (getDirection() == RIGHT) 
		dirFromKey = MRIGHT;
	else 
		dirFromKey = MLEFT;
	
	//updateAnimation(deltaTime);
	setPhysicsObjectPos(sf::Vector2f(getLocation().x + dirFromKey.x, getLocation().y
		+ dirFromKey.y), dirFromKey);
	//flipSprite executed in the collision func
}