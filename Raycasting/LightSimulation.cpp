#include "LightSimulation.h"
#include "Transformations.h"
#include "LineIntersection.h"

std::array<sf::Vertex, 2> LightSimulation::createRayShape(const Ray & p_ray, float p_len)
{
    std::array<sf::Vertex, 2> l_rayShape =
    {
        sf::Vertex(p_ray.m_origin),
        sf::Vertex(p_ray.m_origin + p_ray.normalizedDirection() * static_cast<float>(p_len))
    };
    return l_rayShape;
}

std::vector<std::array<sf::Vertex, 2>> LightSimulation::createLinesShape(std::vector<LineSegment> p_lines)
{
    std::vector<std::array<sf::Vertex, 2>> l_lineShapes;
    for (auto& l_line : p_lines)
    {
        l_lineShapes.push_back(std::array<sf::Vertex, 2>{l_line.m_startPoint, l_line.m_endPoint});
    }
    return l_lineShapes;
}

void LightSimulation::prepareScene()
{
    sf::Vector2f l_center = sf::Vector2f(400.0f, 300.0f);
    m_rayLength = 100000.0;
    sf::Vector2f l_rayOrigin = sf::Vector2f(200.0f, 300.0f);
    sf::Vector2f l_rayDirection = sf::Vector2f(0.0f, 1.0f);

    m_lines =
    {
        LineSegment(sf::Vector2f(0.0f, -50.0f) + l_center, sf::Vector2f(300.0f,  -50.0f) + l_center),
        LineSegment(sf::Vector2f(50.0f, -100.0f) + l_center, sf::Vector2f(300.0f, -150.0f) + l_center),
        LineSegment(sf::Vector2f(-100.0f, -200.0f) + l_center, sf::Vector2f(0.0f, -200.0f) + l_center),
        LineSegment(sf::Vector2f(100.0f, -100.0f) + l_center, sf::Vector2f(100.0f, 300.0f) + l_center)
    };

    m_ray = Ray(l_rayOrigin, l_rayDirection * static_cast<float>(m_rayLength));
    m_lineShapes = createLinesShape(m_lines);
}

void LightSimulation::drawElements(sf::RenderWindow & p_window)
{
    LineIntersection l_lineIntersection;
    for (int i = 0; i < 360; ++i)
    {
        m_ray.m_direction = Transformations::rotate(m_ray.m_direction, 1);
        std::array<sf::Vertex, 2> l_rayShape = createRayShape(m_ray, m_rayLength);
        double l_minDistance = 10000000.0;
        for (auto& l_line : m_lines)
        {
            auto l_t = l_lineIntersection.getTValue(Transformations::rayToLineSegment(m_ray), l_line);
            auto l_u = l_lineIntersection.getUValue(Transformations::rayToLineSegment(m_ray), l_line);
            if (l_t >= 0.0f && l_t <= 1.0f && l_u <= 1.0f && l_u >= 0.0f)
            {
                sf::Vector2f l_pointOnRay = l_lineIntersection.findPointOnLine(Transformations::rayToLineSegment(m_ray), l_t);
                double l_distance = Transformations::distance(m_ray.m_origin, l_pointOnRay);
                if (l_minDistance > l_distance)
                {
                    l_rayShape = createRayShape(m_ray, l_distance);
                    l_minDistance = l_distance;
                }
            }
        }
        p_window.draw(l_rayShape.data(), 2, sf::Lines);
    }
    for (auto& l_lineShape : m_lineShapes)
    {
        p_window.draw(l_lineShape.data(), 2, sf::Lines);
    }
}

Ray & LightSimulation::getRay()
{
    return m_ray;
}
