#include<stdio.h>
struct act
{
	int begin;
	int end;
}Arr[1000];
int n;//�ܵĻ��
int sum = 0;//���ɲμӵĻ��
void search();
void selection_sort();

int main()
{
	scanf("%d\n", &n);//n��
	for (int i = 0; i<n; i++)
		scanf("%d%d", &Arr[i].begin, &Arr[i].end);//ÿ������ֹʱ��
	selection_sort();//�Ի������ʱ����絽������
	search();//Ѱ�����Ļ����
	printf("%d\n", sum);
	return 0;
}
void search()//̰���㷨
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
void selection_sort()//ѡ������(����)
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
