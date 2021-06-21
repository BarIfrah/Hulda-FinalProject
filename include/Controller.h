#pragma once
//============================ include section ===============================
#include "Board.h"
#include "Listener.h"
#include "Menu.h"
//#include "Enemy.h"
#include "Stats.h"
#include <SFML/Graphics.hpp>
//========================== forward declarations ============================
//class MovingObject;
class Player;
/*============================================================================
* Class: Controller. 
* This class manage the game. handle all the cases that happen in the game.
* it connect between all the classes in the project.
* it can load the levels, play the turns,handle colisions
* and draw the objects of the game.
 ============================================================================*/
class Controller
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	Controller();
	//=========================== method section =============================
	void run();
	//========================= private section ==============================
private:
	//========================= members section ==============================
	//SFML:
	sf::RenderWindow m_window;
	sf::Vector2f m_CurrViewPos;
	sf::View m_screenView;
	sf::Clock m_gameClock;
	//Box2D:
	b2World* m_world = nullptr;
	Listener m_listener;
	//Other:
	Board m_board;
	Player* m_player;
	std::vector <MovingObject*> m_enemies;

	Menu m_menu;
	Stats m_stats;



	//GameState m_gameState;
	//====================== privete methods section =========================
	//char runMenu();
	void separateGameObjects(const vector<MovingObject*> &movingObjects);
	void moveCharacters();
	bool handleGameEvents(); // changed to boolean func
	void sideScroll();
	void HandleCharacterCollisionWithWindow(MovingObject*);
	void drawObjects();
	void levelUp();
	void playerDied();
	void gameOver();
};
