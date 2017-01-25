#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// a robot sitting on the top left corner and wants to move to the bottom right (m, n)
// how many possible paths?
int totalMoves(int m, int n)
{
	if (m == 0 || n == 0)
	{
		return 1;
	}
	return totalMoves(m - 1, n) + totalMoves(m, n -1);
}

// imagine there are obstacles in the matrix, 1 means open, 0 means close. How many 
// possible paths?
int totalMoves(int m, int n, vector<vector<int> >& grid)
{
	int count = 0;
	queue<pair<int, int> > q;
	q.push(pair<int, int>(0, 0));
	while (!q.empty())
	{
		pair<int, int> pos = q.front(); q.pop();
		if (!grid[pos.first][pos.second]) { continue; }
		if (pos.first == m && pos.second == n) { count++; }
		if (pos.first + 1 <= m)
		{
			q.push(pair<int, int>(pos.first + 1, pos.second));
		}

		if (pos.second + 1 <= n)
		{
			q.push(pair<int, int>(pos.first, pos.second + 1));
		}
	}
	return count;
}

// BFS doesn't keep all paths. BFS will be useful for finding the shortest path from a -> b
// DFS is basically backtracing
void allPathsWithObstacles(int x, int y, int m, int n, vector<vector<int> >& grid, vector<vector<pair<int, int> > >& paths, vector<pair<int, int> >& cur)
{
	if (x > m || y > n) { return; }
	if (!grid[x][y]) { return; }
	cur.push_back(pair<int, int>(x, y));
	if (x == m && y == n)
	{
		paths.push_back(cur);
		cur.pop_back();
		return;
	}

	allPathsWithObstacles(x + 1, y, m, n, grid, paths, cur);
	allPathsWithObstacles(x, y + 1, m, n, grid, paths, cur);
	cur.pop_back();
}


struct Pos
{
	Pos(int x, int y, int step)
	: x(x)
	, y(y)
	, step(step){}
	int x;
	int y;
	int step;
};

int shortestPath(int startx, int starty, int destx, int desty, int m, int n, vector<vector<int> >& grid)
{
	queue<Pos> q;
	q.push(Pos(startx, starty, 0));
	int min = INT_MAX;

	vector<vector<bool> > visited;
	for (int i = 0; i <grid.size(); i++)
	{
		vector<bool> tmp;
		for (int j = 0; j < grid[i].size(); j++)
		{
			tmp.push_back(false);
		}
		visited.push_back(tmp);
	}

	while (!q.empty())
	{
		Pos top = q.front(); q.pop();
		cout << "visit: " << top.x << "," << top.y << endl;
		visited[top.x][top.y] = true;
		if (top.x == destx && top.y == desty)
		{
			cout << "found" << endl;
			min = top.step < min ? top.step : min;
			continue;
		}

		// top
		if (top.y - 1 >= 0 && grid[top.x][top.y - 1] && top.step + 1 < min && !visited[top.x][top.y - 1])
		{
			q.push(Pos(top.x, top.y - 1, top.step + 1));
		}

		// bottom
		if (top.y + 1 < m && grid[top.x][top.y + 1] && top.step + 1 < min && !visited[top.x][top.y + 1])
		{
			q.push(Pos(top.x, top.y + 1, top.step + 1));
		}

		// left
		if (top.x - 1 >= 0 && grid[top.x - 1][top.y] && top.step + 1 < min && !visited[top.x - 1][top.y])
		{
			q.push(Pos(top.x - 1, top.y, top.step + 1));
		}

		// right
		if (top.x + 1 < n && grid[top.x + 1][top.y] && top.step + 1 < min && !visited[top.x + 1][top.y])
		{
			q.push(Pos(top.x + 1, top.y, top.step + 1));
		}
	}
	return min;
}

