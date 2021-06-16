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
	//void drawHelpeWindow(sf::RenderWindow& window) const;
	void setMyscreen(bool hasWon);
	void setText(sf::Text& message, std::string str, sf::Vector2f pos);
	//void stopMusic();
	bool isClickedOn(const sf::Text&, const sf::Vector2f& pos) const;
	sf::Text m_mainMsg;
	sf::Text m_enter;
	sf::Text m_exit;
	sf::Text m_help;
	sf::Text m_highScore;
	sf::Sprite m_backGround;
	//sf::Sprite m_highBackround;
	//sf::Sprite m_helpBackround;
};