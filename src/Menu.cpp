#include "Menu.h"
#include <Macros.h>
#include "Resources.h"
//-----------------------------------------------------------------------------

Menu::Menu(HighScores *highScores) : m_highScores(highScores)
{
	m_menuBackGround = sf::Sprite(Resources::instance().getTexture(MAIN_MENU_BACKGROUND));
	m_menuBackGround.setScale({ WIN_WIDTH / m_menuBackGround.getGlobalBounds().width, WIN_HEIGHT / m_menuBackGround.getGlobalBounds().height });

	m_helpBackground = sf::Sprite(Resources::instance().getTexture(HELP_KEY));
	m_helpBackground.setScale({ WIN_WIDTH / m_helpBackground.getGlobalBounds().width, WIN_HEIGHT / m_helpBackground.getGlobalBounds().height });
	readScores();
	m_highBackround = sf::Sprite(Resources::instance().getTexture(HIGHMENU));
	m_highBackround.setScale({ WIN_WIDTH / m_highBackround.getGlobalBounds().width, WIN_HEIGHT / m_highBackround.getGlobalBounds().height });

	m_wonBackground = sf::Sprite(Resources::instance().getTexture(NEW_WON_KEY));
	m_wonBackground.setScale({ WIN_WIDTH / m_wonBackground.getGlobalBounds().width, WIN_HEIGHT / m_wonBackground.getGlobalBounds().height });
	/*m_wonBackground = sf::RectangleShape();
	m_wonBackground.setTexture(&Resources::instance().getTexture(WON_KEY));
	m_wonBackground.setPosition(sf::Vector2f(0, 0));
	m_wonBackground.setSize({ 1920, 1080 });*/
	//m_wonBackground.setScale({ WIN_WIDTH / m_wonBackground.getGlobalBounds().width, WIN_HEIGHT / m_wonBackground.getGlobalBounds().height });

	m_lostBackground = sf::Sprite(Resources::instance().getTexture(LOST_KEY));
	m_lostBackground.setScale({ WIN_WIDTH / m_lostBackground.getGlobalBounds().width, WIN_HEIGHT / m_lostBackground.getGlobalBounds().height });

	m_backButton = sf::Sprite(Resources::instance().getTexture(BACK_KEY));
	m_hiScoreButton = sf::Sprite(Resources::instance().getTexture(HI_SCORE_KEY));
	m_infoButton = sf::Sprite(Resources::instance().getTexture(INFO_KEY));
	m_newGameButton = sf::Sprite(Resources::instance().getTexture(NEW_GAME_KEY));
	m_exitButton = sf::Sprite(Resources::instance().getTexture(EXIT_KEY));

	m_creditsBackground = sf::Sprite(Resources::instance().getTexture(CREDITS_KEY));


	m_backButton.setPosition(1620, 980);
	m_hiScoreButton.setPosition(100, 400);
	m_infoButton.setPosition(85, 250);
	m_newGameButton.setPosition(100, 100);
	m_exitButton.setPosition(1620, 980);

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

                if (isClickedOn(m_hiScoreButton, location)) {
					Music::instance().stopMenu();
					Music::instance().playHiScoreMenu();
					if (!drawScoresWindow(window)) 
						return false;
                }
                if (isClickedOn(m_infoButton, location)) {
					Music::instance().stopMenu();
					Music::instance().playInfoMenu();
                    if (!drawHelpWindow(window))
                        return false;
                }
                if (isClickedOn(m_newGameButton, location)) {
					Music::instance().stopMenu();
                    return true;
                }
                if (isClickedOn(m_exitButton, location)) {
					m_exitClicked = true;
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

bool Menu::getExitClicked()
{
	return m_exitClicked;
}

//---------------------------------------------------------------------------------------------
void Menu::drawMywindow(sf::RenderWindow& window) const
{
	window.draw(m_menuBackGround);
	window.draw(m_exitButton);
	window.draw(m_hiScoreButton);
	window.draw(m_infoButton);
	window.draw(m_newGameButton);
}
//------------------------------------------------------------------------
bool Menu::drawHelpWindow(sf::RenderWindow& window) const
{
	window.clear();
	window.draw(m_helpBackground);
	window.draw(m_backButton);
	window.display();
	while (window.isOpen())
		for (auto event = sf::Event{}; window.waitEvent(event);)
			switch (event.type)
			{
			case sf::Event::Closed: {
                return false;
            }
			case sf::Event::MouseButtonReleased: {
                auto location = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});

                if (isClickedOn(m_backButton, location)) {
                    Music::instance().stopInfoMenu();
                    Music::instance().playBack();
                    return true;
                }
            }
            default:
                break;
			}
    return false;
}

