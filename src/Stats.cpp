#include "Stats.h"

Stats::Stats()
{
	m_statInfo.resize(3);
	setText(m_statInfo[0], STATS[0], { 30, 10 }); //fix, to put in macros to be able to have it in a loop
	setText(m_statInfo[1], STATS[1], { 400, 10 });
	setText(m_statInfo[2], STATS[2], { 800, 10 });
	m_rec.setSize({WIN_WIDTH, STAT_HEIGHT});
	m_rec.setPosition({ 0,0 });
	m_rec.setFillColor(sf::Color::Transparent);
	m_lives = 3;
	m_levelTime = sf::Time();
	m_clock = sf::Clock();
	m_score = 0;
	m_level = 1;
	m_lifeRec = sf::IntRect(0, 0, HEART_WIDTH * 3, 96);
	m_lifeSprite = sf::Sprite(Resources::instance().getTexture(LIFE_T), m_lifeRec);
	/*m_lifeRec.width = m_lifeSprite.getTexture()->getSize().x;
	m_lifeRec.height = m_lifeSprite.getTexture()->getSize().y;*/
	m_lifeSprite.setTextureRect(m_lifeRec);
	m_lifeSprite.setPosition(965, 20);
	m_lifeSprite.setScale(.5, .5);
}

void Stats::draw(sf::RenderWindow &window)
{
	window.draw(m_rec);
	for (auto& stat : m_statInfo)
		window.draw(stat);
	window.draw(m_lifeSprite);
}

void Stats::update(int level, int score, int lives)
{
	m_statInfo[0].setString(STATS[0] + std::to_string(level));
	m_statInfo[1].setString(STATS[1] + std::to_string(score));
	m_statInfo[2].setString(STATS[2]);
	m_lifeRec = sf::IntRect(0, 0, HEART_WIDTH * lives, 96);
	m_lifeSprite.setTextureRect(m_lifeRec);

}

void Stats::setPosition(const sf::Vector2f& newPos)
{
	m_rec.setPosition(newPos);
	setText(m_statInfo[0], STATS[0], { newPos.x + 30 , newPos.y + 10}); //fix, to put in macros to be able to have it in a loop
	setText(m_statInfo[1], STATS[1], { newPos.x + 400, newPos.y + 10 });
	setText(m_statInfo[2], STATS[2], { newPos.x + 800, newPos.y + 10 });
	m_lifeSprite.setPosition(newPos.x + 965, newPos.y + 20);
}

bool Stats::isTimeUp()
{
	if (this->m_levelTime.asSeconds() == -1)
		return false;
	return(this->m_clock.getElapsedTime().asSeconds() ==
		this->m_levelTime.asSeconds());
}

void Stats::levelup(float newLevelTime)
{
	m_levelTime = sf::seconds(newLevelTime);
	++m_level;
	m_clock.restart();
}

