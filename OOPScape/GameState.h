#pragma once
#include <memory>
#include <vector>
#include "Hero.h"
#include "Enemy.h"
struct GameState
{
	unsigned int currentLevel;
	Position heroPos;
	std::vector<Position> enemiesPos;

	GameState(unsigned int currentLevel, const Position& heroPos, const std::vector<Position>& enemiesPos);
};

