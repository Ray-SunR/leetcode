#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

class UF
{
public:
	UF(int n)
	: m_count(n)
	{
		for (int i = 0; i < n; i++) { m_data.push_back(i); m_size.push_back(0); }
	}

	// number of connected components
	int Count() const
	{
		return m_count;
	}

	void Union(int u, int v)
	{
		int roota = Find(u);
		int rootb = Find(v);
		if (roota == rootb) { return; }
		m_count--;
		if (m_size[roota] < m_size[rootb])
		{
			m_data[roota] = rootb;
			m_size[rootb] += m_size[roota];
		}
		else
		{
			m_data[rootb] = roota;
			m_size[roota] += m_size[rootb];
		}
	}

	bool Connected(int u, int v) const
	{
		return Find(u) == Find(v);
	}

	int Find(int u) const
	{
		while (m_data[u] != u) 
		{ 
			u = m_data[u];
		}
		return u;
	}

private:
	vector<int> m_data;
	vector<int> m_size;
	int m_count;
};

class Solution {
public:
	int numIslands(vector<vector<char> >& grid) 
	{
		map<int, int> hash;
		int num_of_ones = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == '1') 
				{
					hash[j + i * grid[i].size()] = num_of_ones++;
				}
			}
		}
		UF unionfind(num_of_ones);
		for (int i = 0; i < grid.size(); i++)
		{
			int n = grid[i].size();
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] != '1') { continue; }
				int current = hash[j + i * n];
				// left
				if (j - 1 >= 0 && grid[i][j - 1] == '1')
				{
					unionfind.Union(hash[j - 1 + i * n], current);
				}

				// top
				if (i - 1 >= 0 && grid[i - 1][j] == '1')
				{
					unionfind.Union(hash[j + (i - 1) * n], current);
				}

				// right
				if (j + 1 < grid[i].size() && grid[i][j + 1] == '1')
				{
					unionfind.Union(hash[j + 1 + i * n], current);
				}

				// bottom
				if (i + 1 < grid.size() && grid[i + 1][j] == '1')
				{
					unionfind.Union(hash[j + (i + 1) * n], current);
				}
			}
		}
		return unionfind.Count();
	}
};

int main(void)
{
	/*
	11110
	11010
	11000
	00000
	*/
	vector<vector<char> > grid;
	vector<char> temp;
	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');

	grid.push_back(temp); temp.clear();

	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');

	grid.push_back(temp); temp.clear();

	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('1');
	temp.push_back('0');
	temp.push_back('0');

	grid.push_back(temp); temp.clear();

	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('1');
	temp.push_back('1');

	grid.push_back(temp); temp.clear();

	Solution s;
	cout << s.numIslands(grid) << endl;
	return 0;
}