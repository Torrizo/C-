#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define Num_Dev 3   // ÿ������������豸����������
#define Max 10      //�����ɵ����Ľ�������


int Max_Need_Dev[Max][Num_Dev];    //���н�������Ҫ���豸�������Ŀ
int Allocation_Dev[Max][Num_Dev];      //���н����Ѿ����䵽���豸����Ŀ
int Need_Dev[Max][Num_Dev];        //���н��̻���Ҫ���豸����Ŀ

int current_Available_Dev[Max][Num_Dev];    //��¼������֮�󣬴�ʱϵͳ�Ŀ�����Դ��Ŀ����Ϊ����������ȫ���У���ô�ж��ٸ����̾ͻ�������ٴ������ĵ�ǰ�����Ŀ�����Դ��Ŀ��
int current_recycle_Dev[Max][Num_Dev];          //��¼������֮��ϵͳ�и����豸����Ŀ

int system_Dev[Num_Dev];                //ϵͳ����ӵ�еĸ����豸������
int Available_Dev[Num_Dev];           //ϵͳ��ʣ�����Դ����
int finish[Max];                   //�������н����Ƿ��Ѿ�������ϡ�


int quene[Max];                     //���費�������������ô���ڴ�Ű�ȫ���С� ����¼ÿ�����̵��±�

int num;           // ���̵����� 


void init(){
	printf("������ϵͳ�и�����Դ����Ŀ�ܺͣ�\n");
	for (int i = 0; i < Num_Dev; i++)
	{
		scanf("%d", &system_Dev[i]);
		Available_Dev[i] = system_Dev[i];
		printf("%d\t", Available_Dev[i]);
	}

	printf("\n");

	printf("��������̵�������\n");
	scanf("%d", &num);
	printf("\n");

	printf("���������������������Ҫȫ���豸��������\n");
	for (int i = 0; i < num; i++){
		for (int j = 0; j < Num_Dev; j++)
		{
			scanf("%d", &Max_Need_Dev[i][j]);
		}
	}
	printf("\n");

	printf("��������������Ѿ����䵽���豸����Ŀ��\n");
	for (int i = 0; i < num; i++){
		for (int j = 0; j < Num_Dev; j++)
		{
			scanf("%d", &Allocation_Dev[i][j]);
			Available_Dev[j] = Available_Dev[j] - Allocation_Dev[i][j];       //����ϵͳ��ʣ���豸����Ŀ
		}
	}

	printf("\n");
	for (int i = 0; i < num; i++){
		for (int j = 0; j < Num_Dev; j++)
		{
			Need_Dev[i][j] = Max_Need_Dev[i][j] - Allocation_Dev[i][j];     //�������������Ȼ����Ҫ�ĸ����豸����Ŀ                                                                 
		}
	}
	for (int i = 0; i < num; i++)
	{
		finish[i] = 0;
		quene[i] = -1;
	}

}
void print(){
	printf("����ID\t|\tMax\t|\tAllocat\t|\tNeed\t|\tAvail\t|\t\tfinish\n");
	for (int i = 0; i < num; i++)
	{
		printf("%d\t|\t", i);
		printf("%d,%d%,%d\t|\t%d,%d%,%d\t|\t%d,%d%,%d\t|\t%d,%d%,%d  (%d,%d,%d)\t|\t%d\\", Max_Need_Dev[i][0], Max_Need_Dev[i][1], Max_Need_Dev[i][2], Allocation_Dev[i][0], Allocation_Dev[i][1], Allocation_Dev[i][2], Need_Dev[i][0], Need_Dev[i][1], Need_Dev[i][2], current_Available_Dev[i][0], current_Available_Dev[i][1], current_Available_Dev[i][2], current_recycle_Dev[i][0], current_recycle_Dev[i][1], current_recycle_Dev[i][2], finish[i]);
		printf("\n");
	}
}

int conpare(int *p){            //�жϵ�ǰ�����豸����Ŀ�Ƿ��������������Ľ��̵�Ҫ��
	for (int j = 0; j < Num_Dev; j++){
		if (*(p + j) > Available_Dev[j]){
			return 0;
		}
	}
	return 1;
}

void recycle(int *p){           //��һ������������ϣ������Ѿ�����������豸
	for (int i = 0; i < Num_Dev; i++)
	{
		Available_Dev[i] += *(p + i);
	}
}

int allocation(){
	int flag = 0;
	int count = 1;              //�ж����������Ǳ���һ��֮��û�н��̿������С�
	int i = 0;                  //�ж�����һ������
	int index = 0;              //���ڼ�¼��ȫ���е��±�
	int max_times = 0;              //��Ϊ��num�������� ���Լ����а�ȫ���У�������Ѱ��num��ƽ����
	while (1)
	{
		max_times++;
		if (conpare(Need_Dev[i]) == 1 && finish[i] == 0){
			count = 0;
			finish[i] = 1;              //��ʾ�ý��̻����Դ���������
			for (int j = 0; j < Num_Dev; j++)       // �ý��̻�ȡʣ���豸  ��   
			{
				//     Allocation_Dev[i][j] += Need_Dev[i][j];         //1.�ý����Ѿ�������豸��Ŀ��������Ȼ��Ҫ�� 
				Available_Dev[j] -= Need_Dev[i][j];             //2.ϵͳ��Ŀǰ���õ��豸��Ŀ��ȥ������Ҫ��

				current_Available_Dev[i][j] = Available_Dev[j];   //��¼������֮�󣬴�ʱϵͳ�Ŀ�����Դ��Ŀ����Ϊ����������ȫ���У���ô�ж��ٸ����̾ͻ�������ٴ������ĵ�ǰ�����Ŀ�����Դ��Ŀ��
			}

			recycle(Max_Need_Dev[i]);                    // ������Դ
			for (int j = 0; j < Num_Dev; j++)
			{
				current_recycle_Dev[i][j] += Available_Dev[j];
			}

			quene[index] = i;
			index++;
			if (index == num){
				flag = 1;
				printf("��ȫ�����Ѿ������ˡ�\n");
				break;
			}
		}
		if (count == num){
			printf("�ᷢ���������ް�ȫ���С�����������\n");
			break;
		}
		if (i == num - 1){
			i = 0;
			continue;
		}
		if (max_times == num*num){
			printf("ȫ�������Ѿ�ִ����ϣ��ް�ȫ���С�\n");
			break;
		}
		count++;
		i++;
	}
	return flag;
}

int main(void){
	init();
	int flag = allocation();
	print();
	if (flag == 1){
		for (int i = 0; i < num; i++)
		{
			printf("%d--->", quene[i]);
		}

	}
	printf("\n");
	system("pause");
}