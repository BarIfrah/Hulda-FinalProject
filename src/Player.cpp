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
	: MovingObject(world, location, size, PLAYER_T, ID){}
//============================ methods section ===============================
/*this method manage the movements of the player. the method realize if the
user pressed on key and speedUpPhysicsObject the player by the key that user pressed if the
speedUp is possible.*/
void Player::move(const sf::Time& deltaTime) {
        b2Vec2 dirFromKey = b2Vec2(0, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && ///Jump Up & Right
            sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            dirFromKey = MUP_RIGHT;
            if (getDirection() == LEFT) {
                setDirection(RIGHT);
                flipSprite(sf::Vector2f(-1.f, 1.f));
            }
            setState(JUMP);
            updateLoc();
            updateAnimation(deltaTime);
        }
        else{
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && ///Jump Up & Left
                sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                dirFromKey = MUP_LEFT;
                if (getDirection() == RIGHT) {
                    setDirection(LEFT);
                    flipSprite(sf::Vector2f(-1.f, 1.f));
                }
                setState(JUMP);
                updateLoc();
                updateAnimation(deltaTime);
            }
            else {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {        ///Move Up
                    dirFromKey = MUP;
                    setState(JUMP);
                    updateLoc();
                    updateAnimation(deltaTime);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {     ///Move Down
                    dirFromKey = MDOWN;
                    setState(JUMP);
                    updateLoc();
                    updateAnimation(deltaTime);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {     ///Move Left
                    dirFromKey = MLEFT;
                    setState(RUN);
                    updateLoc();
                    updateAnimation(deltaTime);
                    if (getDirection() == RIGHT) {
                        setDirection(LEFT);
                        flipSprite(sf::Vector2f(-1.f, 1.f));
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { ///Move Right
                    dirFromKey = MRIGHT;
                    setState(RUN);
                    updateLoc();
                    updateAnimation(deltaTime);
                    if (getDirection() == LEFT) {
                        setDirection(RIGHT);
                        flipSprite(sf::Vector2f(-1.f, 1.f));
                    }
                }
                else
                    setState(IDLE);
            }
        }
        
    if (getState() != IDLE) ///not IDLE
         setPhysicsObjectPos(sf::Vector2f (getLocation().x + dirFromKey.x, getLocation().y
             + dirFromKey.y), dirFromKey);
    else {
        updateLoc();
    }
}

//===========================================================================