void allPaths(int startx, int starty, int destx, int desty, int m, int n, vector<vector<int> >& grid, vector<vector<Pos> >& paths, vector<Pos>& cur, vector<vector<bool> >& visited)
{
	cur.push_back(Pos(startx, starty, 0));
	visited[startx][starty] = true;
	if (startx == destx && starty == desty)
	{
		paths.push_back(cur);
		cur.pop_back();
		visited[startx][starty] = false;
		return;
	}

	// top
	if (startx - 1 >= 0 && grid[startx - 1][starty] && !visited[startx - 1][starty])
	{
		allPaths(startx - 1, starty, destx, desty, m, n, grid, paths, cur, visited);
	}

	// left
	if (starty - 1 >= 0 && grid[startx][starty - 1] && !visited[startx][starty - 1])
	{
		allPaths(startx, starty - 1, destx, desty, m, n, grid, paths, cur, visited);
	}

	// bottom
	if (startx + 1 < m && grid[startx + 1][starty] && !visited[startx + 1][starty])
	{
		allPaths(startx + 1, starty, destx, desty, m, n, grid, paths, cur, visited);
	}

	// right
	if (starty + 1 < n && grid[startx][starty + 1] && !visited[startx][starty + 1])
	{
		allPaths(startx, starty + 1, destx, desty, m, n, grid, paths, cur, visited);
	}

	cur.pop_back();
	visited[startx][starty] = false;
}

int main(void)
{
	cout << "totalMoves for (5, 5) is: " << totalMoves(3, 3) << endl;

	int r1[] = {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 };
	int r2[] = {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
	int r3[] = {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 };
	int r4[] = {0, 0, 1, 0, 1, 0, 0, 0, 0, 1 };
	int r5[] = {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 };
	int r6[] = {1, 0, 1, 1, 1, 1, 1, 1, 0, 0 };
	int r7[] = {1, 0, 1, 0, 0, 0, 1, 1, 0, 1 };
	int r8[] = {1, 0, 1, 1, 1, 1, 1, 1, 1, 1 };
	int r9[] = {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 };

	vector<int> vr1(r1, r1 + sizeof(r1) / sizeof(r1[0]));
	vector<int> vr2(r2, r2 + sizeof(r2) / sizeof(r2[0]));
	vector<int> vr3(r3, r3 + sizeof(r3) / sizeof(r3[0]));
	vector<int> vr4(r4, r4 + sizeof(r4) / sizeof(r4[0]));
	vector<int> vr5(r5, r5 + sizeof(r5) / sizeof(r5[0]));
	vector<int> vr6(r6, r6 + sizeof(r6) / sizeof(r6[0]));
	vector<int> vr7(r7, r7 + sizeof(r7) / sizeof(r7[0]));
	vector<int> vr8(r8, r8 + sizeof(r8) / sizeof(r8[0]));
	vector<int> vr9(r9, r9 + sizeof(r9) / sizeof(r9[0]));

	vector<vector<int> > maze;
	maze.push_back(vr1);
	maze.push_back(vr2);
	maze.push_back(vr3);
	maze.push_back(vr4);
	maze.push_back(vr5);
	maze.push_back(vr6);
	maze.push_back(vr7);
	maze.push_back(vr8);
	maze.push_back(vr9);

	cout << "totalMoves with grid 4, 4 is: " << totalMoves(3, 3, maze) << endl;

	vector<vector<pair<int, int> > > paths;
	vector<pair<int, int> > cur;
	//allPathsWithObstacles(0, 0, 10, 11, maze, paths, cur);
	for (int i = 0; i < paths.size(); i++)
	{
		for (int j = 0; j < paths[i].size(); j++)
		{
			cout << "(" << paths[i][j].first << "," << paths[i][j].second << ")" << "->";
		}
		cout << endl;
	}

	cout << shortestPath(0, 0, 3, 4, 9, 10, maze) << endl;
	vector<vector<Pos> > allpaths;
	vector<Pos> current;

	vector<vector<bool> > visited;
	for (int i = 0; i < maze.size(); i++)
	{
		vector<bool> tmp;
		for (int j = 0; j < maze[i].size(); j++)
		{
			tmp.push_back(false);
		}
		visited.push_back(tmp);
	}

	allPaths(0, 0, 3, 4 ,9, 10, maze, allpaths, current, visited);

	cout << "size: " << allpaths.size() << endl;
	for (int i = 0; i < allpaths.size(); i++)
	{
		for (int j = 0; j < allpaths[i].size(); j++)
		{
			cout << "(" << allpaths[i][j].x << "," << allpaths[i][j].y << ")" << " -> ";
		}
		cout << endl;
	}
	return 0;
}