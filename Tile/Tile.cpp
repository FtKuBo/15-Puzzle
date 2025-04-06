#include "Tile.h"


Tile::Tile(int num)
: m_num{num}
{
}

const int Tile::getNum() const
{
    return m_num;
}

void Tile::setNum(int num)
{
    m_num = num;
}

bool Tile::isEmpty() const
{
    return m_num == 0;
}

std::ostream& operator<<(std::ostream& stream, Tile tile)
{
    if (tile.getNum() > 9) // if two digit number
        stream << " " << tile.getNum() << " ";
    else if (tile.getNum() > 0) // if one digit number
        stream << "  " << tile.getNum() << " ";
    else if (tile.getNum() == 0) // if empty spot
        stream << "    ";
    return stream;
}
