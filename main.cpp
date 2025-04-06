#include <iostream>
#include <limits> // for std::numeric_limits
#include <cassert>
#include <algorithm>
#include "Tile/Tile.h"
#include "Board/Board.h"
#include "Direction/Direction.h"
#include "Point/Point.h"

namespace GameSettings
{
    constexpr int g_consolelines(100);
}

namespace UserInput
{
    constexpr char validCommand[]{'w', 's', 'a', 'd', 'q'};

    void ignoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    char getCharacter()
    {
        char input{};
        std::cin >> input;
        ignoreLine();
        return input;
    }

    bool isValidCommand(char ucmd)
    {
        return std::find(std::begin(validCommand), std::end(validCommand), ucmd) != std::end(validCommand);
    }

    char getCommandFromUser()
    {
        char ucmd{};
        while(!isValidCommand(ucmd))
            ucmd = getCharacter();
        
        return  ucmd;
    }

    bool isQuitCommand(char ucmd)
    {
        return ucmd == 'q';
    }

    Direction charToDirection(char ucmd)
    {
        assert(isValidCommand(ucmd) && !isQuitCommand(ucmd));

        int cmdIndex{static_cast<int>(std::distance(validCommand, std::find(std::begin(validCommand), std::end(validCommand), ucmd)))};

        return Direction{static_cast<Direction::Directions>(cmdIndex)};

    }
}

int main()
{
    Board b{};
    
    b.randomize();

    for(int i{0} ; i < GameSettings::g_consolelines; i++) std::cout << '\n';
    std::cout << b;
    for(int i{0} ; i < GameSettings::g_consolelines/3; i++) std::cout << '\n';

    while(true)
    {
        char ops{UserInput::getCommandFromUser()};
        
        if(UserInput::isQuitCommand(ops))
        {
            std::cout << "Bye!\n";
            break;
        }
        if(b.moveTile(UserInput::charToDirection(ops)))
        {
            for(int i{0} ; i < GameSettings::g_consolelines; i++) std::cout << '\n';
            std::cout << b;
            for(int i{0} ; i < GameSettings::g_consolelines/3; i++) std::cout << '\n';
        }
        if(b.isSolved())
        {
            std::cout << "\n\nYou won!\n\n";
            break;
        }
    }
    
    return 0;
}
