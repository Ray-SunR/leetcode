#include <vector>

using namespace std;

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