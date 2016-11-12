/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/

// Thoughts: brute-force with backtracing. We try 1-9 for position 
// with '.'. If it's not valid soduku, then take a step back and 
// set the position with '.'. 
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> >& board, int row, int col, char c) 
	{
		for (int i = 0; i < 9; i++)
		{
			if (board[row][i] != '.' && board[row][i] == c) { return false; }
			if (board[i][col] != '.' && board[i][col] == c) { return false; }
		}

		int group = row / 3 * 3 + col / 3;
		int ro = group / 3 * 3;
		int co = group % 3 * 3;
		for (int i = ro; i < ro + 3; i++)
		{
			for (int j = co; j < co + 3; j++)
			{
				if (board[i][j] != '.' && board[i][j] == c) { return false; }
			}
		}
		return true;
	}

	bool solve(vector<vector<char> > & board)
	{
		for (int i = 0;i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (board[i][j] == '.')
				{
					for (char k = '1'; k <= '9'; k++)
					{
						if (isValidSudoku(board, i, j, k))
						{
							board[i][j] = k;
							if (solve(board))
							{
								return true;
							}
							else
							{
								board[i][j] = '.';
							}
						}
					}
					return false;
				}
			}
		}
		return true;
	}

	void solveSudoku(vector<vector<char> >& board) 
	{
		solve(board);
	}
};

void Initialize(vector<vector<char> >& board, const char* data[], int size)
{
	for (int i = 0; i < size; i++)
	{
		vector<char> row;
		int dsize = strlen(data[i]);
		for (int j = 0; j < dsize; j++)
		{
			row.push_back(data[i][j]);
		}
		board.push_back(row);
	}
}

void Print(const vector<vector<char> >& board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void)
{
	const char* data[] = { 
		"..9748...",
		"7........",
		".2.1.9...",
		"..7...24.",
		".64.1.59.",
		".98...3..",
		"...8.3.2.",
		"........6",
		"...2759.."
	};

	vector<vector<char> > board;
	Initialize(board, data, sizeof(data) / sizeof(data[0]));
	Print(board);
	Solution s;
	//cout << s.isValidSudoku(board) << endl;
	s.solveSudoku(board);

	Print(board);
	//cout << s.isValidSudoku(board) << endl;
	return 0;
}