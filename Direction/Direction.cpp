#include "Direction.h"


Direction::Direction(Directions d)
:m_direction{d}{
}

Direction::Directions Direction::getDirection() const
{
    return m_direction;
}

std::ostream& operator<< (std::ostream& stream, const Direction& d)
{
    stream << (Direction::strDirections[static_cast<std::size_t>(d)]);
    
    return stream;
}

Direction operator- (const Direction& d)
{
    switch (d.m_direction)
    {
    case Direction::up :
        return Direction{Direction::down};
    case Direction::down :
        return Direction{Direction::up};
    case Direction::left :
        return Direction{Direction::right};
    case Direction::right :
        return Direction{Direction::left};
    default:
        break;    
    }

    assert(1 && "Unsupported direction was passed!");
    return Direction{ Direction::up };
}
