#include "Tile.h"


Tile::Tile(int num)
: m_num{num}{}

const int Tile::getNum() const
{
    return m_num;
}

bool Tile::isEmpty() const
{
    return m_num == 0;
}

std::ostream& operator<< (std::ostream& out, const Tile t)
{
    out << ( t.isEmpty() ? ' ' : t.getNum() );
    return out;
}
