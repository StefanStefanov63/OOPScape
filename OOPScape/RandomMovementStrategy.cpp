#include "RandomMovementStrategy.h"

bool RandomMovementStrategy::move(Position& enemyPos, const Position& heroPos, const Level& level)
{
    const int dx[4] = { -1, 1, 0, 0 };
    const int dy[4] = { 0, 0, -1, 1 };

    for (int i = 0; i < 4; i++)
    {
        int dir = std::rand() % 4;

        int nx = enemyPos.getX() + dx[dir];
        int ny = enemyPos.getY() + dy[dir];

        if (canMove(nx, ny, level))
        {
            enemyPos.setX(nx);
            enemyPos.setY(ny);
            return true;
        }
    }
    return false;
}
