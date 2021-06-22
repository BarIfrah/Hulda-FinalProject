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
	const sf::Texture& getBackground();
	const sf::Texture& getTexture(int)const;
	const sf::Font& getFont() const;
	int getNumOfSprites(int)const;
//========================= private section ===============================
private:
	//========================= members section ===============================
	std::unordered_map<int, std::unique_ptr <sf::Texture>> m_texture;
	std::unordered_map<int, int> m_NumOfSprites;
	sf::Font m_font;
		//================= constructors and destructors section =================
	Resources();
	//============================ sets section ===============================
	void setBackgrounds();
	void setObjects();
	void setNumOfSprites();
};