/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles 
- The Rules.

The Sudoku board could be partially filled, where empty cells 
are filled with the character '.'.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> >& board) {
		std::vector<std::map<char, bool> > rowhash(9); // 9
		std::vector<std::map<char, bool> > colhash(9); // 9
		std::vector<std::map<char, bool> > grouphash(9); // 9
		for (int i = 0;i < board.size(); i++)
		{
			for (int j = 0;j < board[i].size(); j++)
			{
				if (board[i][j] == '.') { continue; }
				int groupno = (i / 3) * 3 + (j / 3);
				if (grouphash[groupno].find(board[i][j]) != grouphash[groupno].end())
				{
					return false;
				}
				else
				{
					grouphash[groupno][board[i][j]] = true;
				}

				if (rowhash[i].find(board[i][j]) != rowhash[i].end())
				{
					return false;
				}
				else
				{
					rowhash[i][board[i][j]] = true;
				}

				if (colhash[j].find(board[i][j]) != colhash[j].end())
				{
					return false;
				}
				else
				{
					colhash[j][board[i][j]] = true;
				}
			}
		}
		return true;
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
	cout << s.isValidSudoku(board) << endl;
	return 0;
}