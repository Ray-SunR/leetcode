#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int> >& matrix) 
	{
		flipx(matrix);
		flipdiag(matrix);
	}

private:
	void flipx(vector<vector<int> >& matrix)
	{
		if (matrix.empty()) { return; }
		int m = matrix.size(); int n = matrix[0].size();
		for (int col = 0; col < n; col++)
		{
			int start = 0; int end = m - 1;
			while (start < end)
			{
				swap(matrix[start][col], matrix[end][col]);
				start++; end--;
			}
		}
	}

	void swap(int& a, int& b)
	{
		int tmp = b;
		b = a;
		a = tmp;
	}

	void flipdiag(vector<vector<int> >& matrix)
	{	
		if (matrix.empty()) { return; }
		int m = matrix.size(); int n = matrix[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < i; j++)
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};

void Print(const vector<vector<int> >& matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(void)
{
	vector<vector<int> > matrix;
	vector<int> row;
	for (int i = 1; i <= 16; i++)
	{
		row.push_back(i);
		if (i % 4 == 0)
		{
			matrix.push_back(row);
			row.clear();
		}
	}
	Print(matrix);

	Solution s;
	s.rotate(matrix);

	Print(matrix);
	return 0;
}