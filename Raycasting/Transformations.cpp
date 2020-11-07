#include "Transformations.h"
# define M_PI 3.14159265358979323846  

sf::Vector2f Transformations::rotate(sf::Vector2f p_vec, double p_angle)
{
    double l_angle = toRadinas(p_angle);
    return sf::Vector2f(std::cos(l_angle) * p_vec.x - std::sin(l_angle) * p_vec.y, 
                        std::sin(l_angle) * p_vec.x + std::cos(l_angle) * p_vec.y);
}

double Transformations::toRadinas(double p_angle)
{
    return (p_angle * M_PI) / 180.0f;
}

double Transformations::distance(sf::Vector2f p_vec1, sf::Vector2f p_vec2)
{
    return std::sqrt((p_vec2.x - p_vec1.x) * (p_vec2.x - p_vec1.x) 
           + (p_vec2.y - p_vec1.y) * (p_vec2.y - p_vec1.y));
}

LineSegment Transformations::rayToLineSegment(const Ray & p_ray)
{
    return LineSegment(p_ray.m_origin, p_ray.m_origin + p_ray.m_direction);
}
