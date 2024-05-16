#include "Utils.h"

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
        return true;

    return false;
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;

    return (val > 0) ? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and 
    // special cases 
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}


int getStickScore(const sf::Color& color)
{
    if (color == sf::Color::White)
    {
        return 10;
    }
    else if (color == sf::Color::Green)
    {
        return 8;
    }
    else if (color == sf::Color::Yellow)
    {
        return 5;
    }
    else if (color == sf::Color::Red)
    {
        return 3;
    }
    else if (color == sf::Color::Magenta)
    {
        return 2;
    }
    else if (color == sf::Color::Blue)
    {
        return 1;
    }

    return 0; // Return 0 for unrecognized colors
}
