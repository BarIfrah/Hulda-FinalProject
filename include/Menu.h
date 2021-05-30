#pragma once
//============================ include section ===============================
#include <SFML/Graphics.hpp>
/*============================================================================
* Class: Menu.
* This class represent the menu screen including textures, play the music 
* and handle click - play game or exit.
 ============================================================================*/
class Menu
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	Menu(
		const sf::Vector2f& size = sf::Vector2f(800,600),
		const sf::Vector2f& location = sf::Vector2f(0,0));
	//=========================== method section ==============================
	void draw(sf::RenderWindow& window);
	char handleClick(const sf::Vector2f&)const;
	bool pointingHundle(const sf::Vector2f&);
	//========================= private section ===============================
private:
	//========================= members section ===============================
	sf::Vector2f m_size;
	sf::Vector2f m_location;
	sf::Text m_startGameButton;
	sf::Text m_quitGameButton;
	sf::Sprite m_GameLogo;
	sf::Sprite m_background;
	//====================== privete methods section ==========================
	void calcLogo();
	void calcStartButton();
	void calcQuitButton();
	void calcBackground();
};