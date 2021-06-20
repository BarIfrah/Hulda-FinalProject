 #pragma once
//#include <box2d/box2d.h>
//#include "GameObject.h"
#include "Board.h"
//===========================================================================
class Listener : public b2ContactListener {
public:
	//CollisionsListener()=default;
	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldMainfold);
	void setCurrentBoard(Board&);
private:
	Board* m_board = nullptr;
};