#pragma once
#include "../Direction/Direction.h"

class Point
{
private:
    int m_y{};
    int m_x{};

public:
    Point() = default;
    Point(int y, int x);
    int getY();
    int getX();
    Point getAdjacentPoint(const Direction& d);
    friend bool operator== (const Point& p1, const Point& p2);
    friend bool operator!= (const Point& p1, const Point& p2);

};
