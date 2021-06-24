#pragma once
#include <string>
#include <SFML/Audio.hpp>
#include <unordered_map>
//-----------------------------------------------------------------------------


class Music
{
public:
	enum class Sound
	{
		menu,
		eatFood,
		eatToxic,
		enemyAte,
		wonGame,
		life1up,
		lostGame,
		timeEnd,
		back,
		hiScore,
		level1,
		infoMenu,
		SpecialFood,
		credits,
		level2,
		level3,
		level4,
		level5
	};

	static Music& instance();
	void playEnemyAte();
	void playFood();
	void playToxicFood();
	void playMenu();
	void playLevelMusic(const int&);
	void stopMenu();
	void stopGame();
	void playWonGame();
	void stopWonGame();
	void playLostGame();
	void playBack();
	void playHiScoreMenu();
	void stopHiScoreMenu();
	void playInfoMenu();
	void stopInfoMenu();
	void playSpecialFood();
	void playCredits();
	void stopCredits();
	void stopLevelMusic(const int& level);
	

private:
	Music();
	void loadSound(std::string);
	const sf::SoundBuffer& getSound(Sound) const;
	void setSounds();
	std::vector<sf::SoundBuffer> m_soundBuff;
	std::vector <sf::Sound> m_sounds;
	void loadSounds();
};











