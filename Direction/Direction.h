#pragma once
#include <ostream>
#include <array>
#include <cassert>
#include "../Random.h"

class Direction
{
public:
    enum Directions
    {
        up, down, left, right, endDirections,
    };

    constexpr static std::array<std::string_view, endDirections> strDirections{"up", "down", "left", "right"};
    
private:
    Directions m_direction{};

public:
    Direction(Directions d);

    Directions getDirection()const;
    
    friend std::ostream& operator<< (std::ostream& streamß, const Direction& d); 
    friend Direction operator-(const Direction& d);

    operator std::size_t()const 
    {
        return static_cast<std::size_t>(m_direction); 
    }

    static Direction randomDirection()
    {
        Directions rd{static_cast<Directions>(Random::get(0, endDirections - 1))};

        return Direction{rd};
    }
};
