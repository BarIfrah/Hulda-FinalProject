#pragma once
#include "Player.h"
#include <fstream>
#include <vector>
class HighScores
{
public:
	HighScores(const sf::Vector2f& size = sf::Vector2f(800, 600),
		const sf::Vector2f& location = sf::Vector2f(0, 0));
	void draw(sf::RenderWindow& window);
	void getNewScore(Player*, sf::RenderWindow&);
private:
	std::vector<int> m_scores;
	std::vector<sf::Text> m_textScores;
	sf::Vector2f m_size;
	sf::Vector2f m_location;
	sf::RectangleShape m_background;
	std::ifstream m_reader;
	std::ofstream m_writer;
};

