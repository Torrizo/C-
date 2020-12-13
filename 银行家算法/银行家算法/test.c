#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define Num_Dev 3   // 每个进程所需的设备的种类数量
#define Max 10      //可容纳的最多的进程数量


int Max_Need_Dev[Max][Num_Dev];    //所有进程所需要的设备的最大数目
int Allocation_Dev[Max][Num_Dev];      //所有进程已经分配到的设备的数目
int Need_Dev[Max][Num_Dev];        //所有进程还需要的设备的数目

int current_Available_Dev[Max][Num_Dev];    //记录分配完之后，此时系统的可用资源数目（因为假如会产生安全队列，那么有多少个进程就会产生多少次这样的当前分配后的可用资源数目）
int current_recycle_Dev[Max][Num_Dev];          //记录回收完之后，系统中各个设备的数目

int system_Dev[Num_Dev];                //系统中所拥有的各类设备的数量
int Available_Dev[Num_Dev];           //系统中剩余的资源数量
int finish[Max];                   //存存放所有进程是否已经运行完毕。


int quene[Max];                     //假设不会出现死锁，那么用于存放安全队列。 即记录每个进程的下表。

int num;           // 进程的名字 


void init(){
	printf("请输入系统中各类资源的数目总和：\n");
	for (int i = 0; i < Num_Dev; i++)
	{
		scanf("%d", &system_Dev[i]);
		Available_Dev[i] = system_Dev[i];
		printf("%d\t", Available_Dev[i]);
	}

	printf("\n");

	printf("请输入进程的数量：\n");
	scanf("%d", &num);
	printf("\n");

	printf("请输入各个进程运行所需要全部设备的数量：\n");
	for (int i = 0; i < num; i++){
		for (int j = 0; j < Num_Dev; j++)
		{
			scanf("%d", &Max_Need_Dev[i][j]);
		}
	}
	printf("\n");

	printf("请输入各个进程已经分配到的设备的数目：\n");
	for (int i = 0; i < num; i++){
		for (int j = 0; j < Num_Dev; j++)
		{
			scanf("%d", &Allocation_Dev[i][j]);
			Available_Dev[j] = Available_Dev[j] - Allocation_Dev[i][j];       //计算系统中剩余设备的数目
		}
	}

	printf("\n");
	for (int i = 0; i < num; i++){
		for (int j = 0; j < Num_Dev; j++)
		{
			Need_Dev[i][j] = Max_Need_Dev[i][j] - Allocation_Dev[i][j];     //计算各个进程依然所需要的各个设备的数目                                                                 
		}
	}
	for (int i = 0; i < num; i++)
	{
		finish[i] = 0;
		quene[i] = -1;
	}

}
void print(){
	printf("进程ID\t|\tMax\t|\tAllocat\t|\tNeed\t|\tAvail\t|\t\tfinish\n");
	for (int i = 0; i < num; i++)
	{
		printf("%d\t|\t", i);
		printf("%d,%d%,%d\t|\t%d,%d%,%d\t|\t%d,%d%,%d\t|\t%d,%d%,%d  (%d,%d,%d)\t|\t%d\\", Max_Need_Dev[i][0], Max_Need_Dev[i][1], Max_Need_Dev[i][2], Allocation_Dev[i][0], Allocation_Dev[i][1], Allocation_Dev[i][2], Need_Dev[i][0], Need_Dev[i][1], Need_Dev[i][2], current_Available_Dev[i][0], current_Available_Dev[i][1], current_Available_Dev[i][2], current_recycle_Dev[i][0], current_recycle_Dev[i][1], current_recycle_Dev[i][2], finish[i]);
		printf("\n");
	}
}

int conpare(int *p){            //判断当前可用设备的数目是否可以满足所传入的进程的要求
	for (int j = 0; j < Num_Dev; j++){
		if (*(p + j) > Available_Dev[j]){
			return 0;
		}
	}
	return 1;
}

void recycle(int *p){           //若一个进程运行完毕，回收已经分配给它的设备
	for (int i = 0; i < Num_Dev; i++)
	{
		Available_Dev[i] += *(p + i);
	}
}

int allocation(){
	int flag = 0;
	int count = 1;              //判断死锁。就是遍历一遍之后没有进程可以运行。
	int i = 0;                  //判断是哪一个进程
	int index = 0;              //用于记录安全队列的下表
	int max_times = 0;              //因为有num个变量， 所以假如有安全队列，最多就是寻找num的平方次
	while (1)
	{
		max_times++;
		if (conpare(Need_Dev[i]) == 1 && finish[i] == 0){
			count = 0;
			finish[i] = 1;              //表示该进程获得资源后运行完毕
			for (int j = 0; j < Num_Dev; j++)       // 让进程获取剩余设备  即   
			{
				//     Allocation_Dev[i][j] += Need_Dev[i][j];         //1.让进程已经分配的设备数目加上它仍然需要的 
				Available_Dev[j] -= Need_Dev[i][j];             //2.系统中目前可用的设备数目减去进程需要的

				current_Available_Dev[i][j] = Available_Dev[j];   //记录分配完之后，此时系统的可用资源数目（因为假如会产生安全队列，那么有多少个进程就会产生多少次这样的当前分配后的可用资源数目）
			}

			recycle(Max_Need_Dev[i]);                    // 回收资源
			for (int j = 0; j < Num_Dev; j++)
			{
				current_recycle_Dev[i][j] += Available_Dev[j];
			}

			quene[index] = i;
			index++;
			if (index == num){
				flag = 1;
				printf("安全队列已经返回了。\n");
				break;
			}
		}
		if (count == num){
			printf("会发生死锁。无安全队列。。。。。。\n");
			break;
		}
		if (i == num - 1){
			i = 0;
			continue;
		}
		if (max_times == num*num){
			printf("全部可能已经执行完毕，无安全队列。\n");
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