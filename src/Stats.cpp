#include "..\include\Stats.h"

Stats::Stats()
{
	m_statInfo.resize(3);
	setText(m_statInfo[0], STATS[0], { 30, 700 }); //fix, to put in macros to be able to have it in a loop
	setText(m_statInfo[1], STATS[1], { 400, 700 });
	setText(m_statInfo[2], STATS[2], { 800, 700 });

}

void Stats::draw(sf::RenderWindow &window)
{
	auto rec = sf::RectangleShape({ WIN_WIDTH, STAT_HEIGHT });
	rec.setPosition({ 0, WIN_HEIGHT - STAT_HEIGHT - 1 });
	rec.setFillColor(sf::Color::Magenta);
	window.draw(rec);
	for (auto& stat : m_statInfo)
		window.draw(stat);
}

void Stats::update(int level, int score, int lives)
{
	m_statInfo[0].setString(STATS[0] + std::to_string(level));
	m_statInfo[1].setString(STATS[1] + std::to_string(score));
	m_statInfo[2].setString(STATS[2] + std::to_string(lives));
}
