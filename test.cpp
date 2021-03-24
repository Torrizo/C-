#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
void add()
{
	int v,f,g,h,l;
	int n = 0;
	cin >> n;
	vector<int> a;
	list<int> num;
	for (int i = 0; i < n; i++)
	{
		int s = 0;
		cin >> s;
		num.push_back(s);
	}
	for (int i = 0; i < n - 1; i++)
	{
		char s;
		cin >> s;
		a.push_back(s);
	}
	sort(num.begin(), num.end());
	for (int i = 0; i < n - 1; i++)
	{
		int j = 0;
		if (a.at(i) == '*')
		{
			//v = num.at[j] * num.at[j + 1];
			f = num.front;
			num.pop_front;
			f = f*num.front;
			num.pop_front;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		int f = 0;
		int j = 0;
		if (a.at(i) == '+')
		{
			//v = num.at[j] * num.at[j + 1];
			g = num.front;
			num.pop_front;
			g = g+num.front;
			num.pop_front;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		int j = 0;
		if (a.at(i) == '-')
		{
			//v = num.at[j] * num.at[j + 1];
			h = num.front;
			num.pop_front;
			h= h - num.front;
			num.pop_front;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		int j = 0;
		if (a.at(i) == '%')
		{
			//v = num.at[j] * num.at[j + 1];
			l = num.front;
			num.pop_front;
			l = l % num.front;
			num.pop_front;
		}
	}
	v = l + g + h + f;
	cout << v << endl;
	
}



int main()
{
	system("pause");
	return 0;
}