//============================ include section ===============================
#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
/*============================================================================*/
class Resources
{
	//========================== public section ==============================
public:
	static Resources& instance();
	//============================ gets section ===============================
//	const sf::SoundBuffer& getSound(int) const;
	const sf::Texture& getBackground();
	const sf::Texture& getTexture(int)const;
	//	const sf::Font& getFont(int)const;
	int getNumOfSprites(int)const;
		//=========================== method section ==============================
	//	void playSound(int key);
	//	void playMusic(int);
	//	void pauseMusic();
		//========================= private section ===============================
private:
	//========================= members section ===============================
	std::unordered_map<int, std::unique_ptr <sf::Texture>> m_texture;
	std::unordered_map<int, int> m_NumOfSprites;
	//	std::unordered_map<int, std::unique_ptr<sf::SoundBuffer>> m_soundBuffers;
	//	std::unordered_map<int, std::unique_ptr <sf::Font>> m_font;
	//	sf::Music m_music;
	//	sf::Sound m_sound;
	//	int m_backgroundLevelState;
		//================= constructors and destructors section =================
	Resources();
	//============================ sets section ===============================
	void setBackgrounds();
	//	void setLogos();
	//	void setFonts();
	void setObjects();
	void setNumOfSprites();
};