#include <vector>
#include <iostream>

using namespace std;

// By default it's a max pq
class PQ
{
public:
	PQ(bool max = true): m_size(0), m_max_pq(max) 
	{}

	void push(int val)
	{
		m_data.push_back(val);
		++m_size;
		swim(m_size - 1);
	}

	int pop()
	{
		if (m_size == 0) { return INT_MIN; }
		int ret = m_data[0];
		swap(m_data[0], m_data[m_size - 1]);
		sink(0, --m_size);
		if (m_size <= m_data.size() / 4)
		{
			m_data.resize(m_size);
		}
		return ret;
	}

	bool empty() const
	{
		return m_size == 0;
	}
private:

	void swim(int pos)
	{
		while (pos > 0 && ((m_max_pq && m_data[(pos - 1) / 2] < m_data[pos]) || (!m_max_pq && m_data[(pos - 1) / 2] > m_data[pos])))
		{
			swap(m_data[(pos - 1) / 2], m_data[pos]);
			pos = (pos - 1) / 2;
		}
	}

	void sink(int pos, int n)
	{
		while (2 * pos + 1 < n)
		{
			int i = 2 * pos + 1;
			if (m_max_pq)
			{
				if (i + 1 < n && m_data[i + 1] > m_data[i]) { i++; }
				if (m_data[pos] < m_data[i])
				{
					swap(m_data[pos], m_data[i]);
					pos = i;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (i + 1 < n && m_data[i + 1] < m_data[i]) { i++; }
				if (m_data[pos] > m_data[i])
				{
					swap(m_data[pos], m_data[i]);
					pos = i;
				}
				else
				{
					break;
				}
			}
		}
	}

	void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	bool m_max_pq;
	int m_size;
	vector<int> m_data;
};