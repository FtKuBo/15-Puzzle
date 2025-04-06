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
    constexpr int g_consolelines(25);
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

// Your code goes here

// Note: save your main() from the prior step, as you'll need it again in the next step
int main()
{
    std::cout << std::boolalpha;
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::up)    == Point{ 0, 1 }) << '\n';
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::down)  == Point{ 2, 1 }) << '\n';
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::left)  == Point{ 1, 0 }) << '\n';
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::right) == Point{ 1, 2 }) << '\n';
    std::cout << (Point{ 1, 1 } != Point{ 2, 1 }) << '\n';
    std::cout << (Point{ 1, 1 } != Point{ 1, 2 }) << '\n';
    std::cout << !(Point{ 1, 1 } != Point{ 1, 1 }) << '\n';

    return 0;
}


// int main()
// {
//     Board b{};
    
//     for(int i{0} ; i < GameSettings::g_consolelines; i++) std::cout << '\n';
    
//     std::cout << b;

//     for(int i{0} ; i < 4 ; i++)
//         std::cout << "Generating random direction..." << Direction::randomDirection() << '\n';


//     while(true)
//     {
//         char ops{UserInput::getCommandFromUser()};
        
//         if(UserInput::isQuitCommand(ops))
//         {
//             std::cout << "Bye!\n";
//             break;
//         }
        
//         std::cout << "Valid command: " << UserInput::charToDirection(ops) << '\n';
//     }
    
//     return 0;
// }
