#define _CRT_SECURE_NO_WARNINGS

#include<malloc.h>
#include<stdio.h>

/*用邻接表实现关键路径的求*/

#define MAX 20 /*头结点的最大值*/
#define NUNUM 20

struct node /*邻接点定义*/
{
	int adjvex; /*顶点信息，序号*/
	int dut; /*权值*/
	struct node *next;
};


struct vnode /*头结点定义*/
{
	int vertex; /*顶点信息，序号*/
	int id; /*顶点入度*/
	struct node *link; /*头结点的链域，指向后续邻接点*/
}Adjlist[MAX];


void CreateGraph(struct vnode Adjlist[MAX], int n, int e)/*构建图*/
{
	/*n为顶点数,e为图的边数*/
	int i, j, k, l;
	struct node * p;/*开辟新的邻接点所用的指针类型变量*/


	for (i = 1; i <= n; i++)
	{
		/*建立顶点表*/

		Adjlist[i].vertex = i;
		Adjlist[i].id = 0;
		Adjlist[i].link = NULL;
	}


	for (k = 1; k <= e; k++)
	{
		/*邻接表完善*/
		printf("\nEnter bian<Vi,Vj>de i,j and bian shang de quan zhi w:");
		scanf("%d", &i);
		scanf("%d", &j);

		scanf("%d", &l);
		p = (struct node *)malloc(sizeof(struct node));/*生成新的边表结点*/
		p->adjvex = j; /*将邻接点序号赋值给新结点的顶点信息域*/
		p->dut = l; /*权值*/
		p->next = Adjlist[i].link;
		Adjlist[i].link = p; /*将新结点插入到顶点Vi的边表头部*/
	}

	for (i = 1; i <= n; i++)
	{
		p = Adjlist[i].link;
		while (p != NULL)
		{
			k = p->adjvex;
			Adjlist[k].id = Adjlist[k].id + 1;
			p = p->next;
		}

	}

}


void CriticalPath(struct vnode Adjlist[MAX], int n)
{
	int i, j, m, front, rear;
	int k = 0;

	int ve[NUNUM], vl[NUNUM], e[NUNUM], l[NUNUM];
	int tpord[NUNUM];

	struct node *p;

	for (i = 1; i <= n; i++) /*顶点的最早和最迟发生时间，初始化为0*/
	{
		ve[i] = 0; /*最早发生时间*/
		vl[i] = 0; /*最迟发生时间*/
	}
	front = 0; /*关于堆栈所用变量 front（跟随变量，判断是否堆栈中的结点数据是否已经全部操作过）rear的初始化为0*/
	rear = 0; /*入栈时所用的变量，与数组tpord相联系*/

	for (i = 1; i <= n; i++) /*首先，遍历邻接表的表头，查找入度为0的顶点，并存入堆栈数组tpord中*/
	{
		if (Adjlist[i].id == 0)
		{
			rear++;
			tpord[rear] = i; /*头结点入度为0的点入栈，数组tpord[]，从低到高的顺序存入*/
		}
	}

	m = 0; /*变量初始化，此变量为计数顶点的变量m，其将作为判断图是否有回路使用*/
	while (front != rear) /*栈不空时*/
	{
		front++; /*从低到高的顺序，去对堆栈进行操作*/
		j = tpord[front];/*每次取一个入度为0的顶点，并对其进行如下操作*/
		m++; /*每取一个结点，对M进行加1操作*/

		p = Adjlist[j].link;/*将结点的指针域传给p*/
		while (p != NULL)/*即用p对结点的后续结点进行循环操作*/
		{
			k = p->adjvex;/*取一个邻接点信息，序号*/
			Adjlist[k].id = Adjlist[k].id - 1; /*并将其邻接点入度减去1*/

			if (ve[j] + (p->dut)>ve[k])
				ve[k] = ve[j] + (p->dut); /*顶点的最早发生时间，即取最大值*/

			if (Adjlist[k].id == 0) /*然后判断，若此后续邻接点入度为0，则入栈tpord*/
			{
				rear++;
				tpord[rear] = k; /*在原来数组的基础上进行操作，往上执行*/
			}
			p = p->next;/*对其下一个邻接点进行同样的操作，即入度减1，做最早发生时间的工作，然后判断是否入栈（入度是否为0）*/
		}
	}


	if (m<n) /*n为总结点数，m为遍历时所用的计数器，每遍历一个变量将进行加1操作*/
	{
		printf("\nWang zhong you hui lu ！Cannot tuo pu pai xu!");/*图中是否有回路*/
		return;
	}


	for (i = 1; i <= n; i++)
		vl[i] = ve[n]; /*把所用结点的最早发生时间数据赋值给最迟发生时间数组*/


	for (i = n - 1; i >= 1; i--) /*进行逆拓扑排序，从堆栈数据的最高位开始*/
	{
		j = tpord[i]; /*取结点号*/
		p = Adjlist[j].link; /*取结点的后续邻接点的指针域*/
		while (p != NULL) /*对此结点的邻接点进行操作*/
		{
			k = p->adjvex; /*取 邻接点信息，即编号*/
			if ((vl[k] - p->dut)<vl[j]) /*在活动<j,k>上进行操作，确定事件j的最迟发生时间*/
				vl[j] = vl[k] - (p->dut);
			p = p->next; /*对其下一个邻接点进行同样的操作*/
		}

	} /*逆拓扑排序结束*/


	i = 0; /*循环判断确定 每个结点的最早发生时间 和最迟发生时间是否相等*/

	for (j = 1; j <= n; j++)
	{
		p = Adjlist[j].link;/*取头结点的邻接点的指针域，赋值给p*/
		while (p != NULL)
		{
			k = p->adjvex; /*获得邻接点的序号，或位置*/
			i++; /*i++操作*/

			e[i] = ve[j]; /*事件j的最早发生时间就是其后活动i的最早发生时间*/
			l[i] = vl[k] - (p->dut);/*<j--ai--k>活动ai的最迟发生时间=vl[k]-(p->dut)*/

			printf("\n <%d ,%d>:", Adjlist[j].vertex, Adjlist[k].vertex);
			if (l[i] == e[i]) /*判断是否活动ai的最早发生时间=最迟发生时间？若相等，则此活动为关键活动！*/
			{
				printf("is the key acctivity!");

			}
			else
			{
				printf("is not the key acctivity!");

			}
			p = p->next;
		}
	}

	printf("\nThanks ,BYE!");
}


int main()
{
	int n, e;
	printf("\nPlease enter the data of ding dian shu :");
	scanf("%d", &n);
	printf("\nPlease enter the data of bian shu: ");
	scanf("%d", &e);


	CreateGraph(Adjlist, n, e);
	CriticalPath(Adjlist, n);
	system("pause");
	return 0;
}