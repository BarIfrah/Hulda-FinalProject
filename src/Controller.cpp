#include "Controller.h"
#include "Resources.h"
#include "Macros.h"
#include "Player.h"
#include <iostream>
//============================================================================

Controller::Controller()
        : m_window(sf::VideoMode(1000, 700), "Hulda", sf::Style::Titlebar | sf::Style::Close),
        m_board(sf::Vector2f(0, 0),
            sf::Vector2f((float)BACKGROUND_WIDTH, (float)m_window.getSize().y)),
        m_player(nullptr),
        m_listener(CollisionsListener()){
    m_window.setFramerateLimit(60);
    m_screenView.reset(sf::FloatRect(0, 0, m_window.getSize().x, m_window.getSize().y));
    m_screenView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
    m_window.setView(m_screenView);
    m_world = new b2World(b2Vec2(0, 9.81));
    m_world->SetContactListener(&m_listener);
    m_listener.setCurrentBoard(m_board);
}

//============================================================================

void Controller::run() {
    seperateGameObjects(m_board.loadNewLevel(*m_world));
    while (m_window.isOpen()) {
        m_world->Step(TIMESTEP, VELITER, POSITER);
        m_gameClock.restart();
        m_window.clear();
        drawObjects();
        m_window.display();
        handleGameEvents();
        //m_listener.BeginContact(m_world->GetContactList());
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

void Controller::seperateGameObjects(const vector<MovingObject*>& list)
{
    this->m_enemies.clear();
    for (int i = 0; i < list.size(); ++i) {
        if (dynamic_cast <Player*> (list[i]))
            this->m_player = (Player*)list[i];
        else
            this->m_enemies.push_back(list[i]);
    }
}

//============================================================================

void Controller::moveCharacters()
{
    m_player->move(m_gameClock.getElapsedTime(), m_board);
    for (auto& enemy : m_enemies)
        enemy->move(m_gameClock.getElapsedTime(), m_board);
}

//============================================================================

void Controller::handleGameEvents() {
    if (auto event = sf::Event{}; m_window.pollEvent(event)) {
        switch (event.key.code) {
            case sf::Keyboard::Escape:
                m_window.close();
            default:;
              }
    }
    
    moveCharacters();

    HandleCharacterCollisionWithWindow(m_player);
    for (auto& enemy : m_enemies)
        HandleCharacterCollisionWithWindow(enemy);
    sideScroll();
}

//============================================================================

void Controller::sideScroll() {
    m_CurrViewPos.x = m_player->getSprite().getPosition().x + m_player->getSize().x / 2 - (float(m_window.getSize().x) / 2);
    if (m_CurrViewPos.x < 0)
        m_CurrViewPos.x = 0;
    if (m_CurrViewPos.y < 0)
        m_CurrViewPos.y = 0;
    if (m_CurrViewPos.x > BACKGROUND_WIDTH - m_window.getSize().x)
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
        (sf::Vector2f(character->getLocation().x, 0), MDOWN);
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
