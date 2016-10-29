/*
Design and implement a data structure for Least Recently Used (LRU) cache.
 It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the 
key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already 
present. When the cache reached its capacity, it should invalidate 
the least recently used item before inserting a new item.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

// NULL <-> 1 <-> 2 <-> 3 <-> NULL
class LRUCache{
	struct Node;
public:
	LRUCache(int capacity)
	: m_capa(capacity)
	, m_head(NULL)
	, m_tail(NULL) {}

	int get(int key) {
		unordered_map<int, Node*>::iterator it = m_hash.find(key);
		if (it != m_hash.end())
		{
			// move this element to front
			Node* node = it->second;
			MoveNodeToFront(node);
			//cout << "get: (" << key << ", " << node->m_value << ")" << endl;
			//Print();
			return node->m_value;
		}
		else
		{
			return -1; // falut
		}
	}

	void set(int key, int value) {
		unordered_map<int, Node*>::iterator it = m_hash.find(key);
		if (it == m_hash.end())
		{
			Node* node = new Node(key, value);
			// put that into front
			if (m_head) 
			{
				node->m_next = m_head->m_next; 
				m_head->m_next = node; 
				node->m_pre = m_head; 
				m_head = node; 
			}
			else 
			{
				m_head = node;
				m_tail = node; 
			}

			if (m_hash.size() < m_capa)
			{
				m_hash[key] = node; // no need to swap out
			}
			else
			{
				m_hash[key] = node;
				// need to swap out the tail
				Node* del = m_tail;
				m_tail = m_tail->m_next;
				m_tail->m_pre = NULL;
				m_hash.erase(del->m_key);
				delete del;
			}
		}
		else
		{
			it->second->m_value = value;
			MoveNodeToFront(it->second);
		}
		//cout << "set: (" << key << ", " << value << ")" << endl;
		//Print();
	}
private:
	void MoveNodeToFront(Node* node)
	{
		if (node == m_head) { return; }
		Node* next = node->m_next;
		Node* pre = node->m_pre;
		node->m_next = m_head->m_next; // head's next is always null
		if (next) { next->m_pre = pre; }
		if (pre) { pre->m_next = next; }
		else
		{
			// meaning this node is tail node, we should update tail
			m_tail = next;
		}
		// This condition is guranteed to be true, if the lru has a size of 1, then
		// m_head should be the same as node;
		if (m_head) 
		{ 
			m_head->m_next = node; 
			node->m_pre = m_head; 
			m_head = node; 
		}
		else
		{
			m_head = node;
		}
	}

	void Print() const
	{
		Node* tmp = m_tail;
		while (tmp)
		{
			cout << tmp->m_value << " ";
			tmp = tmp->m_next;
		}
		cout << endl;
	}

	struct Node
	{
		int m_value;
		int m_key;
		Node* m_pre;
		Node* m_next;
		Node(int key, int value, Node* pre = NULL, Node* next = NULL)
		: m_key(key)
		, m_value(value)
		, m_pre(pre)
		, m_next(next){}
	};
	int m_capa;
	Node* m_head;
	Node* m_tail;
	unordered_map<int, Node*> m_hash; // key -> node mapping
};


int main(void)
{
	LRUCache cache(5);
	cache.set(1, 1);
	cache.set(2, 2);
	cache.set(2, 2);
	cache.set(2, 2);
	cache.set(2, 2);
	cache.set(1, 7);
	cout << cache.get(1) << endl;
	cache.set(3, 3);
	cout << cache.get(2) << endl;
	cache.set(4, 4);
	cache.set(5, 5);
	cache.set(6, 6);
	cout << cache.get(1) << endl;
	cout << cache.get(3) << endl;
	cout << cache.get(5) << endl;
	return 0;
}