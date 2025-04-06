#include <ostream>
#include "Board.h"
#include "../Point/Point.h"


Board::Board()
{
    for (int i{0}; i < BoardConfig::nbOfLines; i++)
    {
        for (int j{0}; j < BoardConfig::nbOfCols; j++){
            m_board[i][j].setNum((static_cast<int>(BoardConfig::nbOfLines)*i) + j + 1);
        }

        m_board[BoardConfig::nbOfLines - 1][BoardConfig::nbOfCols - 1].setNum(0);
    }
}

// bool Board::isSolved() const
// {

// }

// void Board::slideTiles(Point point){

// }

std::ostream& operator<< (std::ostream& stream, Board b)
{
    for (int i{0}; i < BoardConfig::nbOfLines; i++)
    {
        for (int j{0}; j < BoardConfig::nbOfCols; j++){
            stream << b.m_board[i][j];
        }
        stream<<'\n';
    }

    return stream;
}
