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

	int f0 = 0;//ǰһ��
	int f1 = 1;//��һ��
	int f = 0;//��¼���ߺ�

	int left = 0;//��¼��߲�ֵ
	int right = 0;//��¼�ұ߲�ֵ

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
	return min(left, right);//�������Ҳ�ֵ��С���Ǹ�
}
int main()
{
	min_step_tofib();
	system("pause");
	return 0;

}