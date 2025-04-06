#include <iostream>
#include "Point.h"

Point::Point(int y, int x)
: m_y{y}, m_x{x}
{
}

int Point::getY()
{
    return m_y;
}

int Point::getX()
{
    return m_x;
}

Point Point::getAdjacentPoint(const Direction& d)
{
    switch (d.getDirection())
    {
    case Direction::up:
        return Point{m_y-1, m_x};

    case Direction::down:
        return Point{m_y+1, m_x};
    
    case Direction::left:
        return Point{m_y, m_x-1} ;

    case Direction::right:
        return Point{m_y, m_x+1} ;

    default:
        break;

    }
    
    std::cout<<"Unsupported direction was passed!\n";

    return Point{m_y, m_x};

}

bool operator== (const Point& p1, const Point& p2)
{
    return (p1.m_y == p2.m_y) && (p1.m_x == p2.m_x);
}

bool operator!= (const Point& p1, const Point& p2)
{
    return (p1.m_y != p2.m_y) || (p1.m_x != p2.m_x);
}

