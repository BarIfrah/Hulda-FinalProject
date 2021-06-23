#pragma once
#include "Trash.h"

class PortalTrash: public Trash {
public:
	PortalTrash(b2World&, const sf::Vector2f&, const sf::Vector2f& , int,bool);
private:
};