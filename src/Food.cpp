//============================= include section ==============================
#include "Food.h"
#include "SFML/Graphics.hpp"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Food::Food(b2World& world, const sf::Vector2f& location,
	const sf::Vector2f& size,
	char objectType)
	: StaticObject(world, location, size, objectType),
	m_is_collected(false) {}
//============================== gets section ================================
//============================ methods section ===============================
//bool Food::is_collected()const { return (this->m_is_collected); }
////============================================================================
//void Food::draw(sf::RenderWindow& window) {
//	if (!this->m_is_collected)
//		this->GameObject::draw(window);
//}
////============================================================================
//void Food::reset() {
//	this->GameObject::reset();
//	this->m_is_collected = false;
//}
////============================================================================
///*this method change the state of the coin after the player collected it.*/
//void Foodt::collect() { this->m_is_collected = true; }
