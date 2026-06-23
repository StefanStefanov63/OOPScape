#include "Regression.h"
#include "Game.h"

bool Regression::use(Game& game)
{
	bool rewind = game.rewindGameState();
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
