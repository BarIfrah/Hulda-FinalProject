#pragma once
//============================= include section ==============================
#include "Food.h"
//========================== forward declarations ============================
//class Controller;
/*============================================================================
 * Class: ToxicFood.
 * when Toxic Food objects collid with the player it's hurt the player and he
 * lost one life and score.
 */
class ToxicFood : public Food
{
public:
//=================== constractors and destractors section ===================

	ToxicFood(b2World&, const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0), int ID = 0);
	virtual ~ToxicFood() = default;
	//=========================== method section =============================
private:
};