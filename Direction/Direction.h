#pragma once
#include <ostream>
#include <array>

class Direction
{
public:
    const static enum Directions
    {
        up, left, down, right, endDirections,
    };

    const static std::array<std::string, 4> directions{"up", "left", "down", "right"};
    

private:
    Directions m_direction{};

public:
    Direction(Directions d);
    friend std::ostream& operator<< (std::ostream& stream, Direction d); 
    friend Direction operator-(Direction d);
};
