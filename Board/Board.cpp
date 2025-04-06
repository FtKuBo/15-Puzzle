#include "Board.h"


Board::Board()
{
    for (int i{0}; i < BoardConfig::nbOfLines; i++)
    {
        for (int j{0}; j < BoardConfig::nbOfCols; j++){
            m_board[i][j].setNum((static_cast<int>(BoardConfig::nbOfLines)*i) + j + 1);
        }

    }
    m_board[BoardConfig::nbOfLines - 1][BoardConfig::nbOfCols - 1].setNum(0);
}

bool Board::moveTile(const Direction& d)
{
    Point emptyTilePoint{}, adjacentToEmptyTilePoint{};
    for (int i{0}; i < BoardConfig::nbOfLines; i++)
    {
        for (int j{0}; j < BoardConfig::nbOfCols; j++){
            if(m_board[i][j].isEmpty())
            {
                emptyTilePoint = Point{i, j};
                adjacentToEmptyTilePoint = emptyTilePoint.getAdjacentPoint(d);
                goto emptyTileFound;
            }
        }

    }
emptyTileFound:
    // Checking wether the adjacent point is valid
    if(adjacentToEmptyTilePoint.getX() >= 0 && adjacentToEmptyTilePoint.getX() < BoardConfig::nbOfCols && adjacentToEmptyTilePoint.getY() >= 0 && adjacentToEmptyTilePoint.getY() < BoardConfig::nbOfLines)
    {
        std::swap(m_board[emptyTilePoint.getY()][emptyTilePoint.getX()], m_board[adjacentToEmptyTilePoint.getY()][adjacentToEmptyTilePoint.getX()]);
        return true;
    }
    return false;
}

void Board::randomize()
{
    for(int i{0}; i < 1000; i++)
    {
        for (int i{0}; i < BoardConfig::nbOfLines; i++)
        {
            for (int j{0}; j < BoardConfig::nbOfCols; j++){
                this->moveTile(Direction::randomDirection());
            }
        }
    }
}

bool Board::isSolved() const
{
    static Board s_solved{};
    for (int i{0}; i < BoardConfig::nbOfLines; i++)
    {
        for (int j{0}; j < BoardConfig::nbOfCols; j++){
            if( m_board[i][j].getNum() != s_solved.m_board[i][j].getNum() ) return false;
        }
    }
    return true;
}


std::ostream& operator<< (std::ostream& stream, const Board& b)
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
