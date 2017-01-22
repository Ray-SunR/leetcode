/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
public:
	Graph(int num_vertices)
	{
		for (int i = 0; i < num_vertices; i++) { m_data.push_back(vector<int>()); }
	}

	void AddEdge(int from, int to)
	{
		m_data[from].push_back(to);
	}

	bool TopoLogicalSort(int u, std::stack<int>& ret, vector<bool>& visited, vector<bool>& currentstack)
	{
		visited[u] = true;
		currentstack[u] = true;
		const vector<int>& adjacent = m_data[u];
		for (int i = 0; i < adjacent.size(); i++)
		{
			if (currentstack[adjacent[i]]) { ret = stack<int>(); return false; }
			if (!visited[adjacent[i]])
			{
				if (!TopoLogicalSort(adjacent[i], ret, visited, currentstack)) { return false; }
			}
		}
		ret.push(u);
		currentstack[u] = false;
		return true;
	}
private:
	std::vector<vector<int> > m_data;
};

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) 
	{
		Graph g(numCourses);
		for (int i = 0; i < prerequisites.size(); i++)
		{
			g.AddEdge(prerequisites[i].second, prerequisites[i].first);
		}

		vector<bool> visited;
		stack<int> stk;
		vector<int> ret;
		for (int i = 0; i < numCourses; i++) { visited.push_back(false); }
		vector<bool> currentstack = visited;
		for (int i = 0; i < numCourses; i++)
		{
			if (!visited[i])
			{
				if (!g.TopoLogicalSort(i, stk, visited, currentstack)) { return ret; }
			}
		}
		while (!stk.empty())
		{
			ret.push_back(stk.top()); stk.pop();
		}
		return ret;
	}
};

int main(void)
{
	/*
	10
[[1,0],[7,0], [4, 1], [4, 7], [2, 1], [8, 7], [9 ,8], [9, 4], [5, 4], [3, 2], [3, 5], [6, 5], [6, 9]]
	*/
	Solution s;
	vector<pair<int, int> > prerequisites;
	prerequisites.push_back(pair<int, int>(1, 0));
	prerequisites.push_back(pair<int, int>(7, 0));
	prerequisites.push_back(pair<int, int>(4, 1));
	prerequisites.push_back(pair<int, int>(4, 7));
	prerequisites.push_back(pair<int, int>(2, 1));
	prerequisites.push_back(pair<int, int>(8, 7));
	prerequisites.push_back(pair<int, int>(9, 8));
	prerequisites.push_back(pair<int, int>(9, 4));
	prerequisites.push_back(pair<int, int>(5, 4));
	prerequisites.push_back(pair<int, int>(3, 2));
	prerequisites.push_back(pair<int, int>(3, 5));
	prerequisites.push_back(pair<int, int>(6, 5));
	prerequisites.push_back(pair<int, int>(6, 9));
	//prerequisites.push_back(pair<int, int>(0, 6));

	vector<int> ret = s.findOrder(10, prerequisites);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
	return 0;
}