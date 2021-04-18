#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
using namespace std;

void pingpang()
{
	int x;
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		vector<int> a;
		vector<int> b;
		for (int j = 0; j < 6; j++)
		{
			int z = 0;
			int c = 0;
			cin >> z;
			cin >> c;
			a.push_back(z);
			b.push_back(c);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int n = 0;
		int m = 0;
		int u = 0;
		int t = 0;

		//for (int j = 0; j < 3; j++)
		//{
		//	int	q = 0;
		//	int d = 0;
		//    if(b[1] - a[j] - (b[0] - a[j])> 0)
		//	{
		//		q++;
		//	}
		//	else if (b[2] - a[j] - (b[1] - a[j])>0 || b[2] - a[j] - b[0] - a[j]> 0)
		//	{
		//		d++;
		//	}
		//	n = q*d;
		//}
		//for (int j = 0; j < 3; j++)
		//{
		//	int	q = 0;
		//	int d = 0;
		//	if (b[4] - a[j+3] - (b[3] - a[j+3])> 0)
		//	{
		//		q++;
		//	}
		//	else if (b[5] - a[j+3] - (b[4] - a[j+3])>0 || b[5] - a[j+3] - b[3] - a[j+3]> 0)
		//	{
		//		d++;
		//	}
		//	m = q*d;
		//}
		//for (int j = 0; j < 6; j++)
		//{
		//	int p = 0;
		//	for (int k = 0; k < 6; k++)
		//	{
		//		if ((b[j] + b[k]) - (a[k] + a[j]) > 0)
		//		{
		//			p++;
		//		}
		//		u = p;
		//	}
		//}
		//if (n == 0)
		//{
		//	t = u*m;
		//	cout << t << endl;
		//}
		//else if (m == 0)
		//{
		//	t = u*n;
		//	cout << t << endl;
		//}
		//else if (u == 0)
		//{
		//	t = m*n;
		//	cout << t << endl;
		//}
		//else if (n == 0 && m == 0 || n == 0 && u == 0 || m == 0 && u == 0)
		//{
		//	t = 0;
		//	cout << t << endl;
		//}
		//else 
		//{
		//	t = 0;
		//	cout << t << endl;
		//}
	}
}

int main()
{
	pingpang();
	system("pause");
	return 0;
}