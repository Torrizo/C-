#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//struct Time_S_E//结构体
//{
//	int begin;//开始时间
//	int end;
//	
//};
//void bubbleSort(struct Time_S_E arr[], int len)  //函数冒泡排序
//{
//	int i, j;
//	struct Time_S_E temp;
//
//	for (j = 0; j<len; ++j)
//	{
//		for (i = 0; i<len; ++i)
//		{
//			if (arr[i].end > arr[i + 1].end)
//			{
//				temp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = temp;
//			}
//		}
//	}
//}
	

//int main()
//{
//	struct Time_S_E time[1000], temp;
//	int i = 0, j = 0, count = 1;
//	int n;
//	printf("Please input the meetting's numbers in total: \n");
//	scanf("%d", &n);
//	printf("Please input the begin time and end time: \n");
//	//input datas
//	for (i = 0; i<n; ++i)
//		scanf("%d %d", &time[i].begin, &time[i].end);
//	//Sort the right endpoint
//	bubbleSort(time, n);
//	//output results
//	printf("The 1 is on the calender\n");
//	for (i = 0; i<n; ++i)
//	{
//		if (time[i].end < time[i + 1].begin)
//			count++;
//	}
//	
//	printf("%d\n", count);
//	system("pause");
//	return 0;
//}

//
//int main()
//{
//
//
//	char c[10] = { 'I', ' ', 'a', 'm', ' ', 's', 'm', 'a', 'r', 't' };
//	int a = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		if (c[i] == 'm')
//		{
//			a++;
//		}
//	}
//	printf("%d\n", a);
//	if (a = 0)
//	{
//		printf("没找到\n");
//	}
//	
//	system("pause");
//	return 0;
//
//}