#include<iostream>
#include<vector>
#include<list>
using namespace std;
int test(int num1, int num2, int num3, int num4)
{
	int a, b, c;
	a = (num1 + num3) / 2;
	b = (num2 + num4) / 2;
	c = (num4 - num2) / 2;
	if ((a - ((num1 + num3) / 2)) != 0)
	{
		cout << "No" << endl;
	}
	else if ((b - ((num2 + num4) / 2)) != 0)
	{
		cout << "No" << endl;
	}
	else if ((c - ((num4 - num2) / 2)) != 0)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "" << a;
		cout << "" << b;
		cout << "" << c;
	}
	
	return 0;
}

//
//int main()
//{
//	int num1, num2, num3, num4;
//	cin >> num1;
//	cin >> num2;
//	cin >> num3;
//	cin >> num4;
//	test(num1,num2,num3,num4);
//	system("pause");
//	return 0;
//}

int main()
{
	string s = "", table = "0123456789ABCDEF";
	int M = 0, N = 0;
	cin >> M >> N;

	if (M == 0)
	{
		s = "0";
	}

	while (M)
	{
		if (M < 0)
		{
			M = -M;
			cout << "-";
		}
		s = table[M % N] + s;
		M /= N;
	}
	cout << s << endl;
	return 0;
}