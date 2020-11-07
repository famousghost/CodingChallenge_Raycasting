#include "Input.h"

bool Input::s_moveUp = false;
bool Input::s_moveDown = false;
bool Input::s_increaseLen = false;
bool Input::s_decreaseLen = false;
float Input::s_speed = 200.0f;

void Input::buttonsClick(sf::RenderWindow& p_window)
{
    sf::Event event;
    while (p_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            p_window.close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            p_window.close();
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
            {
                s_moveUp = true;
            }
            if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
            {
                s_moveDown = true;
            }
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
            {
                s_increaseLen = true;
            }
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
            {
                s_decreaseLen = true;
            }
        }
        else if(event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
            {
                s_moveUp = false;
            }
            if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
            {
                s_moveDown = false;
            }
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
            {
                s_increaseLen = false;
            }
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
            {
                s_decreaseLen = false;
            }
        }
    }
}

void Input::move(sf::Vector2f& p_point, float p_deltaTime)
{
    if (Input::s_moveUp)
    {
        p_point.y -= s_speed * p_deltaTime;
    }
    if (Input::s_moveDown)
    {
        p_point.y += s_speed * p_deltaTime;
    }
    if (Input::s_increaseLen)
    {
        p_point.x += s_speed * p_deltaTime;
    }
    if (Input::s_decreaseLen)
    {
        p_point.x -= s_speed * p_deltaTime;
    }
}
