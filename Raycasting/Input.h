#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
class Input
{
public:

    static void buttonsClick(sf::RenderWindow& p_window);
    static void move(sf::Vector2f& p_point, float p_deltaTime);

    static bool s_moveUp;
    static bool s_moveDown;
    static bool s_increaseLen;
    static bool s_decreaseLen;
    static float s_speed;
    
};

