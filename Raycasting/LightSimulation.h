#pragma once
#include <vector>
#include <array>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "LineSegment.h"

class LightSimulation
{
public:
    std::array<sf::Vertex, 2> createRayShape(const Ray& p_ray, float p_len);

    std::vector<std::array<sf::Vertex, 2>> createLinesShape(std::vector<LineSegment> p_lines);

    void prepareScene();

    void drawElements(sf::RenderWindow& p_window);

    Ray& getRay();

private:
    Ray m_ray;
    std::vector<LineSegment> m_lines;
    std::vector<std::array<sf::Vertex, 2>> m_lineShapes;
    double m_rayLength;
};

