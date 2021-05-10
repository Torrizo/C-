#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <list>
using namespace std;


//int main() {
//
//	int t;
//	cin >> t;
//	for (int i = 0; i < t; ++i) {
//		int n, m;
//		cin >> n >> m;
//		vector<vector<int> > parter;
//		vector<vector<int> > com;
//		class Compare {
//		public:
//			bool operator()(vector<int> &a, vector<int> &b) {
//				return a[0] > b[0];
//			}
//		};
//		sort(parter.begin(), parter.end(), Compare());
//		sort(com.begin(), com.end(), Compare());
//		for (int j = 0; j < n; ++j) {
//			int x;
//			cin >> x;
//			parter.push_back({ x, j + 1 });
//		}
//		for (int j = 0; j < m; ++j) {
//			int x;
//			cin >> x;
//			com.push_back({ x, j + 1 });
//		}
//		sort(parter.begin(), parter.end(), [](vector<int>& a, vector<int>& b) {
//			return a[0] > b[0];
//		});
//		sort(com.begin(), com.end(), [](vector<int>& a, vector<int>& b) {
//			return a[0] > b[0];
//		});
//		for (int i = 0, j = 0; i < parter.size(); ++i) {
//
//			if (com[j][0] >= parter[i][0]) {
//				parter[i][0] = com[j++][1];
//			}
//			else{
//				parter[i][0] = -1;
//			}
//		}
//		sort(parter.begin(), parter.end(), [](vector<int>& a, vector<int>& b) {
//			return a[1] < b[1];
//		});
//		for (vector<vector<int>>::iterator it = parter.begin(); it != parter.end(); ++it) {
//			cout << (*it)[0] << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}
//int getAllSubstrings(string str)
//{
//	vector<string> v;
//	if (str.length() == 0)
//	{
//		return;
//	}
//	else
//	{
//		for (int i = 0; i < str.length(); i++)
//		{
//			for (int j = 1; j < str.length() - i + 1; j++)
//			{
//				//std::cout << str.substr(i, j) << std::endl;
//				v.push_back(str.substr(i, j));
//			}
//		}
//	}
//	return v;
//}

int main()
{
	int r = 0;
	//char *p;
	int n;
	int k;
	//int num = 0;
	//int i;
	cin >> n >> k;
	vector<int> vec;
	//vector<int> w;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	} //插入
	for (int i = 0; i < n; i++)
	{
		string s;
		for (int j = 1; j <= vec[i]; j++)
		{
			if (vec[i] % j == 0)
			{
				//w.push_back(v);
				s.push_back(j);
			}
		}//求正整数因子
		//char t = s.c_str();
		char t = {};
		strcpy(&t,s.c_str);
		char* p = &t;
		int num = 0;
		while (*p != 0)
		{
			num = num * 10 + *p - '0';
			p++;
		} //将所有正整数因子合并成一个数
		string std;
		std.push_back(num);
		set <int> st;
		for (int i = 0; i < std.length(); i++)
		{
			for (int j = 1; j < std.length() - i + 1; j++)
			{
				//std::cout << str.substr(i, j) << std::endl;
				for (int i = 0; i < std.size(); i++);
				{
					int s = 0;
	     			int a = std[s];
					st.insert(a);
				}
			}
		}
		set<int>::iterator it = st.find(k);
		r++;
	}
	cout << r << endl;
	system("pause");
	return 0;
}