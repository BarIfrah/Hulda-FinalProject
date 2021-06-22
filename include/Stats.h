#pragma once

#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Utilities.h"



class Stats
{
public:

	Stats(const int&);
	void draw(sf::RenderWindow&);
	void update(int, int, int, int);
	void setPosition(const sf::Vector2f &);
	bool isTimeUp();
	void levelup(int);
	int getTimeLeft();

private:

	std::vector<sf::Text> m_statInfo;
	sf::RectangleShape m_rec;
	int m_level;
	int m_score;
	int m_lives;
	int m_time;
	sf::IntRect m_lifeRec;
	sf::Time m_levelTime;
	sf::Clock m_clock;
	sf::Sprite m_lifeSprite;
};




























