 #pragma once
#include <box2d/box2d.h>
#include "GameObject.h"
#include "Board.h"
//===========================================================================
class CollisionsListener : public b2ContactListener {
public:
	CollisionsListener()=default;
	void BeginContact(b2Contact* contact);

	void setCurrentBoard(Board&);
private:
	Board* m_board = nullptr;
};