#pragma once

#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Utilities.h"



class Stats
{
public:
	Stats();
	void draw(sf::RenderWindow&);
	void update(int, int, int);
private:
	std::vector<sf::Text> m_statInfo;
};




























