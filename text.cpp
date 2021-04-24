#include<iostream>
#define TEST1(X,Y) X+Y
#define TEST2(X) #X
#define TEST3(X,Y) X##Y
#define TEST4(X,Y) (X+Y)
using namespace std;

int main()
{
	string s = "XXX";
	int i = 1 - TEST4(1, 2)*TEST1(5, 6) * 2;
	cout << i << endl;
	system("pause");
	return 0;
}