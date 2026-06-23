#include "BardicSong.h"
#include "Game.h"

unsigned int BardicSong::STUNTURNS = 3;
unsigned int BardicSong::MINDISTANCE = 2;

bool BardicSong::use(Game& game)
{
    Position heroPos = game.getHero().getPosition();
    bool stun = false;

    for (auto& e : game.getEnemies())
    {
        if (e->isStunned()) continue;

        Position ePos = e->getPosition();

        int dist = std::abs((int)(heroPos.getX() - ePos.getX())) +
            std::abs((int)(heroPos.getY() - ePos.getY()));

        if (dist <= MINDISTANCE)
        {
            stun = true;
            e->setStunTurns(STUNTURNS);
        }
    }

    if (!stun)
    {
        setConsolColor(Color::Yellow);
        std::cout << "No enemies were stunned!\n";
        setConsolColor(Color::None);
    }
    return true;
}
