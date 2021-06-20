#pragma once
//============================ include section ===============================
#include "Board.h"
#include "Listener.h"
//#include "Menu.h"
//#include "GameState.h"
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
	void handleGameEvents();
	void sideScroll();
	void HandleCharacterCollisionWithWindow(MovingObject*);
	void playerDied();
	//========================= private section ==============================
private:
	//========================= members section ==============================
	sf::RenderWindow m_window;
	//view:
	sf::Vector2f m_CurrViewPos;
	sf::View m_screenView;
	b2World* m_world = nullptr;
	Board m_board;
	Listener m_listener;
	std::vector <MovingObject*> m_enemies;
	/*
	Menu m_menu;
	GameState m_gameState;
	*/
	Player* m_player;
	sf::Clock m_gameClock;
	//====================== privete methods section =========================
	//void runGame();
	//char runMenu();
	void separateGameObjects(const vector<MovingObject*> &movingObjects);
	void moveCharacters();
	void drawObjects();
	/*void enemiesTurns(const sf::Time&);
	void play_turns(const sf::Time&);
	void playerDied();
	void levelup();
	void resetLvl();
	void gameOver();*/
};
