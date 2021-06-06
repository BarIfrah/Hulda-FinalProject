#include "Controller.h"
#include "Resources.h"
#include "Macros.h"
#include <iostream>

Controller::Controller()
        : m_window(sf::VideoMode(1920, 1080), "Hulda", sf::Style::Titlebar){
    m_screenView.reset(sf::FloatRect(0, 0, m_window.getSize().x, m_window.getSize().y));
    m_window.setFramerateLimit(60); ///60fps
    m_screenView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
    m_window.setView(m_screenView);
}

void Controller::run() {
    //--------------temporary--------------------------------
    sf::RectangleShape background;
    background.setTexture(&Resources::instance()
            .getBackground(0));
    background.setSize(sf::Vector2f(7185, 1920));
    sf::RectangleShape rec;
    rec.setFillColor(sf::Color::Blue);
    rec.setSize(sf::Vector2f(100, 100));
    rec.setPosition(sf::Vector2f(0, 1600));
    //-------------------------------------------------------
    while (m_window.isOpen())
    {
        m_gameClock.restart();
        m_window.clear();
        //this->m_window.draw(m_background);
        //this->draw();
        this->m_window.draw(background);
        this->m_window.draw(rec);
        m_window.display();
        sf::Vector2f movement;
        if (auto event = sf::Event{}; m_window.pollEvent(event))
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Escape:
                    m_window.close();
                case sf::Keyboard::Right:
                    movement=sf::Vector2f(1, 0);
                    movement *= MOVEMENT_SPEED * m_gameClock.getElapsedTime().asSeconds();
                    rec.move(movement);
                    break;
                case sf::Keyboard::Left:
                    movement = sf::Vector2f(-1, 0);
                    movement *= MOVEMENT_SPEED * m_gameClock.getElapsedTime().asSeconds();
                    rec.move(movement);
                    break;
                case sf::Keyboard::Up:
                    movement=sf::Vector2f(0, -1);
                    movement *= MOVEMENT_SPEED * m_gameClock.getElapsedTime().asSeconds();
                    rec.move(movement);
                    break;
                case sf::Keyboard::Down:
                    movement = sf::Vector2f(0, 1);
                    movement *= MOVEMENT_SPEED * m_gameClock.getElapsedTime().asSeconds();
                    rec.move(movement);
                    break;
                default:
                    ;
            }
            m_CurrViewPos.x = rec.getPosition().x + 50 - (float(m_window.getSize().x) / 5);
            m_CurrViewPos.y = rec.getPosition().y + 50 - (float(m_window.getSize().y) / 2);

            if (m_CurrViewPos.x < 0)
                m_CurrViewPos.x = 0;
            if (m_CurrViewPos.y < 0)
                m_CurrViewPos.y = 0;
            if (m_CurrViewPos.x > m_window.getSize().x)
                m_CurrViewPos.x = m_window.getSize().x;
            if (m_CurrViewPos.y > m_window.getSize().y)
                m_CurrViewPos.y = m_window.getSize().y;
            m_screenView.reset(sf::FloatRect(m_CurrViewPos.x, m_CurrViewPos.y, m_window.getSize().x, m_window.getSize().y));
            m_window.setView(m_screenView);
        }
    }
}
