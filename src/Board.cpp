/*
   This file conatains all methods of the class Board.
*/
//============================= include section ==========================
#include "Board.h"
#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Macros.h"
#include "Resources.h"
#include <vector>
#include "Utilities.h"
#include "Player.h"
#include "Road.h"
#include "Adanit.h"
#include "Trash.h"
#include "SpecialFood.h"
#include "Exterminator.h"
#include "Scooter.h"
using std::vector;
//====================== Constructors & distructors section ==================
Board::Board(const sf::Vector2f& location,
	const sf::Vector2f& size)
	: m_levelReader(DataReader()),
	m_background(sf::RectangleShape()),
	m_location(location),
	m_player(nullptr){
	this->m_background.setSize(size);
	m_background.setPosition(m_location);
	this->loadLevelEffects(0);
	m_map.clear();
}
//================================ gets section ==============================
//============================================================================
const sf::Vector2f& Board::getLevelSize()const {
    return m_background.getSize();
}
//============================================================================
const sf::Vector2f& Board::getLocation() const {
	return this->m_location;
}
//============================================================================
int Board::getLevelTime()const {
	return this->m_levelReader.getLevelTime();
}
//============================================================================
const sf::Vector2f& Board::getPlayerLoc()const {
	return this->m_player->getLocation();
}
//============================================================================
sf::Vector2f Board::getObjectSize()const {
	return sf::Vector2f{getLevelSize().x / m_map[0].size(),
                         getLevelSize().y / m_map.size() };
}
//============================ methods section ===============================
void Board::draw(sf::RenderWindow& window, const sf::Time& deltaTime) {
	window.draw(m_background);
	for (int i = 0; i < this->m_map.size(); i++)
		for (int j = 0; j < this->m_map[i].size(); j++) {
			if (m_map[i][j].get() != nullptr) {
				m_map[i][j]->draw(window);
			}
		}
}
//============================================================================
/*
 * This function update the objects of the game to the current level game.
 * the function build a vector of moving objects ptrs & return it.
 */
std::vector<MovingObject*> Board::loadNewLevel(b2World& world) {
	vector<vector<char>> map = m_levelReader.readNextLevel();
	//vector<MovingObject*> movingsVec = {};
	sf::Vector2f boxSize(getLevelSize().x / map[0].size(),
                         getLevelSize().y / map.size());
	vector<MovingObject*> movingsVec = {};
	loadLevelEffects(1);

	//reset last load parameters:
	clearParameters();
	m_map.resize(map.size());

	int ID = 0;

	//allocating level's objects:
	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
			switch (map[y][x])
			{
			case PLAYER: {
                m_map[y].push_back(std::make_unique<Player>(world, sf::Vector2f
				(boxSize.x * x, boxSize.y * y),sf::Vector2f(2 * boxSize.x, 2 * boxSize.y), ID));
                movingsVec.push_back((MovingObject*)this->m_map[y][x].get());
                m_player = (Player *) m_map[y][x].get();
                m_ObjWithID.insert(std::pair<int, GameObject *>(ID, m_map[y][x].get()));
                ID++;
                break;
            }
            case EXTERMINATOR: {
                m_map[y].push_back(std::make_unique<Exterminator>(ENEMY_DISTANCE_LIMIT ,world, sf::Vector2f
				(boxSize.x * x, boxSize.y * y) ,sf::Vector2f(2 * boxSize.x, 2 * boxSize.y), ID));
                movingsVec.push_back((MovingObject*)this->m_map[y][x].get());
				m_ObjWithID.insert(std::pair<int, GameObject*>(ID, m_map[y][x].get()));
				ID++;
                break;
            }
			case SCOOTER: {
				m_map[y].push_back(std::make_unique<Scooter>(ENEMY_DISTANCE_LIMIT, world, sf::Vector2f
				(boxSize.x * x, boxSize.y * y), sf::Vector2f(2 * boxSize.x, 2 * boxSize.y), ID));
				movingsVec.push_back((MovingObject*)this->m_map[y][x].get());
				m_ObjWithID.insert(std::pair<int, GameObject*>(ID, m_map[y][x].get()));
				ID++;
				break;
			}
			case ROAD:
				m_map[y].push_back(std::make_unique <Road>(world, sf::Vector2f
				(boxSize.x * x, boxSize.y * y) , sf::Vector2f(boxSize.x, boxSize.y),ID));
				m_ObjWithID.insert(std::pair<int, GameObject*>(ID, m_map[y][x].get()));
				ID++;
				break;
			case ADANIT:
				m_map[y].push_back(std::make_unique <Adanit>(world, sf::Vector2f
				(boxSize.x * x, boxSize.y * y) , sf::Vector2f(boxSize.x, boxSize.y), ID));
				m_ObjWithID.insert(std::pair<int, GameObject*>(ID, m_map[y][x].get()));
				ID++;
				break;
			case TRASH:
				m_map[y].push_back(std::make_unique <Trash>(world, sf::Vector2f
				(boxSize.x * x, boxSize.y * y), boxSize,ID));
				m_ObjWithID.insert(std::pair<int, GameObject*>(ID, m_map[y][x].get()));
				ID++;
				break;
			case SPECIAL_FOOD:
				m_map[y].push_back(std::make_unique <SpecialFood>(world, sf::Vector2f
				(boxSize.x * x, boxSize.y * y) , boxSize,ID));
				m_ObjWithID.insert(std::pair<int, GameObject*>(ID, m_map[y][x].get()));
				ID++;
				break;
			default:
				m_map[y].push_back(nullptr); // inputed ' '
				break;
			}
		}
	}
	return movingsVec;
}
//============================================================================
//the method isn't const because fstream's peek method isn't const
bool Board::is_next_lvl_exist() const {
	return m_levelReader.isThereNextLevel();
}
//============================================================================
/*
* This function pass all the map and reset every object to the initial location
* and state.
*/
//void Board::resetLvl() {
//	for (int i = 0; i < this->m_map.size(); ++i)
//		for (int j = 0; j < this->m_map[i].size(); ++j) {
//			if (this->m_map[i][j].get() != nullptr)
//				this->m_map[i][j]->reset();
//		}
//}
////============================================================================
//void Board::gameOver() {
//	this->m_levelReader.resetRead();
//	this->releaseMap();
//	//this->m_door.release();
//	this->m_player = nullptr;
//}
//============================================================================
/*
* This function load the background and the music of the current level.
*/
void Board::loadLevelEffects(int level) {
	this->m_background.setTexture(&Resources::instance()
		.getBackground(level));
	//Resources::instance().playMusic(level);
}
//============================== private section =============================
/*this function all the details of the current level, release ptrs and
unique ptrs.*/
void Board::clearParameters() {
	m_map.clear();
	m_player = nullptr;
}
//============================================================================
/*
* This function called in load new level function to raffle the type of the
* gift. The function return a ptr to the type of food it raffled.
*/
//Food* Board::raffleFood(const sf::Vector2f& boxSize, const sf::Vector2i& index) {
//
//}
//============================================================================
GameObject* Board::getObjWithId(const int id) {
	return m_ObjWithID.find(id)->second;
}