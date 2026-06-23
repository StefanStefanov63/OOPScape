#pragma once
#include <iostream>
#include <fstream>
#include "Dungeon.h"
#include "Hero.h"
#include "ICommand.h"
#include "HeroFactory.h"
#include "EnemyFactory.h"
#include "CommandFactory.h"
#include "Enemy.h"
class Game
{
	Dungeon dungeon;
	unsigned int currentLevel;

	std::unique_ptr<Hero> hero;
	std::vector<std::unique_ptr<Enemy>> enemies;


static Dungeon loadDungeon(const std::string& filepath);
bool EndCondition();
void loadLevel();

public:
	Game(const std::string& filepath, char input);
	
	const Dungeon& getDungeon() const;
	Hero& getHero();
	const Hero& getHero()const;
	unsigned int getCurrentLevel() const;
	std::vector<std::unique_ptr<Enemy>>& getEnemies();


	friend std::ostream& operator<<(std::ostream& os, const Game& game);
	void run();

	
};

