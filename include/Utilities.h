#pragma once
//============================ include section ===============================
#include <fstream> // for string
#include <SFML/Graphics.hpp>
//========================== forward declarations ============================
class Enemy;
/*============================================================================
* This file conatins a functions the help for many actions that happens in 
* the game.
 ============================================================================*/
//=========================== method section ==============================
void terminate(const std::string);
sf::Vector2f calcScale(const sf::Vector2f& size, 
const sf::Vector2f& scale, const sf::Vector2f& textureSize);
sf::Vector2f calcScreenLocation(const sf::Vector2f& ScreenSize,
	const sf::Vector2f& mapSize,
	const sf::Vector2f& location); 
sf::Vector2f calcDistance(const sf::Vector2f&, const sf::Vector2f&);
Enemy* raffleEnemy(const sf::Vector2f&, const sf::Vector2f& location);
