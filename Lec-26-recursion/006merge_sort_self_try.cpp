#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sorting(vector<int> &arr, int start, int mid, int end)
{
	vector<int> c;
	int i = start;
	int j = mid + 1;

	while (i <= mid and j <= end)
	{
		if (arr[i] <= arr[j])
		{
			c.push_back(arr[i]);
			i++;
		}
		else
		{
			c.push_back(arr[j]);
			j++;
		}
	}
	while (i <= mid)
	{
		c.push_back(arr[i]);
		i++;
	}
	while (j <= end)
	{
		c.push_back(arr[j]);
		j++;
	}

	// now copy vector c in arr
	int k = 0;
	for (int i = start; i <= end; i++)
	{
		arr[i] = c[k++];
	}
}

void fxn(vector<int> &arr, int start, int end)
{
	// base case
	if (start >= end)
	{
		return;
	}

	// reccurence relation
	int mid = start + (end - start) / 2;
	fxn(arr, start, mid);
	fxn(arr, mid + 1, end);

	sorting(arr, start, mid, end);
}

int main()
{
	vector<int> arr = {50, 40, 30, 20, 10};
	vector<int> arr1 = {5, 10, 15, 20, 7, 11, 13};
	fxn(arr1, 0, arr1.size() - 1);

	// sorting(arr1 , 0 , 3 , 6) ;
	for (int i = 0; i < arr1.size(); ++i)
	{
		cout << arr1[i] << " ";
	}

	return 0;
}
