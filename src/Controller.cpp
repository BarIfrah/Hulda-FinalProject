#include "Controller.h"
#include "Resources.h"
#include "Macros.h"
#include "Player.h"
#include "Music.h"
#include <iostream>

//============================================================================

Controller::Controller()
        : m_window(sf::VideoMode(1920, 1080), "Hulda", sf::Style::Titlebar | sf::Style::Close),
        m_board(sf::Vector2f(0, 0),
            sf::Vector2f((float)BACKGROUND_WIDTH, (float)m_window.getSize().y)),
        m_player(nullptr),
        m_listener(Listener()),
        m_stats(Stats()){
    m_window.setFramerateLimit(60);
    m_screenView.reset(sf::FloatRect(0, 0, m_window.getSize().x, m_window.getSize().y));
    m_screenView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
    m_window.setView(m_screenView);
    m_world = new b2World(b2Vec2(0, WORLD_GRAVITY));
    m_world->SetContactListener(&m_listener);
    m_listener.setCurrentBoard(m_board);
    srand((unsigned int)time(nullptr));
}

//============================================================================

void Controller::run() {
    separateGameObjects(m_board.loadNewLevel(*m_world));
    bool playingGame = true;
     while (playingGame)
     {
         Music::instance().playMenu(); //at start of main menu
         if (m_menu.runMenu(m_window, false, false))
         {
             Music::instance().playGame(); //after pressing on new game -->runMenu returns true
             while (m_window.isOpen())
             {
                 m_world->Step(TIMESTEP, VELITER, POSITER);
                 std::cout << RegularFood::getFoodCounter() << std::endl;
                 if (RegularFood::getFoodCounter() == 0) {
                     if (m_board.is_next_lvl_exist()) {
                         levelUp();
                     }
                     else {
                         //gameOver();
                         break;
                     }
                 }

                 m_gameClock.restart();
                 m_window.clear();
                 m_stats.update(m_level, m_player->getScore(), m_player->getLife());
                 m_board.removeFood(*m_world);

                 if (m_player->getState() == DIE) {
                     playerDied();
                 }

                 drawObjects();
                 m_stats.draw(m_window);
                 m_window.display();
                 if (!handleGameEvents()) {
                     playingGame = false;
                     break;
                 }
             }
             //Music::instance().playHiScoreMenu();//this is right AFTER when the user presses ESC key during playing game-->m_window.isOpen(line 34) returns false or line 61 is true so break
         }
         //Music::instance().playBack();//this is when the user doesn't click on new game on main menu --> the function runMenu (line 31) returns false
     }
     Music::instance().playEnemyAte();
}
//============================================================================
/*
* this function draw all the dynamic objects in the game by the time clock.
*/
void Controller::drawObjects() {
    m_player->draw(m_window);
    m_board.draw(m_window, m_gameClock.getElapsedTime());
    for (auto& enemy : m_enemies)
        enemy->draw(m_window);
}

//============================================================================

void Controller::levelUp()
{
    //Resources::instance().pauseMusic();
    m_level++;
    int playerScore = m_player->getScore();
    m_board.levelUp(*m_world);
    srand((unsigned int)time(nullptr));
    delete m_world;
    m_world = new b2World(b2Vec2(0, WORLD_GRAVITY));
    separateGameObjects(m_board.loadNewLevel(*m_world));
    //m_gameState.levelup(m_board.getLevelTime());
    m_world->SetContactListener(&m_listener);
    m_listener.setCurrentBoard(m_board);
    m_player->setScore(playerScore);
}

//============================================================================

void Controller::separateGameObjects(const vector<MovingObject*>& movingObjects)
{
    m_enemies.clear();
    m_floors.clear();
    for (auto& obj : movingObjects)
        if (dynamic_cast<Player*>(obj))
            m_player = (Player*)obj;
        else if (dynamic_cast<DynamicFloor*>(obj))
            m_floors.push_back(obj);
        else
            m_enemies.push_back(obj);
}

//============================================================================

void Controller::moveCharacters()
{
    m_player->move(m_gameClock.getElapsedTime(), m_board);
    for (auto& enemy : m_enemies)
        enemy->move(m_gameClock.getElapsedTime(), m_board);
    for (auto& floor : m_floors)
            floor->move(m_gameClock.getElapsedTime(), m_board);
}

//============================================================================


bool Controller::handleGameEvents() {
    if (auto event = sf::Event{}; m_window.pollEvent(event)) {
        switch (event.type) { //changed to type
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    return false;
                break;
            case sf::Event::Closed:
                m_window.close();
                return false;
            default:;
              }
    }
    
    moveCharacters();

    HandleCharacterCollisionWithWindow(m_player);
    for (auto& enemy : m_enemies)
        HandleCharacterCollisionWithWindow(enemy);
    sideScroll();
    return true;
}

//============================================================================

void Controller::sideScroll() {
    m_CurrViewPos.x = m_player->getSprite().getPosition().x + m_player->getSize().x / 2 - (float(m_window.getSize().x) / 2);
    if (m_CurrViewPos.x < 0)
        m_CurrViewPos.x = 0;
    if (m_CurrViewPos.y < 0)
        m_CurrViewPos.y = 0;
    if (m_CurrViewPos.x > BACKGROUND_WIDTH-m_window.getSize().x)
        m_CurrViewPos.x = BACKGROUND_WIDTH - m_window.getSize().x;
    m_screenView.reset(sf::FloatRect(m_CurrViewPos.x, m_CurrViewPos.y, m_window.getSize().x,
                                     m_window.getSize().y));
    m_stats.setPosition(sf::Vector2f(m_CurrViewPos.x, m_CurrViewPos.y));
    m_window.setView(m_screenView);
}

//============================================================================

void Controller::HandleCharacterCollisionWithWindow(MovingObject* character)
{
    if (character->getGlobalBounds().top < STAT_HEIGHT) {
        character->setPhysicsObjectPos
        (sf::Vector2f(character->getLocation().x, character->getGlobalBounds().height + STAT_HEIGHT), EMDOWN);
    }
    if (character->getGlobalBounds().left < 0) {
        character->setPhysicsObjectPos
        (sf::Vector2f( 70, character->getLocation().y),MDOWN+MRIGHT);
    }
    if (character->getGlobalBounds().left+ character->getGlobalBounds().width > m_board.getLevelSize().x) {
        character->setPhysicsObjectPos
        (sf::Vector2f(m_board.getLevelSize().x- character->getGlobalBounds().width, character->getLocation().y), MDOWN + MLEFT);
    }
    character->updateLoc();
}

//============================================================================

void Controller::playerDied()
{
    //Resources::instance().playSound(ENEMY_SOUND);
    m_board.resetObjects();
    //m_gameState.died();
}

//============================================================================

void Controller::gameOver()
{
    //Resources::instance().pauseMusic();
    this->m_player = nullptr;
    this->m_enemies.clear();
   // this->m_board.gameOver();
   // this->m_gameState.gameOver();
}
