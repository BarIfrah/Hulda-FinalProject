#include "Controller.h"
#include "Macros.h"
#include <iostream>

Controller::Controller()
: m_window(sf::VideoMode::getDesktopMode(), "Hulda", sf::Style::Fullscreen)
{}

void Controller::run() {
    while (true) {

        sf::Texture background_texture;
        if (!background_texture.loadFromFile("level2.png"))
            std::cout << "cant open file";

        sf::RectangleShape background;
        background.setTexture(&background_texture);
        background.setSize(sf::Vector2f(m_window.getSize()));
        sf::RectangleShape rec;
        rec.setFillColor(sf::Color::Blue);
        rec.setSize(sf::Vector2f(100, 100));
        
        sf::View view;
        view.reset(sf::FloatRect(0, 0, m_window.getSize().x, m_window.getSize().y));
        view.setViewport(sf::FloatRect(0,0,1.0f,1.0f));
        m_window.setView(view);

        while (m_window.isOpen())
        {
            m_gameClock.restart();
            m_window.clear();
            //this->m_window.draw(m_background);
            //this->draw();
            this->m_window.draw(background);
            this->m_window.draw(rec);
            m_window.display();

            if (auto event = sf::Event{}; m_window.pollEvent(event))
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    m_window.close();
                case sf::Keyboard::Right:
                        rec.move(MOVEMENT_SPEED * m_gameClock.getElapsedTime().asSeconds(), 0);
                        break;
                case sf::Keyboard::Left:
                        rec.move(-MOVEMENT_SPEED * m_gameClock.getElapsedTime().asSeconds(), 0);
                        break;
                default:
                    ;
                }
                m_CurrViewPos.x = rec.getPosition().x + 50 - (m_window.getSize().x / 2);
                m_CurrViewPos.y = rec.getPosition().y + 50 - (m_window.getSize().y / 2);

                if (m_CurrViewPos.x < 0)
                    m_CurrViewPos.x = 0;
                if (m_CurrViewPos.y < 0)
                    m_CurrViewPos.y = 0;
                view.reset(sf::FloatRect(m_CurrViewPos.x, m_CurrViewPos.y, m_window.getSize().x, m_window.getSize().y));
                m_window.setView(view);
            }
        }
    }
}