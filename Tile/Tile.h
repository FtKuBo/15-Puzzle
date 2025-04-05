#pragma once
#include <iostream>

class Tile
{
private: 
    int m_num{};

public:
    Tile(int num = 0);
    const int getNum() const;
    bool isEmpty() const;
    friend std::ostream& operator<< (std::ostream& out, const Tile t);
};
