#pragma once
//============================ include section ===============================
#include "Board.h"
//#include "Menu.h"
//#include "Enemy.h"
//#include "GameState.h"
#include <SFML/Graphics.hpp>
//#include <vector>
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
	sf::RenderWindow m_window;

	//view:
	sf::Vector2f m_CurrViewPos;
	sf::View m_screenView;

	Board m_board;
	/*
	Menu m_menu;
	GameState m_gameState;
	vector <Enemy*> m_enemies;
	std::vector<std::unique_ptr<Enemy>> m_Enemies;
	*/
	Player* m_player;
	sf::Clock m_gameClock;
	//====================== privete methods section =========================
	//void runGame();
	//char runMenu();
	void drawObjects();
	/*void enemiesTurns(const sf::Time&);
	void play_turns(const sf::Time&);
	
	void checkColisions();
	void checkEnemiesColisions();
	void checkCoinsColisions();
	void checkCollectableColisions();

	void seperateGameObjects(const vector<MovingObject*>&);

	void playerDied();
	void levelup();
	void resetLvl();
	void gameOver();*/
};
