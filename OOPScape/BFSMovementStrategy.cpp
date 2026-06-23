#include "BFSMovementStrategy.h"

bool BFSMovementStrategy::move(Position& enemyPos, const Position& heroPos, const Level& level)
{
	unsigned int n = level.getSize();
	unsigned int W = n;


	std::vector<int> parent(W * W, -1);
	std::queue<Position> q;


	int start = enemyPos.getY() * W + enemyPos.getX();
	int goal = heroPos.getY() * W + heroPos.getX();


	parent[start] = start;
	q.push(enemyPos);

	const int dx[4] = { -1, 1, 0, 0 };
	const int dy[4] = { 0, 0, -1, 1 };
	bool found = false;


	while (!q.empty())
	{
		Position cur = q.front();
		q.pop();

		int curI = cur.getY() * W + cur.getX();

		if (curI == goal)
		{
			found = true;
			break;
		}

		for (int k = 0; k < 4; ++k)
		{
			unsigned int nx = cur.getX() + dx[k];
			unsigned int ny = cur.getY() + dy[k];

			if (!canMove(nx, ny, level))
				continue;
			unsigned int ni = ny * W + nx;

			if (parent[ni] != -1) continue;
			parent[ni] = curI;
			q.push(Position(nx, ny));
		}
	}
	if (!found)
		return false;

	int cur = goal;

	while (parent[cur] != start && cur != start)
		cur = parent[cur];

	if (cur == start)
		return false;

	enemyPos.setX(cur % W);
	enemyPos.setY(cur / W);
	return true;
}
