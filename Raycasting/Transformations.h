#pragma once
#include <SFML\Graphics.hpp>
#include "LineSegment.h"

class Transformations
{
public:
    static sf::Vector2f rotate(sf::Vector2f p_vec, double p_angle);

    static double toRadinas(double p_angle);

    static double distance(sf::Vector2f p_vec1, sf::Vector2f p_vec2);

    static LineSegment rayToLineSegment(const Ray & p_ray);

};

