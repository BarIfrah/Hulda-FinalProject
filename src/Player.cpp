//============================= include section ==============================
#include "Player.h" 
#include "SFML/Graphics.hpp"
#include "Utilities.h"
#include "Macros.h"
#include "Resources.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Player::Player(b2World& world ,const sf::Vector2f& location,
	const sf::Vector2f& size)
	: MovingObject(world, location, size, PLAYER_T){}
//============================ methods section ===============================
/*this method manage the movements of the player. the method realize if the
user pressed on key and speedUpPhysicsObject the player by the key that user pressed if the
speedUp is possible.*/
void Player::move(const sf::Time& deltaTime) {

//    switch (this->getState())
//    {
//    case JUMP:
//        updateAnimation(deltaTime);
//        break;
//    case FALL:
//        updateAnimation(deltaTime);
//        break;
//    default:
        b2Vec2 dirFromKey = b2Vec2(0, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {         ///Move Up
            dirFromKey = MUP;
            setState(JUMP);
        }
//            /// will disappear when we add 'Jump' feature
//            dirFromKey = sf::Vector2f(0.f, -1.f);
//            setPhysicsObjectPos(this->getLocation() + dirFromKey, b2Vec2(0, -100));
//            //speedUp(dirFromKey.x, dirFromKey.y);
//            this->setState(JUMP);
//        }
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {     ///Move Down
//         ///supposed to disappear with 'Gravity' feature
//            dirFromKey = sf::Vector2f(0.f, 1.f);
//            setPhysicsObjectPos(this->getLocation() + dirFromKey, b2Vec2(0, 2));
//            //speedUp(dirFromKey.x, dirFromKey.y);
//        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {     ///Move Left
            dirFromKey = MLEFT;
            setState(RUN);
            updateLoc();
//            dirFromKey = sf::Vector2f(-1.f, 0.f);
//            this->setState(RUN);
//            updateAnimation(deltaTime);
//            //speedUp(dirFromKey.x, dirFromKey.y);
//            if (this->getDirection() == RIGHT) {
//                this->setDirection(LEFT);
//                this->flipSprite(sf::Vector2f(-1.f, 1.f));
//            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {    ///Move Right
            dirFromKey = MRIGHT;
            setState(RUN);
            updateLoc();
//            this->setState(RUN);
//            updateAnimation(deltaTime);
//            // speedUp(dirFromKey.x, dirFromKey.y);
//            if (this->getDirection() == LEFT) {
//                this->setDirection(RIGHT);
//                this->flipSprite(sf::Vector2f(-1.f, 1.f));
//            }
        }
        else
            setState(IDLE);
//            if (this->getState() == RUN)
//                this->setState(IDLE);
//            else {
//                this->resetAnimationTime();
//                updateAnimation(sf::seconds(0));
//            }
//        }
    if (getState() != IDLE) ///not IDLE
         setPhysicsObjectPos(sf::Vector2f (getLocation().x + dirFromKey.x, getLocation().y + dirFromKey.y), dirFromKey);
    else
        updateLoc();
//        break;
//    }


   // updateLoc();
   // this->setLocation(m_physics.getVelocity());
}

//===========================================================================