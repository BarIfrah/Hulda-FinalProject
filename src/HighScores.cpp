#include "HighScores.h"
#include "Resources.h"
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <algorithm> 
//========================================================================
HighScores::HighScores(const sf::Vector2f& location, const sf::Vector2f& size)
	: m_location(location), m_size(size)
{

	m_background.setTexture(&Resources::instance().getTexture(HIGHMENU));
	m_background.setPosition(location);
	m_background.setSize(size);
	//
	m_locations.push_back({ 570,420 });
	m_locations.push_back({ 570,560 });
	m_locations.push_back({ 570,700 });
	m_locations.push_back({ 570,840 });

	readFromFile();
}

//========================================================================

void HighScores::draw(sf::RenderWindow& window) {
	window.draw(m_background);

	sf::Text score;

	for (int i = 0; i < m_scores.size() && i < 4; i++)
	{
		setText(score, m_scores[i].first + " - " + std::to_string(m_scores[i].second), m_locations[i]);
		window.draw(score);
	}
}

//========================================================================
/*This method gets new score after the game is over and saves it
	if the score is higher than the smallest score in the table score.*/

void HighScores::getNewScore(Player* player, sf::RenderWindow& window)
{
	int score = player->getScore();
	
	sf::Text scoreT;
	sf::Text enterName;
	sf::Text nameText;

	//fix movement adding lives
	sf::RectangleShape background;
	background.setPosition(sf::Vector2f(0,0));
	background.setSize(m_background.getSize());
	background.setFillColor(sf::Color::White);

	scoreT.setFont(Resources::instance().getFont());
	scoreT.setCharacterSize(80);

	scoreT.setString("Your final score is: " + std::to_string(score));

	scoreT.setColor(sf::Color::Red);
	scoreT.setPosition(sf::Vector2f(0, window.getSize().y / 3));

	enterName.setFont(Resources::instance().getFont());
	enterName.setCharacterSize(80);
	enterName.setString("Whats your name? (press enter to finish)");
	enterName.setColor(sf::Color::Black);
	enterName.setPosition(sf::Vector2f(0, window.getSize().y / 3 + 100));

	nameText.setFont(Resources::instance().getFont());
	nameText.setCharacterSize(80);
	nameText.setString("");
	nameText.setColor(sf::Color::Black);
	nameText.setPosition(sf::Vector2f(0, window.getSize().y / 3 + 180));

	std::string name;

	while (window.isOpen() && name.size() < 10)
	{
		window.clear();
		window.draw(background);
		window.draw(scoreT);
		window.draw(enterName);
		window.draw(nameText);
		window.display();

		if (auto event = sf::Event{}; window.pollEvent(event))
		{
			switch (event.type)
			{
                case sf::Event::Closed:
                    window.close();
                    break;
			    case sf::Event::KeyPressed: {
                    if (event.key.code == sf::Keyboard::Enter)
                        break;
                }
			case sf::Event::TextEntered:
			{
				if (event.text.unicode == ENTER) 
					goto out;

				else if (event.text.unicode == SPACE); 

				else if (event.text.unicode == DELETE) 
				{
					if (name.size() > 0)
						name.pop_back();
					nameText.setString(name);

                    }
                    else if (event.text.unicode < 128)
                    {
                        char a = char(event.text.unicode);
                        name.append(1, a);
                        nameText.setString(name);

                    }
                }
			}
		}
	}

	out:
	if (name.size() == 0)
		name.append("NONAME");

	m_scores.push_back(std::make_pair(name, score));
	std::sort(m_scores.begin(), m_scores.end());
}

//============================================================================

void HighScores::readFromFile()
{
	std::string name; 
	std::string score;

	m_filePointer.open("highscores.txt");

	if (!m_filePointer.is_open())
	{
		m_filePointer = createFile();
	}

	while (!m_filePointer.eof())
	{
		if (!(m_filePointer >> name >> score))
			break;
		m_scores.push_back(std::make_pair(name, std::stoi(score)));
	}
}

//============================================================================

std::fstream HighScores::createFile()
{
	std::fstream newFile;

	newFile.open("highscores.txt", std::ios::in | std::ios::out | std::ios::app);

	if (!newFile)
	{
		//std::cout << "could not create file" << std::endl;
		exit(EXIT_FAILURE);
	}

	return newFile;
}



