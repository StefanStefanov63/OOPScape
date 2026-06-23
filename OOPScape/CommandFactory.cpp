#include "CommandFactory.h"

#include "Game.h"

std::unique_ptr<ICommand> CommandFactory::create(const std::string& input, Game& game)
{
    Hero& hero = game.getHero();
    const Level& level = game.getDungeon().getLevels()[game.getCurrentLevel() - 1];

    if (input == "W")
        return std::make_unique<MoveCommand>(hero, Direction::Up, level);

    else if (input == "D")
        return std::make_unique<MoveCommand>(hero, Direction::Right, level);

    else if (input == "S")
        return std::make_unique<MoveCommand>(hero, Direction::Down, level);

    else if (input == "A")
        return std::make_unique<MoveCommand>(hero, Direction::Left, level);

    else if (input == "Q")
         return std::make_unique<AbilityCommand>(game);

    return std::make_unique<NullCommand>();
}
