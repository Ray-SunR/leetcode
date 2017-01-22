// Generate all permutations of a given string

#include <iostream>
#include <vector>

using namespace std;

vector<string> Permutations(const string& str)
{
	vector<string> ret;
	if (str.size() == 1) { ret.push_back(str); return ret; }
	vector<string> others = Permutations(str.substr(1));
	char first = str[0];
	for (int i = 0;i < others.size(); i++)
	{
		const string& target = others[i];
		for (int j = 0;j < target.size() + 1; j++)
		{
			string toadd = target;
			toadd.insert(j, 1, first);
			ret.push_back(toadd);
		}
	}
	return ret;
}

int main(void)
{
	string str = "abc";

	vector<string> ret = Permutations(str);
	cout << "size: " << ret.size() << endl;
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << endl;
	}
	return 0;
}