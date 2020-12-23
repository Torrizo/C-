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
void Select(huffmantree HT, int i, int& s1, int& s2)//��û�и��ڵ�����нڵ�����С������ֵ��ֵ��s1��s2 
{
	int j, k = 1;
	while (HT[k].parent) //����С�ĸ��ڵ�Ϊ0����û�и��ڵ�ĵ�   
		k++;
	s1 = k;
	for (j = 1; j <= i; j++)
		if (!HT[j].parent && HT[j].weight < HT[s1].weight)//�Ҹ��ڵ�Ϊ0�����нڵ��е���Сֵ������s1     
			s1 = j;
	k = 1;
	while (HT[k].parent || k == s1)//����С�ĸ��ڵ�Ϊ0����û�и��ڵ�ĵ㣬�Ҳ�����s1   
		k++;
	s2 = k;
	for (j = 1; j <= i; j++)
		if (!HT[j].parent && HT[j].weight < HT[s2].weight && j != s1)//�Ҹ��ڵ�Ϊ0�����нڵ��еĲ�Ϊs1����Сֵ������s2   
			s2 = j;
}

//�����������
void  huffmancoding(huffmantree& ht, huffmancode& hc, int* w, int n)
{
	if (n <= 1) return;
	int m;
	m = 2 * n - 1;
	ht = (huffmantree)malloc((m + 1) * sizeof(htnode));
	int i;
	huffmantree p;
	w++;
	for (p = ht + 1, i = 1; i <= n; ++i, ++p, ++w)//��ʼ��n��Ҷ�ӽ��
	{
		p->weight = *w;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	for (; i <= m; ++i, ++p)//��ʼ�������ڵ�
	{
		p->weight = 0;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	for (i = n + 1; i <= m; ++i) //���շ�����
	{
		int s1;		int s2;
		Select(ht, i - 1, s1, s2);                                                                 //��ht[1..i-1]ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1,s2.
		ht[s1].parent = i; ht[s2].parent = i;
		ht[i].lchild = s1; ht[i].rchild = s2;
		ht[i].weight = ht[s1].weight + ht[s2].weight;
	}
	//����
	hc = (huffmancode)malloc((n + 1) * sizeof(char*));                                                    //����n���ַ������ͷָ������
	char* cd = (char*)malloc(n * sizeof(char));                                                             //���������Ĺ����ռ�
	cd[n - 1] = '\0';//���������
	for (int i = 1; i <= n; ++i)                                                                                 //����ַ������������
	{
		int  f;
		int c;
		int start = n - 1;         //���Ʋ���
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
	cout << "����Ҷ�ӽ�����" << endl;
	cin >> n;
	w = (int*)malloc(n * sizeof(int));
	cout << "����Ȩֵ" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	huffmancoding(ht, hc, w, n);
	cout << "����" << endl;
	for (int i = 1; i <= n; i++)
	{//��� 
		cout << hc[i] << endl;
	}
	return 0;
}
