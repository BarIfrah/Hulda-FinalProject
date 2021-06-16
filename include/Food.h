#pragma once
//============================ include section ===============================
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
//========================== forward declarations ============================
class Controller;
/*============================================================================
 * Class: Food.
 * This class represent all the Food objects in the game: regular, toxic and
 * special food.
 */
class Food : public StaticObject{
public:
	//================= constractors and destractors section =================
	Food(b2World& ,const sf::Vector2f& = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0),
		char objectType = NOTHING,int ID=0);
	virtual ~Food() = default;
	//=========================== method section =============================
	virtual bool is_collected()const;
	virtual void draw(sf::RenderWindow&)override;
	/*virtual void reset();
	virtual void handleColision(Controller&)=0;*/
	virtual void collect();
	//====================== privete methods section =========================
private:
	//========================= members section ==============================
	bool m_is_collected;
};

