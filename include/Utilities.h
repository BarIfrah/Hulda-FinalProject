#pragma once
//============================ include section ===============================
#include <fstream> // for string
#include <SFML/Graphics.hpp>
#include <Resources.h>
#include "Macros.h"
//========================== forward declarations ============================
class Enemy;
/*============================================================================
* This file conatins a functions the help for many actions that happens in 
* the game.
 ============================================================================*/
//=========================== method section ==============================
sf::Vector2f calcScale(const sf::Vector2f& size,
const sf::Vector2f& scale, const sf::Vector2f& textureSize);
sf::Vector2f calcScreenLocation(const sf::Vector2f& ScreenSize,
	const sf::Vector2f& mapSize,
	const sf::Vector2f& location);
float calcDistance(const sf::Vector2f&, const sf::Vector2f&);

void setText(sf::Text& message, std::string str, sf::Vector2f pos);