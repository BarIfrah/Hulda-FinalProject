#include "Exterminator.h"
#include "Macros.h"
#include "Board.h"
#include <cstdlib>
//=============================================================================

Exterminator::Exterminator(float distanceLim,b2World& world, const sf::Vector2f& location,
	const sf::Vector2f& size, int ID)
	: Enemy(distanceLim, world, location, size, EXTERMINATOR_T, ID) {
	flipSprite(sf::Vector2f(-1.f, 1.f));
}
//=============================================================================

void Exterminator::setCollision(int collisionState) { m_collided = collisionState; }

//=============================================================================

void Exterminator::move(const sf::Time& deltaTime, Board& currentLevel) {
	sf::Vector2f playerLocation = currentLevel.getPlayerLoc();
	b2Vec2 dirFromKey = b2Vec2(0, 0);
	switch (m_collided)
	{
	case TRASH_C:
		if (getDirection() == RIGHT)
			dirFromKey = b2Vec2(EMRIGHT.x, EMUP.y);
		else
			dirFromKey = b2Vec2(EMLEFT.x, EMUP.y);
		m_collided = NOT_COLLIDED;
		break;
	case ADANIT_C:
		dirFromKey = b2Vec2(EMLEFT.x, EMDOWN.y);
		break;
	default:
		//the enemy is above & right to player:
		if (this->getLocation().y < playerLocation.y && getLocation().x > playerLocation.x) {
			dirFromKey = b2Vec2(MLEFT.x, 0);
			//setState(JUMP);
			//updateAnimation(deltaTime);
			
		} //enemy is above & left to player:
		else if (this->getLocation().y < playerLocation.y && getLocation().x < playerLocation.x) {
			dirFromKey = b2Vec2(MRIGHT.x, 0);
			//setState(JUMP);
			//updateAnimation(deltaTime);
		}
		//enemy is below & right to player:
		else if (this->getLocation().y > playerLocation.y && getLocation().x - 1 > playerLocation.x) {
				dirFromKey = b2Vec2(MLEFT.x, MUP.y);
				//setState(RUN);
				//updateAnimation(deltaTime);
		}
		//enemy is below & left to player:
		else if (this->getLocation().y > playerLocation.y && getLocation().x + 1 < playerLocation.x) {
			dirFromKey = b2Vec2(MRIGHT.x, MUP.y);
			//setState(RUN);
			//updateAnimation(deltaTime);
		}
		else {
			//setState(IDLE);
			//dirFromKey = b2Vec2(0, EMDOWN.y);
		}
		break;
	}
	if (getDirection() == RIGHT) {
		setDirection(LEFT);
		flipSprite(sf::Vector2f(-1.f, 1.f));
	}
	//if (getState() != IDLE) ///not IDLE
		setPhysicsObjectPos(sf::Vector2f(getLocation().x + dirFromKey.x, getLocation().y
			+ dirFromKey.y), dirFromKey);
}