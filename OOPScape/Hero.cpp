#include "Hero.h"

Hero::Hero(const Position& currentPosition, std::unique_ptr<Ability> ability)
	: IEntity(currentPosition), ability(std::move( ability))
{
}

bool Hero::useAbilty(Game& game)
{
    return ability->use(game);
}

bool Hero::move(const Level& level, Direction direction)
{
    Position next = currentPosition;

    switch (direction)
    {
    case Direction::Up: { next += Position(-1, 0); break; };
    case Direction::Right: { next += Position(0, 1); break; };
    case Direction::Down: { next += Position(1, 0); break; }
    case Direction::Left: { next += Position(0, -1); break; }

    }

    if (level.isWalable(next))
    {
        currentPosition = next;
        return true;
    }

    return false;
}

std::ostream& operator<<(std::ostream& os, const Hero& enemy)
{
    setConsolColor(Color::Yellow);
    os << " H ";
    setConsolColor(Color::None);

    return os;
}
