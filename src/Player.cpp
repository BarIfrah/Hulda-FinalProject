//============================= include section ==============================
#include "Player.h" 
#include "SFML/Graphics.hpp"
#include "Utilities.h"
#include "Macros.h"
#include "Resources.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Player::Player(const sf::Vector2f& location,
	const sf::Vector2f& size)
	: MovingObject(location, size){
    m_physics = Physics(sf::Vector2f(0, 0), PLAYER_DRAG, PLAYER_ACCEL);
    m_state = IDLE;
}

//============================ methods section ===============================
/*this method manage the movements of the player. the method realize if the
user pressed on key and speedUpPhysicsObject the player by the key that user pressed if the
speedUp is possible.*/
//void Player::playTurn(const sf::Time& deltaTime, Board& board) {
//	
//}
void Player::move() {
    /// this is the move function in our project.

    /// WE NEED TO MAKE ANIMATION FUNC HERE
    ///now we get direction from keyboard and send it to physics.

    sf::Vector2f dirFromKey = sf::Vector2f (0, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){              ///Move Up
        /// will disappear when we add 'Jump' feature
        dirFromKey = sf::Vector2f(0.f, -1.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){     ///Move Down
        ///supposed to disappear with 'Gravity' feature
        dirFromKey = sf::Vector2f(0.f, 1.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){     ///Move Left
        dirFromKey = sf::Vector2f(-1.f, 0.f);
        m_state = LEFT;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){    ///Move Right
        dirFromKey = sf::Vector2f(1.f, 0.f);
        m_state = RIGHT;
    }
    speedUp(dirFromKey.x, dirFromKey.y);
}

void Player::slowDown() {
    m_physics.slowDownPhysicsObject();
}


void Player::speedUp(const float xDir, const float yDir) {
    m_physics.speedUpPhysicsObject(xDir, yDir);
}