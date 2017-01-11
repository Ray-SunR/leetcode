#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
Given a MxN matrix where each element can either be 0 or 1. We need to find the shortest 
path between a given source cell to a destination cell. The path can only be created out 
of a cell if its value is 1.
*/

struct Position
{
	Position(int x, int y, int step)
	: x(x)
	, y(y)
	, step(step){}
	int x;
	int y;
	int step;
};

int shortestMazePath(int maze[][10], int m, int n, int x, int y)
{
	queue<Position> q; q.push(Position(0, 0, 0));
	int min = INT_MAX;
	while (!q.empty())
	{
		Position pos = q.front(); q.pop();
		if (pos.x == x && pos.y == y)
		{
			min = min < pos.step ? min : pos.step;
			continue;
		}

		// left
		if (pos.x - 1 >= 0 && maze[pos.x - 1][pos.y] && pos.step + 1 < min)
		{
			q.push(Position(pos.x - 1, pos.y, pos.step + 1));
		}

		// right
		if (pos.x + 1 < n && maze[pos.x + 1][pos.y] && pos.step + 1 < min)
		{
			q.push(Position(pos.x + 1, pos.y, pos.step + 1));
		}

		// top
		if (pos.y - 1 >= 0 && maze[pos.x][pos.y - 1] && pos.step + 1 < min)
		{
			q.push(Position(pos.x, pos.y - 1, pos.step + 1));
		}

		// bottom
		if (pos.y + 1 < n && maze[pos.x][pos.y + 1] && pos.step + 1 < min)
		{
			q.push(Position(pos.x, pos.y + 1, pos.step + 1));
		}
	}

	return min == INT_MAX ? -1 : min;
}

int main(void)
{
	int maze[9][10] = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                  {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                  {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
  cout << shortestMazePath(maze, 9, 10, 3, 4);
}