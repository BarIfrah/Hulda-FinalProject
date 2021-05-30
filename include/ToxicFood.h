#pragma once
//============================= include section ==============================
#include "Food.h"
#include <sfml\Graphics.hpp>
//========================== forward declarations ============================
//class Controller;
/*============================================================================
 * Class: ToxicFood.
 * when Toxic Food objects collid with the player it's hurt the player and he
 * lost one life.
 */
class ToxicFood : public Food
{
public:
//=================== constractors and destractors section ===================

	ToxicFood(const sf::Vector2f& = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	virtual ~ToxicFood() = default;
	//=========================== method section =============================

	//virtual void handleColision(Controller&) override;
	virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
private:
};