#include<vector>
#include<list>
#include<iostream>
#include<algorithm>
////using namespace std;
//////int XOR(const vector<int>& v, int i, int j)
//////{
//////	int res = v[i];
//////	for (int k = i + 1; k <= j; k++)
//////	{
//////		res ^= v[k];
//////	}
//////	return res;
//////}
//////int main()
//////{
//////	int n, k;
//////	cin >> n >> k;
//////	vector<int> v;
//////	for (int i = 0; i < n; i++)
//////	{
//////		int num;
//////		cin >> num;
//////		v.push_back(num);
//////	}
//////	int res INT_MIN;
//////	for (int i = 0; i < n; i++)
//////	{
//////		for (int j = i; j < n&&j < i + k; j++)
//////		{
//////			res = max(res, XOR(v, i, j));
//////		}
//////	}
//////	cout << res << endl;
//////	system("pause");
//////	return 0;
//////}
////int fun()
////{
////	unsigned int n, k;
////	cin >> n >> k;
////	vector<int> v;
////	for (int i = 0; i < n; i++)
////	{
////		int num;
////		cin >> num;
////		v.push_back(num);
////	}
////	int count = 0;
////	int res = 0;
////	sort(v.begin(), v.end());
////	int i = v.size() - 1;
////	for (; i >= 0; i--)
////	{
////		if (v[i] > 0)
////		{
////			res += v[i];
////			count++;
////		}
////		else
////		{
////			while (i >= 3)
////			{
////				if (v[i] + v[i - 1] + v[i - 2] >=k)
////				{
////					count += 3;
////					res += v[i] + v[i - 1] + v[i - 2];
////					i -= 3;
////				}
////				else
////				{
////					break;
////				}
////			}
////			break;
////		}
////	}
////	res += count / 3 * k;
////	cout << res << endl;
////	return 0;
////	
////
////	
////	
////}
////
////
////int main()
////{
////	fun();
////	system("pause");
////	return 0;
////}
//
//#include<vector>
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//bool myfunction(int i, int j)
//{
//	return (i > j);
//}
//void fun()
//{
//	int n, k;
//	cin >> n >> k;
//	vector<int> vct;
//	int sum = 0;
//	int count = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		int tmp;
//		cin >> tmp;
//		if (tmp > 0)
//		{
//			sum += tmp;
//			if (count % 3 == 0)
//			{
//				sum += k;
//			}
//			else
//			{
//				vct.push_back(tmp);
//			}
//		}
//		sort(vct.begin(), vct.end(),myfunction);
//		int s = 0;
//		for (auto& v : vct)
//		{
//			count++;
//			s += v;
//			if (count % 3 == 0)
//			{
//				s += k;
//				if (s > 0)
//				{
//					sum += s;
//					s = 0;
//				}
//				else
//				{
//					break;
//				}
//			}
//		}
//	}
//	cout << sum << endl;
//}
//int main()
//{
//	fun();
//	system("pause");
//	return 0;
//}
#include<iostream>

class B
{
public:
	int func()
	{
		cout << " " << endl;
	}
};

class A : public B
{
public:
	virtual void fun()
	{
		cout << " " << endl;
	}
};