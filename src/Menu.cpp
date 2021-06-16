#include "..\include\Menu.h"
#include <Macros.h>
#include "Resources.h"
//-----------------------------------------------------------------------------

Menu::Menu()
{
	m_backGround = sf::Sprite(Resources::instance().getTexture(MENU));
	m_backGround.setScale({ WIN_WIDTH / m_backGround.getGlobalBounds().width, WIN_HEIGHT / m_backGround.getGlobalBounds().height });

	//m_helpBackround = sf::Sprite(Resources::instance().getTexture(HELPMENU));
	//m_helpBackround.setScale({ WIN_WIDTH / m_helpBackround.getGlobalBounds().width, WIN_HEIGHT / m_helpBackround.getGlobalBounds().height });

	//m_highBackround = sf::Sprite(Resources::instance().getTexture(HIGHMENU));
	//m_highBackround.setScale({ WIN_WIDTH / m_highBackround.getGlobalBounds().width, WIN_HEIGHT / m_highBackround.getGlobalBounds().height });

	setText(m_mainMsg, "THE HULDA", { MSG_WIDTH*5.7, MSG_HEIGHT/2.5 });
	setText(m_enter, "New Game", { MSG_WIDTH*6.5, MSG_HEIGHT*1.5 });
	setText(m_exit, "Exit", { MSG_WIDTH*8, MSG_HEIGHT*4.5 });
	setText(m_help, "Help", { MSG_WIDTH*8, MSG_HEIGHT*3.5 });
	setText(m_highScore, "High Scores", { MSG_WIDTH*6, MSG_HEIGHT*2.5 });
}
//---------------------------------------------------------------------------------------------
bool Menu::runMenu(sf::RenderWindow& window, bool finished, bool hasWon)
{
	window.clear();
	if (finished)
	{
		setMyscreen(hasWon);
		setText(m_enter, "main menu", { MSG_WIDTH, MSG_HEIGHT });
	}
	drawMywindow(window);
	window.display();

	while (window.isOpen())
		for (auto event = sf::Event{}; window.waitEvent(event);)
			switch (event.type)
			{
			case sf::Event::Closed:
				return false;
			case sf::Event::MouseButtonReleased:
				auto location = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

				//if (isClickedOn(m_highScore, location))
				//{
				//	window.clear();
				//	drawHelpeWindow(window);
				//	window.display();						//go to high score screen
				//}
				//if (isClickedOn(m_help, location))
				//{
				//	window.clear();
				//	drawHighScoreWindow(window);
				//	window.display();						//go to help screen
				//}
				if (isClickedOn(m_enter, location))
				{
					return true;
				}
				if (isClickedOn(m_exit, location))
				{
					return false;
				}
			}
	return false;
}

//---------------------------------------------------------------------------------------------
//void Menu::resetMainMenu(sf::RenderWindow& window)
//{
//	setText(m_mainMsg, "lode runner - star wars edition", { MAIN_MSG_WIDTH, MAIN_MSG_HEIGHT });
//	setText(m_enter, "new game", { ENTER_WIDTH, ENTER_HEIGHT });
//	m_backGround = sf::Sprite(Textures::instance().getTexture(8));
//	m_backGround.setScale({ WIN_WIDTH / m_backGround.getGlobalBounds().width, WIN_HEIGHT / m_backGround.getGlobalBounds().height });
//}

//---------------------------------------------------------------------------------------------
void Menu::drawMywindow(sf::RenderWindow& window) const
{
	window.draw(m_backGround);
	window.draw(m_mainMsg);
	window.draw(m_enter);
	window.draw(m_exit);
	window.draw(m_help);
	window.draw(m_highScore);
}

//void Menu::drawHighScoreWindow(sf::RenderWindow& window) const
//{
//	window.draw(m_highBackround);
//}
//
//void Menu::drawHelpeWindow(sf::RenderWindow& window) const
//{
//	window.draw(m_helpBackround);
//}
//---------------------------------------------------------------------------------------------
void Menu::setMyscreen(bool hasWon)
{
	if (hasWon)
	{
		m_backGround = sf::Sprite(Resources::instance().getTexture(MENU));
		m_backGround.setScale({ WIN_WIDTH / m_backGround.getGlobalBounds().width, WIN_HEIGHT / m_backGround.getGlobalBounds().height });
		setText(m_mainMsg, "you won!", { 100, 100 });
	}
	else
	{
		m_backGround = sf::Sprite(Resources::instance().getTexture(MENU));
		m_backGround.setScale({ WIN_WIDTH / m_backGround.getGlobalBounds().width, WIN_HEIGHT / m_backGround.getGlobalBounds().height });
		setText(m_mainMsg, "game over!", { 100, 100 });
	}
}

//---------------------------------------------------------------------------------------------
void Menu::setText(sf::Text& message, std::string str, sf::Vector2f pos)
{
	message.setFont(Resources::instance().getFont());
	message.setString(str);
	message.setPosition(pos);
	message.setCharacterSize(WIN_WIDTH / 20);
	message.setFillColor(sf::Color(255, 255, 0, 255));
}
//---------------------------------------------------------------------------------------------
//void Menu::stopMusic()
//{
//	Music::instance().stopWonGame();
//	Music::instance().stopMenu();
//	Music::instance().stopLostGame();
//}

//---------------------------------------------------------------------------------------------
//checks if the specific message sent has been clicked on or not
bool Menu::isClickedOn(const sf::Text& text, const sf::Vector2f& pos) const
{
	return text.getGlobalBounds().contains(pos);
}

