#pragma once
#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "Music.h"
//-----------------------------------------------------------------------------

class Menu
{
public:
	Menu();
	//void resetMainMenu(sf::RenderWindow&);
	bool runMenu(sf::RenderWindow& window, bool, bool);

private:
	void drawMywindow(sf::RenderWindow& window) const;
	//void drawHighScoreWindow(sf::RenderWindow& window) const;
	bool drawHelpWindow(sf::RenderWindow& window) const;
	bool drawScoresWindow(sf::RenderWindow& window) const;
	void setMyscreen(bool hasWon);
	
	//void stopMusic();
	bool isClickedOn(const sf::Sprite&, const sf::Vector2f& pos) const;
	void readScores();
	sf::Text m_mainMsg;
	sf::Text m_enter;
	/*
	sf::Text m_exit;
	sf::Text m_back;
	sf::Text m_help;
	sf::Text m_highScoreBtn;*/
	sf::Sprite m_backGround;
	sf::Sprite m_highBackround;
	sf::Sprite m_helpBackground;
	sf::Sprite m_exit;
	std::vector < std::pair<std::string, std::string>> m_highScores;
	//
	sf::Sprite m_back2;
	sf::Sprite m_hiScore2;
	sf::Sprite m_info2;
	sf::Sprite m_newGame2;
};