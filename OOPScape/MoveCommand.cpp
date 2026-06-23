#include "MoveCommand.h"

MoveCommand::MoveCommand(Hero& aHero, const Direction& aDirection, const Level& aLevel)
	: hero(aHero), direction(aDirection), level(aLevel)
{
}

bool MoveCommand::execute()
{
    if (!hero.move(level, direction))
    {
        setConsolColor(Color::Red);
        std::cout << "Ivalid movement!\n";
        setConsolColor(Color::None);
        return false;
    }
    return true;
}
