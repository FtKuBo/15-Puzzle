#pragma once
#include <ostream>
#include "../Tile/Tile.h"
#include "../Direction/Direction.h"
#include "../Point/Point.h"
#include "../Random.h"

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
    bool moveTile(const Direction& d);
    void randomize();
    bool isSolved() const;
    friend std::ostream& operator<< (std::ostream& steam, const Board& b);
};
