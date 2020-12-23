//#pragma warning( disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;

typedef struct {
	int weight;
	int parent, lchild, rchild;
}htnode, *huffmantree;
typedef char** huffmancode;
void Select(huffmantree HT, int i, int& s1, int& s2)//把没有父节点的所有节点中最小的两个值赋值给s1，s2 
{
	int j, k = 1;
	while (HT[k].parent) //找最小的父节点为0，即没有父节点的点   
		k++;
	s1 = k;
	for (j = 1; j <= i; j++)
		if (!HT[j].parent && HT[j].weight < HT[s1].weight)//找父节点为0的所有节点中的最小值，赋给s1     
			s1 = j;
	k = 1;
	while (HT[k].parent || k == s1)//找最小的父节点为0，即没有父节点的点，且不等于s1   
		k++;
	s2 = k;
	for (j = 1; j <= i; j++)
		if (!HT[j].parent && HT[j].weight < HT[s2].weight && j != s1)//找父节点为0的所有节点中的不为s1的最小值，赋给s2   
			s2 = j;
}

//构造哈夫曼树
void  huffmancoding(huffmantree& ht, huffmancode& hc, int* w, int n)
{
	if (n <= 1) return;
	int m;
	m = 2 * n - 1;
	ht = (huffmantree)malloc((m + 1) * sizeof(htnode));
	int i;
	huffmantree p;
	w++;
	for (p = ht + 1, i = 1; i <= n; ++i, ++p, ++w)//初始化n个叶子结点
	{
		p->weight = *w;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	for (; i <= m; ++i, ++p)//初始化其它节点
	{
		p->weight = 0;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	for (i = n + 1; i <= m; ++i) //建赫夫曼树
	{
		int s1;		int s2;
		Select(ht, i - 1, s1, s2);                                                                 //在ht[1..i-1]选择parent为0且weight最小的两个结点，其序号分别为s1,s2.
		ht[s1].parent = i; ht[s2].parent = i;
		ht[i].lchild = s1; ht[i].rchild = s2;
		ht[i].weight = ht[s1].weight + ht[s2].weight;
	}
	//编码
	hc = (huffmancode)malloc((n + 1) * sizeof(char*));                                                    //分配n个字符编码的头指针向量
	char* cd = (char*)malloc(n * sizeof(char));                                                             //分配求编码的工作空间
	cd[n - 1] = '\0';//编码结束符
	for (int i = 1; i <= n; ++i)                                                                                 //逐个字符求哈夫曼编码
	{
		int  f;
		int c;
		int start = n - 1;         //控制层数
		for (c = i, f = ht[i].parent; f != 0; c = f, f = ht[f].parent)
		{
			if (ht[f].lchild == c)
				cd[--start] = '0';
			else cd[--start] = '1';
		}
		hc[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(hc[i], &cd[start]);

	}
	free(cd);
}

int main()
{
	int n;
	int* w;
	huffmantree ht;
	huffmancode hc;
	cout << "输入叶子结点个数" << endl;
	cin >> n;
	w = (int*)malloc(n * sizeof(int));
	cout << "输入权值" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	huffmancoding(ht, hc, w, n);
	cout << "编码" << endl;
	for (int i = 1; i <= n; i++)
	{//输出 
		cout << hc[i] << endl;
	}
	return 0;
}
