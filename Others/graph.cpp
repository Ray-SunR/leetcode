#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include "priority_queue.hpp"
#include "UF.hpp"

using namespace std;

struct Edge
{
	Edge(int dest, int weight)
	: m_dest(dest)
	, m_weight(weight){}
	int m_weight;
	int m_dest;
};

class Graph
{
public:
	void AddEdge(int u, int v, int weight = 1);
	void BreadFirstSearch(std::vector<int>& ret) const;
	void DepthFirstSearch(std::vector<int>& ret) const;
	void TopologicalSort(std::vector<int>& ret) const;
	void MST_Kruscal(std::vector<int>& ret) const;
	void MST_Prim(std::vector<int>& ret) const;
	bool HasCycleDFS() const; 
	bool HasCycleUnionFind() const;
private:
	void TopologicalSortHelper(int u, std::stack<int>& ret, std::vector<bool>& visited) const;
	void DFSHelper(int u, std::vector<int>& ret, std::vector<bool>& visited) const;
	bool HasCycleDFSHelper(int u, vector<bool>& visited) const;
	map<int, vector<Edge> > m_data;
};

void Graph::TopologicalSortHelper(int u, std::stack<int>& ret, std::vector<bool>& visited) const
{
	visited[u] = true;
	const std::vector<Edge>& adjacent = m_data.find(u)->second;
	for (int i = 0; i < adjacent.size(); i++)
	{
		if (!visited[adjacent[i].m_dest])
		{
			TopologicalSortHelper(adjacent[i].m_dest, ret, visited);
		}
	}
	ret.push(u);
}

bool Graph::HasCycleDFSHelper(int u, vector<bool>& visited) const
{
	visited[u] = true;
	const std::vector<Edge>& adjacent = m_data.find(u)->second;
	for (int i = 0; i < adjacent.size(); i++)
	{
		if (visited[adjacent[i].m_dest]) { return true; }
		return HasCycleDFSHelper(adjacent[i].m_dest, visited);
	}
	visited[u] = false;
	return false;
}

bool Graph::HasCycleDFS() const
{
	std::vector<bool> visited;
	for (int i = 0; i < m_data.size(); i++) { visited.push_back(false); }
	std::map<int, std::vector<Edge> >::const_iterator it = m_data.begin();
	while (it != m_data.end())
	{
		if (HasCycleDFSHelper(it->first, visited)) { return true; }
		++it;
	}
	return false;
}

// Use dfs but dfs the node's adjancet nodes then push the node
void Graph::TopologicalSort(std::vector<int>& ret) const
{
	if (HasCycleDFS()) { cout << "cycle found!" << endl; return; }
	std::vector<bool> visited;
	for (int i = 0; i < m_data.size(); i++) { visited.push_back(false); }
	map<int, std::vector<Edge> >::const_iterator it = m_data.begin();
	stack<int> stk;
	while (it != m_data.end())
	{
		if (!visited[it->first])
		{
			TopologicalSortHelper(it->first, stk, visited);
		}
		++it;
	}
	while (!stk.empty())
	{
		ret.push_back(stk.top()); stk.pop();
	}
}

void Graph::MST_Kruscal(std::vector<int>& ret) const
{
	return;
}

void Graph::MST_Prim(std::vector<int>& ret) const
{
	return;
}

bool Graph::HasCycleUnionFind() const 
{ 
	map<int, vector<Edge> >::const_iterator it = m_data.begin();
	UF unionfind(m_data.size());
	while (it != m_data.end())
	{
		const vector<Edge>& adjacent = it->second;
		for (int i = 0; i < adjacent.size(); i++)
		{
			int roota = unionfind.Find(it->first);
			int rootb = unionfind.Find(adjacent[i].m_dest);
			if (roota == rootb) { return true; }
			unionfind.Union(it->first, adjacent[i].m_dest);
		}
		++it;
	}
	return false;
}

void Graph::AddEdge(int u, int v, int weight)
{
	m_data[u].push_back(Edge(v, weight));
	if (m_data.find(v) == m_data.end())
	{
		m_data[v];
	}
}

void Graph::BreadFirstSearch(std::vector<int>& ret) const
{
	if (m_data.empty()) { return; }
	queue<int> q;
	q.push(0);
	vector<bool> visited;
	for (int i = 0; i < m_data.size(); i++) { visited.push_back(false); }

	while (!q.empty())
	{
		int front = q.front(); q.pop();
		if (visited[front]) { continue; }
		ret.push_back(front);
		visited[front] = true;
		const vector<Edge>& adjacent = m_data.find(front)->second;
		for (int i = 0; i < adjacent.size(); i++)
		{
			q.push(adjacent[i].m_dest);
		}
	}
}

void Graph::DFSHelper(int u, std::vector<int>& ret, std::vector<bool>& visited) const
{
	ret.push_back(u);
	visited[u] = true;
	const vector<Edge>& adjacent = m_data.find(u)->second;
	for (int i = 0; i < adjacent.size(); i++)
	{
		if (!visited[adjacent[i].m_dest])
		{
			DFSHelper(adjacent[i].m_dest, ret, visited);
		}
	}
}

void Graph::DepthFirstSearch(std::vector<int>& ret) const
{
	if (m_data.empty()) { return; }
	vector<bool> visited;
	for (int i = 0; i < m_data.size(); i++) { visited.push_back(false); }
	DFSHelper(0, ret, visited);
}

int main(void)
{
	Graph g;
	g.AddEdge(0, 2);
	g.AddEdge(0, 3);
	g.AddEdge(2, 1);
	g.AddEdge(1, 0);
	g.AddEdge(1, 4);
	g.AddEdge(4, 3);
	g.AddEdge(2, 5);
	g.AddEdge(5, 3);
	g.AddEdge(5, 4);

	Graph g1;
	g1.AddEdge(0, 1);
	g1.AddEdge(1, 2);

	std::vector<int> bfs;
	g.BreadFirstSearch(bfs);
	for (int i = 0; i < bfs.size(); i++)
	{
		cout << bfs[i] << " ";
	}
	cout << endl;

	std::vector<int> dfs;
	g.DepthFirstSearch(dfs);
	for (int i = 0; i < dfs.size(); i++)
	{
		cout << dfs[i] << " ";
	}
	cout << endl;

	std::vector<int> topo;
	g.TopologicalSort(topo);
	for (int i = 0; i < topo.size(); i++)
	{
		cout << topo[i] << " ";
	}
	cout << endl;

	PQ q;
	q.push(19);
	q.push(2);
	q.push(14);
	q.push(9);
	q.push(7);
	q.push(6);
	q.push(5);
	q.push(12);
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;

	Graph g2;
	g2.AddEdge(0, 1);
	g2.AddEdge(0, 2);
	g2.AddEdge(2, 1);
	g2.AddEdge(1, 3);
	g2.AddEdge(3, 4);
	g2.AddEdge(2, 4);

	if (g2.HasCycleUnionFind())
	{
		cout << "Has cycle" << endl;
	}
}