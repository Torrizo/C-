//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//
//int knapsack(int n, int time, vector<int> &v, vector<int> &vc, vector<vector<int>> &res){
//	for (int i = 1; i <= n; i++){//i����Ʒ 
//		for (int j = 1; j <= time; j++){//��������Ϊj 
//			if (v[i] > j){//��ǰ���������� j �Ų��µ� i ����Ʒʱ
//				res[i][j] = res[i - 1][j];
//			}
//			else
//			{
//				res[i][j] = max(res[i - 1][j - v[i]] + vc[i], res[i - 1][j]);
//			}
//		}
//	}
//
//	return res[n][time];
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> v;
//	for (int i = 0; i < n; i++)
//	{
//		int x = 0;
//		cin >> x;
//		v.push_back(x);
//	}
//	vector<int> vc;
//	for (int i = 0; i < n; i++)
//	{
//		int x = 0;
//		cin >> x;
//		vc.push_back(x);
//	}
//	int time;
//	cin >> time;
//	vector<vector<int>> res(n+1, vector<int>(time + 1), 0);
//	knapsack(n, time, v, vc, res);
//	cout << res[n][time] << endl;
//	system("pause");
//	return 0;
//}