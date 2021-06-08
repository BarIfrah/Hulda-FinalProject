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
	: MovingObject(location, size){}
//============================ methods section ===============================
/*this method manage the movements of the player. the method realize if the
user pressed on key and move the player by the key that user pressed if the
move is possible.*/
//void Player::playTurn(const sf::Time& deltaTime, Board& board) {
//	
//}

