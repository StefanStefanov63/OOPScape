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
    , enemies(EnemyFactory::createAll(dungeon.getLevels()[0]))
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

std::vector<std::unique_ptr<Enemy>>& Game::getEnemies()
{
    return enemies;
}

void Game::run()
{
    captureGameState();
    while (true)
    { 
        std::cout << *this;
        std::cout << "\nCommand(W - up, A - left, S - down, D - right or Q - specila abl):\n";

        std::string input;
        std::cin >> input;

        auto command = CommandFactory::create(input, *(this));
        if (command)
        {
           if (command->execute())
           {
               if (EndCondition()) break;

               for (auto& e : enemies)
                   e->move(hero->getPosition(), dungeon.getLevels()[currentLevel - 1]);

               if (EndCondition()) break;

              captureGameState();
           }
        }
    }
}

void Game::captureGameState()
{

    std::vector<Position> enemyPos;
    for (auto& e : enemies)
    {
        enemyPos.push_back(e->getPosition());
    }
    history.push(GameState(currentLevel, hero->getPosition(), enemyPos));
}

bool Game::rewindGameState()
{
   if (history.empty() || history.size() <2)
       return false;

   history.pop();
   restoreGameState(history.top());
   history.pop();
   return true;
}

void Game::restoreGameState(const GameState& state)
{
    int i = 0;
    hero->setPosition(state.heroPos);
    for (auto& e : enemies)
    {
        e->setPosition(state.enemiesPos[i]);
        i++;
    }
}

bool Game::EndCondition()
{
    bool enemy = false;

    for (auto& e : enemies)
    {
        if (hero->getPosition() == e->getPosition() && !e->isStunned())
        {
            enemy = true;
            break;
        }
    }

    if (enemy)
    {
        std::cout << *this;
        setConsolColor(Color::LightRed);
        std::cout << "\nYou lost, the monsters got you!";
        setConsolColor(Color::None);
        return enemy;
    }

    bool exit = hero->getPosition() == dungeon.getLevels()[currentLevel - 1].getExit();
    if (exit)
    {   
        std::cout << *this;

        if (currentLevel < this->dungeon.getLevels().size())
        {
            setConsolColor(Color::Green);
            std::cout << "\nBeat Level!\n";
            setConsolColor(Color::None);

            currentLevel++;
            loadLevel();

            return false;
        }

        else
        {
            setConsolColor(Color::Yellow);
            std::cout << "\nBeat Game!\n";
            setConsolColor(Color::None);
        }
    }
     return exit;
}

void Game::loadLevel()
{
    history = std::stack<GameState>();
    hero->setPosition(dungeon.getLevels()[currentLevel - 1].getHeroStarting());
    enemies.clear();
    enemies = EnemyFactory::createAll(dungeon.getLevels()[currentLevel - 1]);

    for (auto& e : this->enemies)
    {
        e->setStunTurns(e->getStunTurns() + 1);
    }
}

std::ostream& operator<<(std::ostream& os, const Game& game)
{
    setConsolColor(Color::Blue);

    const Level& level = game.getDungeon().getLevels()[game.getCurrentLevel() - 1];
    unsigned int size = level.getSize();

    setConsolColor(Color::Blue);
    os << std::string(size * 3 + 2, '-');
    os << '\n';
    setConsolColor(Color::None);




    for (unsigned int row = 0; row < size; row++)
    {
        setConsolColor(Color::Blue);
        os << "|";
        setConsolColor(Color::None);


        for (unsigned int col = 0; col < size; col++)
        {
            bool enemy = false;
            
            for (auto& e : game.enemies)
            {
                if (e->getPosition() == Position(row, col))
                {
                    if(game.hero->getPosition() == Position(row, col) && e->isStunned())
                        os << *game.hero;
                    else
                        os << *e;
                    
                    enemy = true;
                    break;
                }

            }
            if (!enemy)
            {
                if (game.hero->getPosition() == Position(row, col))
                    os << *game.hero;
                else
                    os << level.getMap()[row][col];
            }
        }
        setConsolColor(Color::Blue);
        os << "|\n";
        setConsolColor(Color::None);
    }

    setConsolColor(Color::Blue);
    os << std::string(size * 3 + 2, '-');
    os << '\n';
    setConsolColor(Color::None);

    return os;
}
