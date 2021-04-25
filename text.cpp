#include<iostream>
#include<vector>
using namespace std;
//int j = 0;
//int fun(int x ,vector<int>&v)
//{
//	int max = v[0];
//	int min = v[0];
//	int m = 0;
//	int n = 0;
//	for (int i = 0; i < x; i++)
//	{
//		if (v[i]>max)
//		{
//			max = v[i];
//			n=i;
//		}
//	}
//	for (int i = 0; i < x; i++)
//	{
//		if (v[i]<min)
//		{
//			min = v[i];
//			m=i;
//		}
//	}
//	//cout << max << endl;
//	if ((max + min) % 2 == 0)
//	{
//		v[m] = (max + min) / 2;
//		v[n] = (max + min) / 2;
//	}
//	else
//	{
//		v[m] = (max + min) / 2;
//		v[n] = (max + min) / 2 + 1;
//	}
//	for (int i = 0; i < x-1; i++)
//	{
//		if (v[i] == v[i + 1])
//		{
//			return fun(x,v);
//			j++;
//			break;
//		}
//		else
//		{
//			cout << j << endl;
//		}
//	}
//}
//
//int main()
//{
//	int x;
//	cin >> x;
//	vector<int>v;
//	for (int i = 0; i < x; i++)
//	{
//		int u;
//		cin >> u;
//		v.push_back(u);
//	}
//	fun(x,v);
//	system("pause");
//	return 0;
//}

class A{
public:
	virtual void fun_1(){}
	virtual void fun_2(){}

};
class B :public A{

};
int main()
{
	cout << sizeof(A) << endl;
	return 0;
}
