#include <iostream>
#include "Game.h"

int main()
{
    std::srand(std::time(0));

    std::string path ,character;
    std::cin >> path >> character;
    //std::string h = "C:/Users/Admin/Desktop/Dungeon1.txt";
   
    Game game(path, character[0]);
    game.run();
    
}
