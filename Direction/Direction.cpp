#include "Direction.h"

Direction::Direction(Directions d)
:m_direction{d}{
}

std::ostream& operator<< (std::ostream& stream, Direction d)
{
    stream << Direction::directions[d];
}

Direction operator-(Direction d);
