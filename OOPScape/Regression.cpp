#include "Regression.h"
#include "Game.h"

bool Regression::use(Game& game)
{
	return game.rewindGameState();
}
