////#include<bit/stdc++.h>
//#include<iostream>
//#include<unordered_map>
//#include<vector>
//
//using namespace std;
//int main()
//{
//	int n ,m;
//	cin >> n >> m;
//	vector<pair<int, int>> v;
//	for (int i = 1; i <= n; i++)
//	{
//		int num;
//		cin >> num;
//		v.push_back(make_pair(num, i));
//	}
//	unordered_map<int, pair<int, int>> mp;
//	for (auto item : v)
//	{
//		if (mp.find(item.first) == mp.end())
//		{
//			mp[item.first] = make_pair(item.second, item.second);
//		}
//		else
//		{
//			if (mp[item.first].first > item.second)
//			{
//				mp[item.first].first = item.second;
//			}
//			else if (mp[item.first].second<item.second)
//			{
//				mp[item.first].second = item.second;
//			}
//		}
//	}
//	for (int i = 0; i < m; i++)
//	{
//		int x;
//		cin >> x;
//		if (mp.find(x) != mp.end())
//		{
//			cout << mp[x].first << " " << mp[x].second << endl;
//		}
//	}
//	return 0;
//}