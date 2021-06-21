#include "Utilities.h"


void setText(sf::Text& message, std::string str, sf::Vector2f pos)
{
	message.setFont(Resources::instance().getFont());
	message.setString(str);
	message.setPosition(pos);
	message.setCharacterSize(20);
	message.setFillColor(sf::Color(255, 255, 0, 255));
}