#include "AbilityCommand.h"

AbilityCommand::AbilityCommand(Game& game) : game(game)
{
}

bool AbilityCommand::execute()
{
	bool rewind = game.getHero().useAbilty(game);
	if (rewind)
	{
		for (auto& e : game.getEnemies())
		{
			e->setStunTurns(e->getStunTurns() + 1);
		}
	}
	else
	{
		setConsolColor(Color::Yellow);
		std::cout << "Couldnt regreess!\n";
		setConsolColor(Color::None);
	}
	return rewind;
}
