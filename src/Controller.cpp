#include "Controller.h"
#include "Resources.h"
#include "Macros.h"
#include "Player.h"
#include "Music.h"
#include <iostream>

//============================================================================

Controller::Controller()
        : m_window(sf::VideoMode(1920, 1080), "Ratata Game", sf::Style::Titlebar | sf::Style::Close),
          m_board(sf::Vector2f(0, 0),
            sf::Vector2f((float)BACKGROUND_WIDTH, (float)m_window.getSize().y)),
          m_player(nullptr),
          m_listener(Listener()),
          m_highScore({0, 0}, sf::Vector2f(m_window.getSize())),
          m_menu(Menu(&m_highScore)),
            m_stats(Stats(m_board.getLevelTime()))
{
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
    while (m_window.isOpen())
    {
        Music::instance().playMenu(); //at start of main menu
        m_stats.levelup(m_board.getLevelTime());
        if (m_menu.runMenu(m_window, false, false))
        {
            Music::instance().playGame(); //after pressing on new game -->runMenu returns true
            while (m_window.isOpen())
            {
                m_world->Step(TIMESTEP, VELITER, POSITER);
                if (m_player->canLevelUP()) {

                    if (m_board.isNextLvlExist()) {
                        levelUp();
                    }
                    else {
                        resetGame();
                        break;
                    }
                }

                 m_gameClock.restart();
                 m_window.clear();
                 m_stats.update(m_level, m_player->getScore(), m_player->getLife(), m_stats.getTimeLeft());
                 m_board.removeFood(*m_world);

                if (m_player->getState() == DIE) {
                    if (m_player->getLife() == 0){
                        /// need to add high score option here
                        resetGame();
                        break;
                    }
                    ///reset timer
                    playerDied();
                }

                drawObjects();
                m_stats.draw(m_window);
                m_window.display();
                if (!handleGameEvents()) {
                    resetGameView();
                    Music::instance().stopGame();
                    break;
                }
            }
            //this is right AFTER when the user presses ESC key during playing game-->m_window.isOpen(line 34) returns false or line 61 is true so break
        }
        //this is when the user doesn't click on new game on main menu --> the function runMenu (line 31) returns false
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
    m_level++;
    int playerScore = m_player->getScore();
    int playerLife = m_player->getLife();
    srand((unsigned int)time(nullptr));
    m_board.levelUp(*m_world);
    delete m_world;
    m_world = new b2World(b2Vec2(0, WORLD_GRAVITY));
    separateGameObjects(m_board.loadNewLevel(*m_world));
    m_stats.levelup(m_board.getLevelTime());
    m_world->SetContactListener(&m_listener);
    m_listener.setCurrentBoard(m_board);
    m_player->setScore(playerScore);
    m_player->resetLife(playerLife);
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
    m_player->setStatsPtr(&m_stats);
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
    if (character->getGlobalBounds().top < STAT_HEIGHT) { ///collision with top
        character->setPhysicsObjectPos
        (sf::Vector2f(character->getLocation().x, character->getGlobalBounds().height + STAT_HEIGHT), EMDOWN);
    }
    if (character->getGlobalBounds().left < 0) { ///collision with left
        character->setPhysicsObjectPos
        (sf::Vector2f( 80, character->getLocation().y),MDOWN+MRIGHT);
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

void Controller::resetGame() {
    resetGameView();
    m_highScore.getNewScore(m_player, m_window);
    m_board.gameOver(*m_world);
    m_level = 0;
    m_player->resetLife(3);
    m_player->resetScore();
    RegularFood::resetFoodCounter();
    Music::instance().stopGame();
    levelUp();
}
//============================================================================

void Controller::resetGameView()
{
    m_screenView.reset(sf::FloatRect(0, 0, m_window.getSize().x, m_window.getSize().y));
    m_window.setView(m_screenView);
}