#include "Controller.h"
#include "Resources.h"
#include "Macros.h"
#include "Player.h"
#include <iostream>

Controller::Controller()
        : m_window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Hulda", sf::Style::Titlebar | sf::Style::Close),
        m_board(sf::Vector2f(0, 0),
            sf::Vector2f((float)BACKGROUND_SIZE, (float)m_window.getSize().y)),
        m_player(nullptr){
    m_window.setFramerateLimit(60);
    m_screenView.reset(sf::FloatRect(0, 0, m_window.getSize().x, m_window.getSize().y));
    m_screenView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
    m_window.setView(m_screenView);
    m_world = std::make_unique<b2World>(b2Vec2(0, 9.81));
}
//============================================================================
void Controller::run() {
    while (m_window.isOpen()) 
    {
        if (m_menu.runMenu(m_window, false, false))
        {
            m_player = m_board.loadNewLevel(*(m_world.get()));

            while (m_window.isOpen()) {
                m_world.get()->Step(TIMESTEP, VELITER, POSITER);
                m_gameClock.restart();
                m_window.clear();
                drawObjects();
                m_window.display();
                if (!handleGameEvents())
                    break;
            }
        }
        else 
            m_window.close();
    }
   
}
//============================================================================
/*
* this function draw all the dynamic objects in the game by the time clock.
*/
void Controller::drawObjects() {
    this->m_board.draw(m_window, m_gameClock.getElapsedTime());
    this->m_player->draw(this->m_window);
   /* for (int i = 0; i < this->m_enemies.size(); ++i)
        this->m_enemies[i]->draw(this->m_window);
    for (int i = 0; i < this->m_giftEnemies.size(); ++i)
        this->m_giftEnemies[i]->draw(this->m_window);*/
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
    m_player->move(m_gameClock.getElapsedTime());
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
    if (m_CurrViewPos.x > BACKGROUND_SIZE-m_window.getSize().x)
        m_CurrViewPos.x = BACKGROUND_SIZE - m_window.getSize().x;
    m_screenView.reset(sf::FloatRect(m_CurrViewPos.x, m_CurrViewPos.y, m_window.getSize().x,
                                     m_window.getSize().y));
    m_window.setView(m_screenView);
}
//============================================================================