#pragma once
#include <iostream>
#include <fstream>
#include "Dungeon.h"
class Game
{
	Dungeon dungeon;
	unsigned int currentLevel;
static Dungeon loadDungeon(const std::string& filepath);
public:
	Game(const std::string& filepath);
	
	Dungeon getDungeon() const;

	friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

