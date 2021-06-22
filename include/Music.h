#pragma once
#include <string>
#include <SFML/Audio.hpp>
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
		gameTheme,
		infoMenu
	};

	static Music& instance();
	void playEnemyAte();
	void playFood();
	void playToxicFood();
	void playMenu();
	void playGame();
	void stopMenu();
	void stopGame();
	void playLifeBonus();
	void playWonGame();
	void stopWonGame();
	void playLostGame();
	void stopLostGame();
	void playTimeEnd();
	void playBack();
	void playHiScoreMenu();
	void stopHiScoreMenu();
	void playInfoMenu();
	void stopInfoMenu();

private:
	Music();
	void loadSound(const std::string);
	const sf::SoundBuffer& getSound(const Sound) const;
	void setSounds();
	std::vector<sf::SoundBuffer> m_soundBuff;
	std::vector <sf::Sound> m_sounds;
	void loadSounds();
};