#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	//int n = 1;
	//int m = 2;
	//switch (n)
	//{
	//case 1:
	//	m++;//m=3
	//case 2:
	//	n++;//n=2
	//case 3:
	//	switch (n)
	//	{
	//	case 1:
	//		n++;
	//	case 2://m=3,n=2
	//		m++;//m=4
	//		n++;//n=3
	//		break;
	//	}
	//case 4:
	//	m++;//m=5
	//	break;
	//default:
	//	break;
	//}
	//printf("m = %d,n = %d\n", m, n);
	//int i = 1;
	//while (i <= 10)
	//{
	//	if (i == 5)
	//		break;
	//	printf("%d", i);
	//	i = i + 1;
	//}
	//int i = 1;
	//while (i <= 10)
	//{
	//	i = i + 1;
	//	if (i == 5)
	//		continue;
	//	printf("%d", i);
	//}

	int n = 0;
	scanf("%d", &n);
	int i = 0;
	long long int ret = 1;
	for (i = 1; i <= n; ++i)
	{
		ret = ret * i;
	}
	printf("%d", ret);

	system("pause");
	return 0;
}