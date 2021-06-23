#pragma once
#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "Music.h"
#include "HighScores.h"
//-----------------------------------------------------------------------------

class Menu
{
public:
	Menu(HighScores *highScores);
	//void resetMainMenu(sf::RenderWindow&);
	bool runMenu(sf::RenderWindow& window, bool, bool);
	bool getExitClicked();
	void drawLostWindow(sf::RenderWindow& window) const;
	void drawWonWindow(sf::RenderWindow& window) const;

private:
	void drawMywindow(sf::RenderWindow& window) const;
	//void drawHighScoreWindow(sf::RenderWindow& window) const;
	bool drawHelpWindow(sf::RenderWindow& window) const;
	bool drawScoresWindow(sf::RenderWindow& window) const;
	void drawCreditsWindow(sf::RenderWindow& window) const;

	

	void setMyscreen(bool hasWon);
	
	//void stopMusic();
	static bool isClickedOn(const sf::Sprite&, const sf::Vector2f& pos) ;
	void readScores();
	sf::Text m_mainMsg;
	sf::Text m_enter;
	
	sf::Sprite m_menuBackGround;
	sf::Sprite m_highBackround;
	sf::Sprite m_helpBackground;
	sf::Sprite m_creditsBackground;

	sf::Sprite m_wonBackground;
	sf::Sprite m_lostBackground;

//	std::vector < std::pair<std::string, std::string>> m_highScores;
	sf::Sprite m_exitButton;
	sf::Sprite m_backButton;
	sf::Sprite m_hiScoreButton;
	sf::Sprite m_infoButton;
	sf::Sprite m_newGameButton;

	HighScores *m_highScores;

	bool m_exitClicked = false;
};