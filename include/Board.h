#pragma once
//============================ include section ===============================
#include <vector>
#include "DataReader.h"
#include "GameObject.h"
#include "MovingObject.h"
#include <unordered_map>
#include "Collisions.h"
//========================== forward declarations ============================
//class MovingObject;
//class GameObject;
//class StaticObject;
//class Enemy;
class Player;
//class Food;
//============================== using section ===============================
using std::vector;
/*============================================================================
 * Class: Board.
 * the board contain and draw the level's objects.
 * alse the board helps the 
 * read the levels from the file by one of its member.
 * also the board help
 */
class Board
{
public:
	//================= constructors and destructors section =================
	Board(const sf::Vector2f& location = sf::Vector2f(0,0),
		const sf::Vector2f& size = sf::Vector2f(0,0));
	~Board() = default;
	//============================ gets section ==============================
	int getLevelTime()const;
	const sf::Vector2f& getLevelSize() const;
	const sf::Vector2f& getLocation() const;
	sf::Vector2f getObjectSize()const;
	GameObject* getObjWithId(int);
	Collisions getCollisionObj() const { return m_collision; }
	const sf::Vector2f& getPlayerLoc()const;
	//=========================== method section =============================
	void draw(sf::RenderWindow& window, const sf::Time&);
	std::vector<MovingObject*> loadNewLevel(b2World&);
	bool is_next_lvl_exist()const;
	//void gameOver();
	void loadLevelEffects(int);
	std::vector<MovingObject*> resetLevel(b2World&);
private:
	//========================= members section ==============================
	vector<vector<std::unique_ptr<GameObject>>> m_map;
	vector<vector<char>> m_charactersMap;
	std::unordered_map<int, GameObject*> m_ObjWithID;
	sf::Vector2f m_location;
	DataReader m_levelReader;
	sf::RectangleShape m_background;
	Player* m_player;
	Collisions m_collision;
	//std::vector<std::unique_ptr<Food>> m_CollectedFood = {};
	//====================== privete methods section =========================
	void clearParameters();
	//Food* raffleFood(const sf::Vector2f& boxSize,const sf::Vector2i& index);	
};