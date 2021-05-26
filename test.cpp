#include<iostream>
using namespace std;
int test()
{
	double v1, v2, c1, c2, s;
	cin >> v1 >> v2 >> c1 >> c2 >> s;
	double k, b, d ,f;
	f = 8.34;
	k = (c2 - c1) / (v2 - v1);
	b = k*s / f;
	d = (k*v1 - 2 * c1)*s / f - v1*v1;
	cout << "k=" << k << " " << "b=" << b << " " << "d=" << d << " " << endl;
	return k, b, d;
}

int main()
{
	while (1)
	{
		test();
	}
	system("pause");
	return 0;
}