#include<iostream>
#include<string>
using namespace std;
int min(int num1, int num2)
{
	if (num1 > num2)
	{
		return num2;
	}
	else if (num1 <= num2)
	{
		return num1;
	}
}
int min_step_tofib()
{
	int n;
	cin >> n;

	int f0 = 0;//前一个
	int f1 = 1;//后一个
	int f = 0;//记录二者和

	int left = 0;//记录左边差值
	int right = 0;//记录右边差值

	while (1)
	{
		f = f0 + f1;
		f0 = f1;
		f1 = f;

		if (f < n)
		{
			left = n - f;
		}
		else
		{
			right = f - n;
			break;
		}
	}
	return min(left, right);//返回左右差值较小的那个
}
int main()
{
	min_step_tofib();
	system("pause");
	return 0;

}