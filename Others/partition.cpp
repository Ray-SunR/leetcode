// Partition an array of numbers for supporting quick sort

#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& v, int left, int right)
{
	int pivot = left + (right - left) / 2;
	int save = v[pivot];
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (i <= j && v[i] < save) { i++; }
		if (i <= j)
		{
			v[pivot] = v[i];
			pivot = i++;
		}
		while (i <= j && v[j] > save) { j--; }
		if (i <= j)
		{
			v[pivot] = v[j];
			pivot = j--;
		}
	}

	v[pivot] = save;
	return pivot;
}

void qsort(vector<int>& v, int left, int right)
{
	int pivot = Partition(v, left, right);
	cout << "pivot: " << pivot << " a[pivot]: " << v[pivot] << endl;
	if (pivot < right)
	{
		qsort(v, pivot + 1, right);
	}

	if (pivot > left)
	{
		qsort(v, left, pivot - 1);
	}
}

int main(void)
{
	int a[] = {4,3,2,1};
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
	qsort(v, 0, v.size() - 1);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}