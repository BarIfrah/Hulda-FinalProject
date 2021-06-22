#include "HighScores.h"
#include "Resources.h"
#include "Utilities.h"
#include <algorithm> 
//========================================================================
HighScores::HighScores(const sf::Vector2f& location, const sf::Vector2f& size)
	: m_location(location), m_size(size)
{

	m_background.setTexture(&Resources::instance().getTexture(HIGHMENU));
	m_background.setPosition(location);
	m_background.setSize(size);
	m_textScores.resize(4);
	setText(m_textScores[0], "Yoram - 40", { 600, 400 });
	setText(m_textScores[1], "Eran - 30", { 600, 540 });
	setText(m_textScores[2], "Lor - 20", { 600, 680 });
	setText(m_textScores[3], "Michal - 10", { 600, 820 });
}

//========================================================================

void HighScores::draw(sf::RenderWindow& window) {
	window.draw(m_background);
	for (auto& score : m_textScores)
		window.draw(score);
}

//========================================================================
/*This method get new score after the game is over and save it
	if the score is higher than the smallest score in the table score.*/

void HighScores::getNewScore(Player* player, sf::RenderWindow& window)
{
	int newScore = player->getScore();
	int min_score = *m_scores.end();
	if (newScore > min_score)
		m_scores.push_back(newScore);
	std::sort(m_scores.begin(), m_scores.end());
	m_scores.erase(m_scores.end()); 
}
