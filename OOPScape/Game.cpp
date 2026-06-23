#include "Game.h"

Dungeon Game::loadDungeon(const std::string& filepath)
{
    std::ifstream ifs(filepath);

    if (!ifs)
        throw std::runtime_error("Failed to open file");

    return Dungeon(ifs);
}

Game::Game(const std::string& filepath, char input)
    : currentLevel(1), dungeon(loadDungeon(filepath))
    , hero(HeroFactory::create(dungeon.getLevels()[0].getHeroStarting(), input))
{
}

const Dungeon& Game::getDungeon() const
{
    return dungeon;
}

Hero& Game::getHero()
{
    return *hero;
}

const Hero& Game::getHero() const
{
    return *hero;
}

unsigned int Game::getCurrentLevel() const
{
    return currentLevel;
}

void Game::run()
{
    while (true)
    {
        std::cout << *this;
        std::cout << "\nCommand(W - up, A - left, S - down, D - right or Q - specila abl):\n";

        std::string input;
        std::cin >> input;

        auto cmd = CommandFactory::create(input, *(this));
        if (cmd) cmd->execute();

        
        if (EndCondition()) break;

        
        /*for (auto& e : enemies)
            e->update(*this);*/

        if (EndCondition()) break;
    }

}

bool Game::EndCondition()
{
    bool exit = hero->getPosition() == dungeon.getLevels()[currentLevel - 1].getExit();
    if (exit)
    {   
        std::cout << *this;

        if (currentLevel < this->dungeon.getLevels().size())
        {
            
            std::cout << "\nBeat Level!\n";

            currentLevel++;
            loadLevel();

            return false;
        }

        else
        {
            std::cout << "\nBeat Game!\n";
        }
    }
     return exit;
}

void Game::loadLevel()
{
    hero->setPosition(dungeon.getLevels()[currentLevel - 1].getHeroStarting());
}

std::ostream& operator<<(std::ostream& os, const Game& game)
{
    setConsolColor(Color::Blue);

    const Level& level = game.getDungeon().getLevels()[game.getCurrentLevel() - 1];
    unsigned int size = level.getSize();

    os << std::string(4, ' ');
    for (unsigned int i = 0; i < size; i++)
    {
        os << ' ' << i << ' ';
    }
    os << '\n';

    os << std::string(4, ' ');
    os << std::string(size * 3, '-');
    os << '\n';




    for (unsigned int row = 0; row < size; row++)
    {
        setConsolColor(Color::Blue);
        os << ' ' << row << " |";
        setConsolColor(Color::None);


        for (unsigned int col = 0; col < size; col++)
        {
            if(game.hero->getPosition() == Position(row,col))
                os << NodeFactory::createNode('H');
            else
                os << level.getMap()[row][col];
        }
        os << '\n';
    }

    setConsolColor(Color::Blue);

    os << std::string(4, ' ');
    os << std::string(size * 3, '-');
    os << '\n';

    os << std::string(4, ' ');
    for (unsigned int i = 0; i < size; i++)
    {
        os << ' ' << i << ' ';
    }
    setConsolColor(Color::None);

    return os;
}
