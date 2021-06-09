#include "Controller.h"
#include "Resources.h"
#include "Macros.h"
#include "Player.h"
#include <iostream>

Controller::Controller()
        : m_window(sf::VideoMode(1920, 1080), "Hulda", sf::Style::Titlebar | sf::Style::Close),
        m_board(sf::Vector2f(0, 0),
            sf::Vector2f((float)BACKGROUND_SIZE, (float)m_window.getSize().y)),
        m_player(nullptr){
    m_window.setFramerateLimit(60);
    m_screenView.reset(sf::FloatRect(0, 0, m_window.getSize().x, m_window.getSize().y));
    m_screenView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
    m_window.setView(m_screenView);
}
//============================================================================
void Controller::run() {
    this->m_player = this->m_board.loadNewLevel();
    
    while (m_window.isOpen()) {
        m_gameClock.restart();
        m_window.clear();
        this->m_board.draw(m_window, m_gameClock.getElapsedTime());
        this->drawObjects();
        m_window.display();

        handleGameEvents();

    }
}
//============================================================================
/*
* this function draw all the dynamic objects in the game by the time clock.
*/
void Controller::drawObjects() {
    this->m_player->draw(this->m_window);

   /* for (int i = 0; i < this->m_enemies.size(); ++i)
        this->m_enemies[i]->draw(this->m_window);
    for (int i = 0; i < this->m_giftEnemies.size(); ++i)
        this->m_giftEnemies[i]->draw(this->m_window);*/
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
    m_player->move(m_gameClock.getElapsedTime());
    sideScroll();
}
//============================================================================
void Controller::sideScroll() {
    m_CurrViewPos.x = m_player->getSprite().getPosition().x + m_player->getSize().x / 2 - (float(m_window.getSize().x) / 2);
    //m_CurrViewPos.y = m_player->getSprite().getPosition().y + m_player->getSize().y / 2 - (float(m_window.getSize().y) / 2);
    //m_CurrViewPos.y = m_window.getSize().y;

    if (m_CurrViewPos.x < 0)
        m_CurrViewPos.x = 0;
    if (m_CurrViewPos.y < 0)
        m_CurrViewPos.y = 0;
    if (m_CurrViewPos.x > m_window.getSize().x)
        m_CurrViewPos.x = m_window.getSize().x;
    if (m_CurrViewPos.y > m_window.getSize().y)
        m_CurrViewPos.y = m_window.getSize().y;
    m_screenView.reset(sf::FloatRect(m_CurrViewPos.x, m_CurrViewPos.y, m_window.getSize().x,
                                     m_window.getSize().y));
    m_window.setView(m_screenView);
}
//============================================================================