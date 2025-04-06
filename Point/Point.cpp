#include <iostream>
#include "Point.h"
#include "../Board/Board.h"

Point::Point(int y, int x)
: m_y{y}, m_x{x}
{
}

Point Point::getAdjacentPoint(const Direction& d)
{
    switch (d.getDirection())
    {
    case Direction::up:
        if(m_y > 0)
            return Point{m_y-1, m_x};
        break;

    case Direction::down:
        if(m_y + 1 < BoardConfig::nbOfLines)
            return Point{m_y+1, m_x};
        break;
    
    case Direction::left:
        if(m_x > 0)
            return Point{m_y, m_x-1} ;
        break;

    case Direction::right:
        if(m_x + 1 < BoardConfig::nbOfCols)
            return Point{m_y, m_x+1} ;
        break;

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

