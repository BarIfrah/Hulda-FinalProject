//============================= include section ==============================
#include "Player.h" 
#include "SFML/Graphics.hpp"
#include "Utilities.h"
#include "Macros.h"
#include "Resources.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Player::Player(b2World& world ,const sf::Vector2f& location,
	const sf::Vector2f& size,int ID)
	: MovingObject(world, location, size, PLAYER_T, ID){
    setIntRect(sf::IntRect(0, 0, PLAYER_BOX_WIDTH, PLAYER_BOX_HEIGHT));
}
//============================ methods section ===============================
/*this method manage the movements of the player. the method realize if the
user pressed on key and speedUpPhysicsObject the player by the key that user pressed if the
speedUp is possible.*/
void Player::move(const sf::Time& deltaTime,Board& CurrentLevel) {
    b2Vec2 dirFromKey = b2Vec2(0, 0);
    if (getState() == DIE) {
        //updateAnimation(deltaTime);
        //TODO: resetLevel or gameOver
    }
    else {
        int state = IDLE;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {        ///Move Up
            dirFromKey = b2Vec2(getLinearVelocity().x, MUP.y);
            state = JUMP;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {     ///Move Down
            dirFromKey = b2Vec2(getLinearVelocity().x, MDOWN.y);
            state = JUMP;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {     ///Move Left
            dirFromKey = b2Vec2(MLEFT.x, getLinearVelocity().y);
            state = RUN;
            if (getDirection() == RIGHT) {
                setDirection(LEFT);
                flipSprite(sf::Vector2f(-1.f, 1.f));
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { ///Move Right
            dirFromKey = b2Vec2(MRIGHT.x, getLinearVelocity().y);
            state = RUN;
            if (getDirection() == LEFT) {
                setDirection(RIGHT);
                flipSprite(sf::Vector2f(-1.f, 1.f));
            }
        }
        else {
            state = IDLE;
            setState(IDLE, PLAYER_BOX_HEIGHT, PLAYER_BOX_WIDTH);
            dirFromKey = b2Vec2(getLinearVelocity().x, MDOWN.y);
        }


        if (state != IDLE) { ///not IDLE
            setState(state, PLAYER_BOX_HEIGHT, PLAYER_BOX_WIDTH);
            updateLoc();
            setPhysicsObjectPos(sf::Vector2f(getLocation().x + dirFromKey.x,
                getLocation().y + dirFromKey.y), dirFromKey);
            updateAnimation(deltaTime);
        }
        else {
            updateLoc();
            //updateAnimation(deltaTime);
        }
    }
}

//===========================================================================
void Player::updateAnimation(const sf::Time &deltaTime ) {
    setAnimationTime(deltaTime);
    int spritesNum = (int)(getAnimationTime().asSeconds() / ANIMATIONS_RATE);
    if (Resources::instance().getNumOfSprites(getState()) <= spritesNum)
        resetAnimationTime();
    else {
        sf::IntRect updatedRect = getIntRect();
        updatedRect.left = spritesNum * PLAYER_BOX_WIDTH;
        if (updatedRect.width < 0) {
            updatedRect.left += PLAYER_BOX_WIDTH;

        }
        setOrigin();
        setIntRect(updatedRect);
    }
}