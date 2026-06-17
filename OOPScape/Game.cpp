#include "Game.h"

Dungeon Game::loadDungeon(const std::string& filepath)
{
    std::ifstream ifs(filepath);

    if (!ifs)
        throw std::runtime_error("Failed to open file");

    return Dungeon(ifs);
}

Game::Game(const std::string& filepath)
    : currentLevel(1),
    dungeon(loadDungeon(filepath))
{
}

Dungeon Game::getDungeon() const
{
    return dungeon;
}

std::ostream& operator<<(std::ostream& os, const Game& game)
{
    os << game.dungeon;

    return os;
}
