#include "CommandFactory.h"

#include "Game.h"
std::unique_ptr<ICommand> CommandFactory::create(const std::string& input, Game& game)
{
    Hero& hero = game.getHero();
    const Level& level = game.getDungeon().getLevels()[game.getCurrentLevel() - 1];

    if (input == "W")
        return std::make_unique<MoveCommand>(hero, Direction::Up, level);

    if (input == "D")
        return std::make_unique<MoveCommand>(hero, Direction::Right, level);

    if (input == "S")
        return std::make_unique<MoveCommand>(hero, Direction::Down, level);

    if (input == "A")
        return std::make_unique<MoveCommand>(hero, Direction::Left, level);


    /* if (input == "Q")
         return std::make_unique<AbilityCommand>(static_cast<Hero&>(hero), game);*/

    return std::make_unique<NullCommand>();
}
