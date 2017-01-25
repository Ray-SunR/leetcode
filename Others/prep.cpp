#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include "UF.hpp"

using namespace std;


struct Edge
{
	Edge(int start, int dest, int weight)
	: m_dest(dest)
	, m_start(start)
	, m_weight(weight){}
	int m_weight;
	int m_dest;
	int m_start;
};

class Graph
{
public:
	void AddEdge(int u, int v, int weight = 1);
	void BreadFirstSearch(std::vector<int>& ret) const;
	void DepthFirstSearch(std::vector<int>& ret) const;
	void DepthFirstSearchIterative(std::vector<int>& ret) const;
	void TopologicalSort(std::vector<int>& ret) const;
	void MST_Kruscal(std::vector<Edge>& ret) const;
	void MST_Prim(std::vector<int>& ret) const;
	bool HasCycleDFS() const; 
	bool HasCycleUnionFind() const;
private:
	void TopologicalSortHelper(int u, std::stack<int>& ret, std::vector<bool>& visited) const;
	void DFSHelper(int u, std::vector<int>& ret, std::vector<bool>& visited) const;
	bool HasCycleDFSHelper(int u, vector<bool>& visited) const;
	map<int, vector<Edge> > m_data;
};

void Graph::DepthFirstSearchIterative(std::vector<int>& ret) const
{
	if (m_data.empty()) { return; }
	std::vector<bool> visited(m_data.size(), false);
	std::stack<int> s;
	s.push(m_data.begin()->first);
	while (!s.empty())
	{
		int v = s.top(); s.pop();
		ret.push_back(v);
		cout << "visit: " << v << endl;
		visited[v] = true;
		const vector<Edge>& edges = m_data.find(v)->second;
		for (int i  =0; i < edges.size(); i++)
		{
			if (!visited[edges[i].m_dest])
			{
				s.push(edges[i].m_dest);
			}
		}
	}
}

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

bool EdgeLess(const Edge& a, const Edge& b)
{
	return a.m_weight < b.m_weight;
}

void Graph::MST_Kruscal(std::vector<Edge>& ret) const
{
	map<int, vector<Edge> >::const_iterator it = m_data.begin();
	vector<Edge> all_edges;
	while (it != m_data.end())
	{
		all_edges.insert(all_edges.end(), it->second.begin(), it->second.end());
		++it;
	}

	std::sort(all_edges.begin(), all_edges.end(), EdgeLess);
	UF unionfind(m_data.size());
	int idx = 0;
	int edge_idx = 0;
	// n - 1 edges
	while (idx < m_data.size() - 1 && edge_idx < all_edges.size())
	{
		const Edge& pick = all_edges[edge_idx++];
		int roota = unionfind.Find(pick.m_start);
		int rootb = unionfind.Find(pick.m_dest);
		if (roota != rootb)
		{
			ret.push_back(pick);
			unionfind.Union(roota, rootb);
		}
	}

	if (idx < m_data.size() - 1) { cout << "Doesn't exist!" << endl; }
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
	m_data[u].push_back(Edge(u, v, weight));
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
	DFSHelper(m_data.begin()->first, ret, visited);
}

class Solution
{
public:
	string longestPalindrome(const string& s)
	{
		string ret;
		for (int i = 1; i < 2 * s.size() + 1; i++)
		{
			std::string str = expandPalindrome(s, (i - 1) / 2, i / 2);
			if (str.size() > ret.size()) { ret = str; }
		}
		return ret;
	}

	std::string expandPalindrome(const std::string& s, int left, int right)
	{
		while (left >= 0 && right < s.size() && s[left] == s[right])
		{
			left--; right++;
		}
		return s.substr(left + 1, right - left - 1);
	}

	int lengthOfLongestSubstring(string s)
	{
		map<char, int> hash;
		int cur = 0;
		int begin = 0;
		int max = 0;
		while (cur < s.size())
		{
			map<char, int>::iterator it = hash.find(s[cur]);
			if (it != hash.end()) 
			{
				int pos = it->second;
				max = cur - begin > max ? cur - begin : max;
				begin = begin < pos + 1 ? pos + 1 : begin;
			}

			hash[s[cur]] = cur;
			cur++;
		}
		return max > cur - begin ? max : cur - begin;
	}

	vector<int> twoSum(const vector<int>& nums, int target)
	{
		std::map<int, int> hash;
		std::vector<int> ret;
		for (int i = 0; i < nums.size(); i++)
		{
			if (hash.find(target - nums[i]) == hash.end())
			{
				hash[nums[i]] = i;
			}
			else
			{
				ret.push_back(i);
				ret.push_back(hash[target - nums[i]]);
			}
		}
		return ret;
	}

	// 1. empty case
	// 2. skip all white spaces
	// 3. sign
	// 4. overflow
	int atoi(const std::string& str)
	{
		// empty
		if (str.empty()) { return 0; }

		// whitespaces
		int i = 0;
		while (i < str.size() && isspace(str[i])) { i++; }

		// sign
		bool positive = true;
		if (i < str.size() && str[i] == '-') { positive = false; i++; }
		else if (i < str.size() && str[i] == '+') { i++; }

		// overflow
		int ret = 0;
		while (i < str.size() && str[i] <= '9' && str[i] >= '0')
		{
			if (INT_MAX / 10 < ret || (INT_MAX / 10 == ret && INT_MAX % 10 < str[i] - '0'))
			{
				return positive ? INT_MAX : INT_MIN;
			}
			ret = ret * 10 + str[i] - '0';
			cout << "ret: " << ret << endl;
			i++;
		}

		return positive ? ret : -ret;
	}
};

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

	std::vector<int> dfsret;
	g.DepthFirstSearch(dfsret);
	for (int i = 0; i <dfsret.size(); i++)
	{
		cout << dfsret[i] << " ";
	}
	cout <<endl;
	dfsret.clear();
	g.DepthFirstSearchIterative(dfsret);
	for (int i = 0; i <dfsret.size(); i++)
	{
		cout << dfsret[i] << " ";
	}
	cout <<endl;

	Solution s;
	cout << s.longestPalindrome("abbc") << endl;
	cout << s.longestPalindrome("abbbaabbbc") << endl;
	cout << s.longestPalindrome("abcddcbaaaaaaaaaaaa") << endl;

	cout << s.lengthOfLongestSubstring("abcdeffffffff") << endl;

	cout << s.atoi("       +1234456") << endl;
	return 0;
}