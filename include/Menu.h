#pragma once
#include <SFML/Graphics.hpp>
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
	void setText(sf::Text& message, std::string str, sf::Vector2f pos) const;
	//void stopMusic();
	bool isClickedOn(const sf::Text&, const sf::Vector2f& pos) const;
	void readScores();
	sf::Text m_mainMsg;
	sf::Text m_enter;
	sf::Text m_exit;
	sf::Text m_back;
	sf::Text m_help;
	sf::Text m_highScoreBtn;
	sf::Sprite m_backGround;
	sf::Sprite m_highBackround;
	sf::Sprite m_helpBackground;
	std::vector < std::pair<std::string, std::string>> m_highScores;
};