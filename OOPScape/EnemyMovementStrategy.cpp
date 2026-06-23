#include "EnemyMovementStrategy.h"

bool EnemyMovementStrategy::canMove(int x, int y, const Level& level)
{ 
    return x >= 0 && y >= 0 &&
        x < level.getSize() &&
        y < level.getSize() &&
        level.getMap()[x][y].isWalkable();
}