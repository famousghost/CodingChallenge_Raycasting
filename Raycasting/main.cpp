#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include "GameWindow.h"
#include "Input.h"
#include "LightSimulation.h"

int main()
{
    const float l_sideBarSize = 100.0f;
    const unsigned int l_windowWidth = 800;
    const unsigned int l_windowHeight = 600;
    std::string l_title = "Raycasting";
    LightSimulation l_lightSimulation;
    double l_rayLength = 100000.0;
    sf::RenderWindow m_window(sf::VideoMode{ l_windowWidth, l_windowHeight }, l_title, sf::Style::Default);
    static double l_time = 0.1;
    l_lightSimulation.prepareScene();
    auto& l_ray = l_lightSimulation.getRay();
    float l_prevTime = 0.0f;
    float l_currentTime = 0.0f;
    sf::Clock clock;
    while (m_window.isOpen())
    {
        sf::Time l_elapsed = clock.getElapsedTime();
        l_prevTime = l_currentTime;
        l_currentTime = l_elapsed.asSeconds();
        float l_deltaTime = l_currentTime - l_prevTime;
        m_window.clear();
        Input::buttonsClick(m_window);
        Input::move(l_ray.m_origin, l_deltaTime);
        l_lightSimulation.drawElements(m_window);

        m_window.display();
    }

    return 0;
}