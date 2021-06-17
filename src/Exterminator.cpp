#include "Exterminator.h"
#include "Macros.h"
#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <chrono>

Exterminator::Exterminator(float distanceLim,b2World& world, const sf::Vector2f& location,
	const sf::Vector2f& size, int ID)
	: Enemy(distanceLim, world, location, size, EXTERMINATOR_T, ID) {
	setDirection(RIGHT);
	flipSprite(sf::Vector2f(-1.f, 1.f));
}

//Exterminator::Exterminator(b2World & world, const sf::Vector2f &loc, const sf::Vector2f & size, float speed)
//                            : Enemy(world, loc, size, speed) {};
//




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
void Exterminator::move(const sf::Time& deltaTime, Board& currentLevel) {
	sf::Vector2f playerLocation = currentLevel.getPlayerLoc();
	b2Vec2 dirFromKey = b2Vec2(0, 0);

	//the enemy is above & right to player:
	if (this->getLocation().y < playerLocation.y && getLocation().x > playerLocation.x) {
		dirFromKey = b2Vec2(EMLEFT.x, EMDOWN.y);
		//setState(JUMP);
		updateLoc();
		//updateAnimation(deltaTime);
		if (getDirection() == RIGHT) {
			setDirection(LEFT);
			flipSprite(sf::Vector2f(-1.f, 1.f));
		}
	} //enemy is above & left to player:
	else if(this->getLocation().y < playerLocation.y && getLocation().x < playerLocation.x){
		dirFromKey = b2Vec2(EMRIGHT.x, EMDOWN.y);
		//setState(JUMP);
		updateLoc();
		//updateAnimation(deltaTime);
		if (getDirection() == LEFT) {
			setDirection(RIGHT);
			flipSprite(sf::Vector2f(-1.f, 1.f));

		}
	}
	//enemy is below & right to player:
	/*else*/ if (this->getLocation().y > playerLocation.y && getLocation().x-1 > playerLocation.x) {
		dirFromKey = b2Vec2(EMLEFT.x, EMUP.y);
		//setState(RUN);
		updateLoc();
		//updateAnimation(deltaTime);
		if (getDirection() == RIGHT) {
			setDirection(LEFT);
			flipSprite(sf::Vector2f(-1.f, 1.f));
		}
	} //enemy is below & left to player:
	else if (this->getLocation().y > playerLocation.y && getLocation().x+1 < playerLocation.x) {
		dirFromKey = b2Vec2(EMRIGHT.x, EMUP.y);
		//setState(RUN);
		updateLoc();
		//updateAnimation(deltaTime);
		if (getDirection() == LEFT) {
			setDirection(RIGHT);
			flipSprite(sf::Vector2f(-1.f, 1.f));
		}
	}
	else{
		//setState(IDLE);
	}
	//if (getState() != IDLE) ///not IDLE
		setPhysicsObjectPos(sf::Vector2f(getLocation().x + dirFromKey.x, getLocation().y
			+ dirFromKey.y), dirFromKey);
	/*else {
		updateLoc();
	}*/
}