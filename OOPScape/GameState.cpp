#include "GameState.h"

GameState::GameState(unsigned int currentLevel, const Position& heroPos, const std::vector<Position>& enemiesPos)
: currentLevel(currentLevel), heroPos(heroPos), enemiesPos(enemiesPos)
{
}
