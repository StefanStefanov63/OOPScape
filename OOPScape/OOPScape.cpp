#include <iostream>
#include "Game.h"

int main()
{
    std::srand(std::time(0));
    std::string h = "C:/Users/Admin/Desktop/Dungeon1.txt";
   
    Game game(h,'C');
    game.run();
    
}
