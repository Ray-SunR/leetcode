#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(vector<int>& data, int low, int high)
{
	int pivot = low + (high - low) / 2;
	int target = data[pivot];
	while (low <= high)
	{
		while (low <= high && data[low] < data[pivot]) { low++; }
		if (low <= high)
		{
			swap(data[low], data[pivot]);
			pivot = low++;
		}

		while (low <= high && data[high] > data[pivot]) { high--; }
		if (low <= high)
		{
			swap(data[high], data[pivot]);
			pivot = high--;
		}
	}
	data[pivot] = target;
	return pivot;
}

void qsorthelper(vector<int>& data, int low, int high)
{
	if (low >= high) { return; }
	int pivot = partition(data, low, high);
	qsorthelper(data, low, pivot - 1);
	qsorthelper(data, pivot + 1, high);
}

void qsort(vector<int>& data)
{
	qsorthelper(data, 0, data.size() - 1);
}

void merge(vector<int>& data, vector<int>& axii, int low, int mid, int high)
{
	for (int i = low; i <= high; i++)
	{
		axii[i] = data[i];
	}
	int i = low;
	int j = mid + 1;
	int k = i;
	while (k <= high)
	{
		if (i > mid) { data[k++] = axii[j++]; }
		else if (j > high) { data[k++] = axii[i++]; }
		else if (axii[i] < axii[j]) { data[k++] = axii[i++]; }
		else { data[k++] = axii[j++]; }
	}
}

void mergesorthelper(vector<int>& data, vector<int>& axii, int low, int high)
{
	if (low >= high) { return; }
	int mid = low + (high - low) / 2;
	mergesorthelper(data, axii, low, mid);
	mergesorthelper(data, axii, mid + 1, high);
	merge(data, axii, low, mid, high);
}

void mergesort(vector<int>& data)
{
	vector<int> axii = data;
	mergesorthelper(data, axii, 0, data.size() - 1);
}

void sink(vector<int>& data, int pos, int size)
{
	while (2 * pos + 1 < size)
	{
		int idx = 2 * pos + 1;
		if (idx + 1 < size && data[idx + 1] > data[idx]) { idx++; }
		if (data[pos] < data[idx])
		{
			swap(data[pos], data[idx]);
			pos = idx;
		}
		else
		{
			break;
		}
	}
}

void heapsort(vector<int>& data)
{
	// heaptify
	for (int i = (data.size() - 2) * data.size() /2; i >= 0; i--)
	{
		sink(data, i, data.size());
	}

	int n = data.size();
	while (n)
	{
		swap(data[0], data[n - 1]);
		sink(data, 0, --n);
	}
}

int main(void)
{
	int data[] = {10, 9, 9, 8, 7, 6, 5, 2, 2, 2, 4, 3, 2, 2, 2, 1};
	vector<int> vec(data, data + sizeof(data) / sizeof(data[0]));
	heapsort(vec);

	for (int i = 0; i < vec.size(); i++) { cout << vec[i] << " "; }
		cout <<endl;
	return 0;
}

