#include "Menu.h"
#include <Macros.h>
#include "Resources.h"
//-----------------------------------------------------------------------------

Menu::Menu(HighScores* highScores) : m_highScores(highScores)
{
	m_backGround = sf::Sprite(Resources::instance().getTexture(MAIN_MENU_BACKGROUND));
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
	m_back2.setPosition(1620, 980);
	m_hiScore2.setPosition(100, 400);
	m_info2.setPosition(85, 250);
	m_newGame2.setPosition(100, 100);

}

//---------------------------------------------------------------------------------------------
bool Menu::runMenu(sf::RenderWindow& window, bool finished, bool hasWon)
{
	while (window.isOpen()) 
	{
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
			case sf::Event::MouseButtonReleased: {
                auto location = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});

                if (isClickedOn(m_hiScore2, location)) {
					Music::instance().stopMenu();
					Music::instance().playHiScoreMenu();
					if (!drawScoresWindow(window)) 
						return false;
                }
                if (isClickedOn(m_info2, location)) {
					Music::instance().stopMenu();
					Music::instance().playInfoMenu();
                    if (!drawHelpWindow(window))
                        return false;
                }
                if (isClickedOn(m_newGame2, location)) {
					Music::instance().stopMenu();
                    return true;
                }
                if (isClickedOn(m_back2, location)) {
					Music::instance().stopMenu();
                    return false;
                }
            }
            default:
                break;
			}
		//right here could be for ex. when the user clicked the "back" button when he was at the HiScore screen
		
	}
	return false;
}

//---------------------------------------------------------------------------------------------
void Menu::drawMywindow(sf::RenderWindow& window) const
{
	window.draw(m_backGround);
	window.draw(m_back2);
	window.draw(m_hiScore2);
	window.draw(m_info2);
	window.draw(m_newGame2);
}
//------------------------------------------------------------------------
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
					Music::instance().stopInfoMenu();
					Music::instance().playBack();
					return true;
				}
			}
}

//------------------------------------------------------------------------
bool Menu::drawScoresWindow(sf::RenderWindow& window) const
{
	sf::Vector2f backButtonPos = { 100, 550 };
	window.clear();
	m_highScores->draw(window);
	/*window.draw(m_highBackround);
	window.draw(m_back2);
	sf::Text name;
	sf::Text score;
	for (int i = 0; i < m_highScores.size(); i++)
	{
		setText(name, m_highScores[i].first, sf::Vector2f( 250, 300 + 100 * i ));
		setText(score, m_highScores[i].second, sf::Vector2f( 450, 300 + 100 * i ));
		window.draw(name);
		window.draw(score);
	}*/
	//window.draw(m_back);
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
					Music::instance().stopHiScoreMenu();
					Music::instance().playBack();
					return true;
				}
			}
}
//change to enum to know what state we are in. It depends on what state we're in to print what object we need to recognize the clicks. by the enum and clicks we change the state
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
	/*m_highScores.push_back(std::make_pair("Oren", "100"));
	m_highScores.push_back(std::make_pair("fyfyn", "854"));*/
}

