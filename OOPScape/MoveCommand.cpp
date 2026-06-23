#include "MoveCommand.h"

MoveCommand::MoveCommand(IEntity& anEntity, const Direction& aDirection, const Level& aLevel)
	: entity(anEntity), direction(aDirection), level(aLevel)
{
}

void MoveCommand::execute()
{
    if (!entity.move(level, direction))
    {
        setConsolColor(Color::Red);
        std::cout << "Ivalid movement!\n";
        setConsolColor(Color::None);
    }
}
