#include <iostream>
#include <map>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) { return NULL; }
		map<RandomListNode*, RandomListNode*> hash;
		RandomListNode* pre = NULL;
		RandomListNode* root = head;
		while (head)
		{
			hash[head] = new RandomListNode(head->label);
			if (!pre) { pre = hash[head]; }
			else
			{
				pre->next = hash[head];
				pre = pre->next;
			}

			if (head->random && hash.find(head->random) == hash.end())
			{
				hash[head->random] = new RandomListNode(head->random->label);
			}

			pre->random = head->random ? hash[head->random] : NULL;
			head = head->next;
		}
		return hash[root];
	}
};

void Print(const RandomListNode* root)
{
	while (root)
	{
		cout << " val: " << root->label;
		if (root->random)
		{
			cout << " random: " << root->random->label << endl;
		}
		root = root->next;
		cout << endl;
	}
}

int main(void)
{
	RandomListNode* one = new RandomListNode(1);
	RandomListNode* two = new RandomListNode(2);
	RandomListNode* three = new RandomListNode(3);
	RandomListNode* four = new RandomListNode(4);
	RandomListNode* five = new RandomListNode(5);
	one->next = two;
	one->random = five;

	two->next = three;
	two->random = one;

	three->next = four;
	three->random = four;

	four->next = five;
	four->random = one;

	five->random = two;

	Solution s;
	Print(s.copyRandomList(one));
	return 0;
}