#include "Controller.h"
#include "Resources.h"
#include "Macros.h"
#include "Player.h"
#include <iostream>
//============================================================================

Controller::Controller()
        : m_window(sf::VideoMode(1500, 1000), "Hulda", sf::Style::Titlebar | sf::Style::Close),
        m_board(sf::Vector2f(0, 0),
            sf::Vector2f((float)BACKGROUND_WIDTH, (float)m_window.getSize().y)),
        m_player(nullptr),
        m_listener(Listener()){
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
     while (m_window.isOpen()) {
        if (m_menu.runMenu(m_window, false, false)) {
            while (m_window.isOpen()) {
                m_world->Step(TIMESTEP, VELITER, POSITER);
                std::cout << RegularFood::getFoodCounter() << std::endl;
                if (RegularFood::getFoodCounter() == 0) {
                    if (m_board.is_next_lvl_exist()) {
                        levelUp();
                    }else {
                        //gameOver();
                        break;
                    }
                }


                m_gameClock.restart();
                m_window.clear();
                m_stats.update(1, 100, 3);

                m_board.removeFood(*m_world);

                if (m_player->getState() == DIE) {
                    playerDied();
                }

                drawObjects();
                m_window.display();
                handleGameEvents();
            }
        }
     }
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
    m_board.levelUp(*m_world);
    srand((unsigned int)time(nullptr));
    delete m_world;
    m_world = new b2World(b2Vec2(0, WORLD_GRAVITY));
    separateGameObjects(m_board.loadNewLevel(*m_world));
    //m_gameState.levelup(m_board.getLevelTime());
    m_world->SetContactListener(&m_listener);
    m_listener.setCurrentBoard(m_board);
}

//============================================================================

void Controller::separateGameObjects(const vector<MovingObject*>& movingObjects)
{
    this->m_enemies.clear();
    for (auto& obj : movingObjects)
        if (dynamic_cast<Player*>(obj))
            m_player = (Player*)obj;
        else
            m_enemies.push_back(obj);
}

//============================================================================

void Controller::moveCharacters()
{
    m_player->move(m_gameClock.getElapsedTime(), m_board);
    for (auto& enemy : m_enemies)
        enemy->move(m_gameClock.getElapsedTime(), m_board);
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
    m_window.setView(m_screenView);
}

//============================================================================

void Controller::HandleCharacterCollisionWithWindow(MovingObject* character)
{
    if (character->getGlobalBounds().top < 0) {
        character->setPhysicsObjectPos
        (sf::Vector2f(character->getLocation().x, character->getGlobalBounds().height), EMDOWN);
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
