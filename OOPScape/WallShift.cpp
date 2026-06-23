#include "WallShift.h"
#include "Game.h"

bool WallShift::use(Game& game)
{
    Hero& hero = game.getHero();
    Position next = hero.getPosition();
    Position over = next;
    Direction direction;
    bool dir = false;
    std::cout << "\nCommand(W - up, A - left, S - down, D - right, Q - quit); \n";

    while (!dir)
    {
        char c;
        std::cin >> c;

        switch (c) 
        {
        case 'W': { direction = Direction::Up; dir = true; break; }
        case 'D': { direction = Direction::Right; dir = true; break; }
        case 'S': { direction = Direction::Down; dir = true; break; }
        case 'A': { direction = Direction::Left; dir = true; break; }
        case 'Q': { return false; }
        default:
        {
            setConsolColor(Color::Red);
            std::cout << "Incorect Input\n"; 
            setConsolColor(Color::None);
            continue;
        }
        }
    }


    switch (direction)
    {
    case Direction::Up: { next += Position(-1, 0); over += Position(-2, 0); break; };
    case Direction::Right: { next += Position(0, 1); over += Position(0, 2); break; };
    case Direction::Down: { next += Position(1, 0); over += Position(2, 0); break; }
    case Direction::Left: { next += Position(0, -1); over += Position(0, -2); break; }

    }


    if (game.getDungeon().getLevels()[game.getCurrentLevel() - 1].isWalable(over)
        && !game.getDungeon().getLevels()[game.getCurrentLevel() - 1].isWalable(next))
    {
        hero.setPosition(over);
        return true;
    }
    setConsolColor(Color::Yellow);
    std::cout << "Couldnt WallShift!\n";
    setConsolColor(Color::None);

    return false;
}
