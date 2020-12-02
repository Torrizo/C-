#include<stdio.h>
struct act
{
	int begin;
	int end;
}Arr[1000];
int n;//总的活动数
int sum = 0;//最多可参加的活动数
void search();
void selection_sort();

int main()
{
	scanf("%d\n", &n);//n项活动
	for (int i = 0; i<n; i++)
		scanf("%d%d", &Arr[i].begin, &Arr[i].end);//每项活动的起止时间
	selection_sort();//对活动按结束时间从早到晚排序
	search();//寻找最多的活动安排
	printf("%d\n", sum);
	return 0;
}
void search()//贪心算法
{
	sum = 1;
	int temp = Arr[0].end;
	for (int i = 1; i<n; i++)
	{
		if (Arr[i].begin >= temp)
		{
			sum++;
			temp = Arr[i].end;
		}
	}
}
void selection_sort()//选择排序(升序)
{
	int i, j, k;
	struct act temp;
	for (i = 0; i<n; i++)
	{
		k = i;
		for (j = i + 1; j<n; j++)
			if (Arr[j].end<Arr[k].end)    k = j;
		struct act temp = Arr[i];
		Arr[i] = Arr[k];
		Arr[k] = temp;
	}
}
