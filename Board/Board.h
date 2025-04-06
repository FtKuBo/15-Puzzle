#pragma once
#include "../Tile/Tile.h"
#include <ostream>

namespace BoardConfig
{
    constexpr std::size_t nbOfCols{4};
    constexpr std::size_t nbOfLines{4};
    constexpr std::size_t nbOfTiles{nbOfCols*nbOfLines};
}

class Board
{
private:
    Tile m_board[BoardConfig::nbOfLines][BoardConfig::nbOfCols]{};

public:
    Board();
    bool isSolved() const;
    void slideTiles();
    friend std::ostream& operator<< (std::ostream& steam, Board);
};
