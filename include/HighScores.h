#pragma once
#include "Player.h"
#include <fstream>
#include <vector>
#include <unordered_map>

class HighScores
{
public:
	HighScores(const sf::Vector2f& size = sf::Vector2f(800, 600),
		const sf::Vector2f& location = sf::Vector2f(0, 0));
	void draw(sf::RenderWindow& window);
	void getNewScore(Player*, sf::RenderWindow&);
	void readFromFile();
	std::fstream createFile();
private:

	sf::Vector2f m_size;
	sf::Vector2f m_location;
	sf::RectangleShape m_background;
	std::fstream m_filePointer;
	std::ofstream m_writer;
	//
	std::unordered_map<int, std::string> m_scoresMap;
	std::vector<int> m_scores;
	std::vector<sf::Vector2f> m_locations;
};