//------------------------------------------------------------------------
bool Menu::drawScoresWindow(sf::RenderWindow& window) const
{
//	sf::Vector2f backButtonPos = { 100, 550 };
	window.clear();
	m_highScores->draw(window);
//	window.draw(m_highBackround);
//	window.draw(m_back);
//	sf::Text name;
//	sf::Text score;
//	for (int i = 0; i < m_highScores.size(); i++)
//	{
//		setText(name, m_highScores[i].first, sf::Vector2f( 250, 300 + 100 * i ));
//		setText(score, m_highScores[i].second, sf::Vector2f( 450, 300 + 100 * i ));
//		window.draw(name);
//		window.draw(score);
//	}
    window.draw(m_backButton);
    window.display();
    while (window.isOpen())
        for (auto event = sf::Event{}; window.waitEvent(event);)
            switch (event.type)
            {
                case sf::Event::Closed:
                    return false;
                case sf::Event::MouseButtonReleased: {
                    auto location = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});

                    if (isClickedOn(m_backButton, location)) {
                        Music::instance().stopHiScoreMenu();
                        Music::instance().playBack();
                        return true;
                    }
                }
                default:;
            }
    return false;
}


//change to enum to know what state we are in. It depends on what state we're in to print what object we need to recognize the clicks. by the enum and clicks we change the state
//
//---------------------------------------------------------------------------------------------
void Menu::setMyscreen(bool hasWon)
{
	if (hasWon)
	{
		m_menuBackGround = sf::Sprite(Resources::instance().getTexture(MENU));
		m_menuBackGround.setScale({ WIN_WIDTH / m_menuBackGround.getGlobalBounds().width, WIN_HEIGHT / m_menuBackGround.getGlobalBounds().height });
		setText(m_mainMsg, "you won!", { 100, 100 });
	}
	else
	{
		m_menuBackGround = sf::Sprite(Resources::instance().getTexture(MENU));
		m_menuBackGround.setScale({ WIN_WIDTH / m_menuBackGround.getGlobalBounds().width, WIN_HEIGHT / m_menuBackGround.getGlobalBounds().height });
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
bool Menu::isClickedOn(const sf::Sprite& text, const sf::Vector2f& pos)
{
	return text.getGlobalBounds().contains(pos);
}

void Menu::readScores()
{
//	m_highScores.push_back(std::make_pair("Oren", "100"));
//	m_highScores.push_back(std::make_pair("fyfyn", "854"));
}

void Menu::drawCreditsWindow(sf::RenderWindow& window) const
{
	
}

void Menu::drawLostWindow(sf::RenderWindow& window) const
{
	//window.clear();
	window.draw(m_lostBackground);
	window.display();
	while (window.isOpen())
		for (auto event = sf::Event{}; window.waitEvent(event);)
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				return;
			default:
				break;
			}
}

void Menu::drawWonWindow(sf::RenderWindow& window) const
{
	//window.clear();
	window.draw(m_wonBackground);
	window.display();
	while (window.isOpen())
		for (auto event = sf::Event{}; window.waitEvent(event);)
			switch (event.type)
			{
			case sf::Event::KeyPressed: 
				return;
			default:
				break;
			}
}

