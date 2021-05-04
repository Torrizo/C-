#include<iostream>
#include<vector>
using namespace std;
int test(int v, int* a,int n)
{
	if (v > a[n - 1])
	{
		return n + 1;
	}
	int left = 0;
	int right = n - 1;
	int mid = (left + right) / 2;
	while (left < right)
	{
		if (a[mid] >= v)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
		mid = left + (right - left) / 2;
	}
	return mid + 1;
}
int main()
{
	vector<int> v;
	return 0;
}