#include "Controller.h"
#include "Resources.h"
#include "Macros.h"
#include "Player.h"
#include <iostream>

Controller::Controller()
        : m_window(sf::VideoMode::getDesktopMode(), "Hulda", sf::Style::Fullscreen),
        m_board(sf::Vector2f(0, 0),
            sf::Vector2f((float)BACKGROUND_SIZE, (float)m_window.getSize().y)),
        m_player(nullptr){
    m_screenView.reset(sf::FloatRect(0, 0, m_window.getSize().x, m_window.getSize().y));
    m_screenView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
    m_window.setView(m_screenView);
}

void Controller::run() {
    this->m_player = this->m_board.loadNewLevel();
    //--------------temporary--------------------------------
    /*sf::Vector2f boxSize = sf::Vector2f(128, 256);
    sf::IntRect rect = sf::IntRect(0, 0, CHARACTER_WIDTH, CHARACTER_HEIGHT);
    sf::Sprite playerSprite(Resources::instance().getTexture(PLAYER_T), rect);
    playerSprite.setPosition(sf::Vector2f(0, (m_window.getSize().y / 5)*4));
    rect.width = playerSprite.getTexture()->getSize().x;
    rect.height = playerSprite.getTexture()->getSize().y;
    playerSprite.setTextureRect(rect);
    playerSprite.setScale(
        (float)boxSize.x / rect.width,
        (float)boxSize.y / rect.height);*/

    /*sf::RectangleShape playerSprite;
    playerSprite.setSize(sf::Vector2f(200, 200));
    playerSprite.setPosition(sf::Vector2f(0, m_window.getSize().y/2));
    playerSprite.setTexture(&Resources::instance().getTexture(PLAYER_T));*/
    //-------------------------------------------------------
    while (m_window.isOpen()) {
        m_gameClock.restart();
        m_window.clear();
        this->m_board.draw(m_window, m_gameClock.getElapsedTime());
        //this->m_window.draw(playerSprite);
        this->drawObjects();
        m_window.display();

//        sf::Vector2f movement;
        if (auto event = sf::Event{}; m_window.pollEvent(event)) {
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    m_window.close();
//                case sf::Keyboard::Right:
//                    movement=sf::Vector2f(1, 0);
//                    movement *= MOVEMENT_SPEED * m_gameClock.getElapsedTime().asSeconds();
//                    playerSprite.speedUp(movement);
//                    break;
//                case sf::Keyboard::Left:
//                    movement = sf::Vector2f(-1, 0);
//                    movement *= MOVEMENT_SPEED * m_gameClock.getElapsedTime().asSeconds();
//                    playerSprite.speedUp(movement);
//                    break;
//               /* case sf::Keyboard::Up:
//                    movement=sf::Vector2f(0, -1);
//                    movement *= MOVEMENT_SPEED * m_gameClock.getElapsedTime().asSeconds();
//                    player.speedUp(movement);
//                    break;
//                case sf::Keyboard::Down:
//                    movement = sf::Vector2f(0, 1);
//                    movement *= MOVEMENT_SPEED * m_gameClock.getElapsedTime().asSeconds();
//                    player.speedUp(movement);
//                    break;*/
//                default:
//                    ;
//            }
//            m_CurrViewPos.x = playerSprite.getPosition().x + 50 - (float(m_window.getSize().x) / 5);
//            m_CurrViewPos.y = playerSprite.getPosition().y + 50 - (float(m_window.getSize().y) / 2);
            }
            m_player->move();
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
    }
}
//=========================================================================== =
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