#include "..\include\Menu.h"
#include <Macros.h>
#include "Resources.h"
//-----------------------------------------------------------------------------

Menu::Menu()
{
	m_backGround = sf::Sprite(Resources::instance().getTexture(MENU_BACKGROUND));
	m_backGround.setScale({ WIN_WIDTH / m_backGround.getGlobalBounds().width, WIN_HEIGHT / m_backGround.getGlobalBounds().height });

	m_helpBackground = sf::Sprite(Resources::instance().getTexture(HELPMENU));
	m_helpBackground.setScale({ WIN_WIDTH / m_helpBackground.getGlobalBounds().width, WIN_HEIGHT / m_helpBackground.getGlobalBounds().height });
	readScores();
	m_highBackround = sf::Sprite(Resources::instance().getTexture(HIGHMENU));
	m_highBackround.setScale({ WIN_WIDTH / m_highBackround.getGlobalBounds().width, WIN_HEIGHT / m_highBackround.getGlobalBounds().height });

	m_back2 = sf::Sprite(Resources::instance().getTexture(BACK_KEY));
	m_hiScore2 = sf::Sprite(Resources::instance().getTexture(HI_SCORE_KEY));
	m_info2 = sf::Sprite(Resources::instance().getTexture(INFO_KEY));
	m_newGame2 = sf::Sprite(Resources::instance().getTexture(NEW_GAME_KEY));
	m_back2.setPosition(800, 680);
	m_hiScore2.setPosition(800, 300);
	m_info2.setPosition(800, 480);
	m_newGame2.setPosition(800, 100);


	/*setText(m_mainMsg, "THE HULDA", { MSG_WIDTH*5.7, MSG_HEIGHT/2.5 });
	setText(m_enter, "New Game", { MSG_WIDTH*6.5, MSG_HEIGHT*1.5 });
	setText(m_exit, "Exit", { MSG_WIDTH*8, MSG_HEIGHT*4.5 });
	setText(m_help, "Help", { MSG_WIDTH*8, MSG_HEIGHT*3.5 });
	setText(m_highScoreBtn, "High Scores", { MSG_WIDTH*6, MSG_HEIGHT*2.5 });
	setText(m_back, "Back", { 10, 10 });*/
}

//---------------------------------------------------------------------------------------------
bool Menu::runMenu(sf::RenderWindow& window, bool finished, bool hasWon)
{
	while (window.isOpen()) {
		window.clear();
		if (finished)
		{
			setMyscreen(hasWon);
			setText(m_enter, "main menu", { MSG_WIDTH, MSG_HEIGHT });
		}
		drawMywindow(window);
		window.display();
		if (auto event = sf::Event{}; window.pollEvent(event))
			switch (event.type)
			{
			case sf::Event::Closed:
				return false;
			case sf::Event::MouseButtonReleased:
				auto location = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

				if (isClickedOn(m_hiScore2, location))
				{
					if (!drawScoresWindow(window))
						return false;
				}
				if (isClickedOn(m_info2, location))
				{
					if (!drawHelpWindow(window))
						return false;
				}
				if (isClickedOn(m_newGame2, location))
				{
					return true;
				}
				if (isClickedOn(m_back2, location))
				{
					return false;
				}
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
	/*window.draw(m_backGround);
	window.draw(m_mainMsg);
	window.draw(m_enter);
	window.draw(m_exit);
	window.draw(m_help);
	window.draw(m_highScoreBtn);*/
	window.draw(m_backGround);
	window.draw(m_back2);
	window.draw(m_hiScore2);
	window.draw(m_info2);
	window.draw(m_newGame2);

}

bool Menu::drawHelpWindow(sf::RenderWindow& window) const
{
	window.clear();
	window.draw(m_helpBackground);
	window.draw(m_back2);
	window.display();
	while (window.isOpen())
		for (auto event = sf::Event{}; window.waitEvent(event);)
			switch (event.type)
			{
			case sf::Event::Closed:
				return false;
			case sf::Event::MouseButtonReleased:
				auto location = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

				if (isClickedOn(m_back2, location))
				{
					return true;
				}
			}
}

bool Menu::drawScoresWindow(sf::RenderWindow& window) const
{
	window.clear();
	window.draw(m_highBackround);
	sf::Text name;
	sf::Text score;
	for (int i = 0; i < m_highScores.size(); i++)
	{
		setText(name, m_highScores[i].first, sf::Vector2f( 250, 300 + 100 * i ));
		setText(score, m_highScores[i].second, sf::Vector2f( 450, 300 + 100 * i ));
		window.draw(name);
		window.draw(score);
	}
	window.draw(m_back);
	window.display();
	while (window.isOpen())
		for (auto event = sf::Event{}; window.waitEvent(event);)
			switch (event.type)
			{
			case sf::Event::Closed:
				return false;
			case sf::Event::MouseButtonReleased:
				auto location = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

				if (isClickedOn(m_back2, location))
				{
					return true;
				}
			}
}
// change to enum to know what state we are in. depends what state we are in to print whicvh object and which object we need to find the clicks. by the enum and clicks we change the state
//
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

//---------------------------------------------------------------------------------------------
//void Menu::stopMusic()
//{
//	Music::instance().stopWonGame();
//	Music::instance().stopMenu();
//	Music::instance().stopLostGame();
//}

//---------------------------------------------------------------------------------------------
//checks if the specific message sent has been clicked on or not
bool Menu::isClickedOn(const sf::Sprite& text, const sf::Vector2f& pos) const
{
	return text.getGlobalBounds().contains(pos);
}

void Menu::readScores()
{
	m_highScores.push_back(std::make_pair("Oren", "100"));
	m_highScores.push_back(std::make_pair("fyfyn", "854"));
}
