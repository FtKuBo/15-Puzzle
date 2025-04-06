#include <iostream>
#include "Tile/Tile.h"
#include "Board/Board.h"
#include <limits> // for std::numeric_limits

namespace GameSettings
{
    constexpr int g_consolelines(25);
}

namespace UserInput
{
    constexpr char validCommand[]{'w', 'a', 's', 'd', 'q'};

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
        for(char cmd : validCommand)
            if(cmd == ucmd) return true;
        
        return false;
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
}


int main()
{
    Board b{};
    
    for(int i{0} ; i < GameSettings::g_consolelines; i++) std::cout << '\n';
    
    std::cout << b;

    while(true)
    {
        char ops{UserInput::getCommandFromUser()};

        std::cout << "Valid command: " << ops << '\n';
 
        if(UserInput::isQuitCommand(ops))
        {
            std::cout << "Bye!\n";
            break;
        }

    }
    
    return 0;
}
