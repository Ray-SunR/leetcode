/*
Given a string containing just the characters '(' and ')', find the 
length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has
 length = 2.

Another example is ")()())", where the longest valid parentheses substring 
is "()()", which has length = 4.
*/

// ))()(((()))(()
// Thoughts: use a stack of char and int(pos), when having ')', check if the 
// top stack is '(', if so, pop, otherwise, push. when not having '(', push.
// this way, after traversal, all left in the stack fail to be a valid parenthese. 
// Traverse through the stack and calculate biggest gap between indices. 
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<pair<int, char> > stk;
		for (int i = 0;i < s.size(); i++)
		{
			if (s[i] == ')')
			{
				if (!stk.empty() && stk.top().second == '(')
				{
					cout << "pop: " << stk.top().second << endl;
					stk.pop();
				}
				else
				{
					stk.push(pair<int, char>(i, ')'));
					cout << "push: " << stk.top().second << endl;
				}
			}
			else
			{
				stk.push(pair<int, char>(i, '('));
				cout << "push: " << stk.top().second << endl;
			}
		}
		Print(stk);
		if (stk.empty()) { return s.size(); }

		int pretop = stk.top().first; stk.pop();
		int max_length = s.size() - pretop - 1;
		while (!stk.empty())
		{
			int top = stk.top().first; stk.pop();
			max_length = max(max_length, pretop - top - 1);
			pretop = top;
		}
		return max(max_length, pretop);
	}

	int max(int a, int b)
	{
		return a > b ? a : b;
	}

	void Print(stack<pair<int, char> > stk)
	{
		while (!stk.empty())
		{
			cout << "(" << stk.top().first << ", " << stk.top().second << ") ";
			stk.pop();
		}
		cout << endl;
	}
};

int main(void)
{
	Solution s;
	cout << s.longestValidParentheses("))(())((") << endl;
	cout << s.longestValidParentheses("((((())()(((()))(())))))") << endl;
	return 0;
}