#include "AbilityCommand.h"

AbilityCommand::AbilityCommand(Game& game) : game(game)
{
}

bool AbilityCommand::execute()
{
	return game.getHero().useAbilty(game);
}
