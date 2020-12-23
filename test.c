//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//
//typedef struct
//{
//	int w, f, lc, rc; // 权值 双亲结点和左 右子节点
//}node, *tree;
//
//void q(tree*HT, int n, int*s1, int*s2)
//{
//	int mi;
//	for (int i = 1; i <= n; i++)     // 找到第一个最小值
//	{
//		if (!(*HT)[i].f)
//		{
//			mi = i;
//			break;
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if ((*HT)[i].f == 0 && ((*HT)[i].w<(*HT)[mi].w))
//			mi = i;
//	}
//	*s1 = mi;    // 找到第二个与第一个不同的最小值
//	for (int i = 1; i <= n; i++)
//	{
//		if ((*HT)[i].f == 0 && i != *s1)
//		{
//			mi = i;
//			break;
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if ((*HT)[i].f == 0 && i != *s1 && ((*HT)[i].w<(*HT)[mi].w))
//			mi = i;
//	}
//	*s2 = mi;
//}
//
//void build(tree*HT, int*w, int n);
//
//int main()
//{
//	int*a, n, x;
//	scanf("%d", &n);
//	a = (int*)malloc((n + 1)*sizeof(int)); //c++:w = new int[n+1];
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &x);
//		a[i] = x;
//	}
//	tree HT;
//	build(&HT, a, n);
//	system("pause");
//	return 0;
//}
//
//void build(tree*HT, int*w, int n) /* 答案 */
//{
//	int m = n * 2 - 1, s1, s2;
//	(*HT) = (node*)malloc((m + 1)*sizeof(node)); //HT=new Nodee[m+1];
//	for (int i = 1; i <= n; i++)
//	{
//		(*HT)[i].w = w[i];
//		(*HT)[i].f = (*HT)[i].lc = (*HT)[i].rc = 0;
//	}
//	for (int i = n + 1; i <= m; i++)
//		(*HT)[i].w = (*HT)[i].f = (*HT)[i].lc = (*HT)[i].rc = 0;
//	for (int i = n + 1; i <= m; i++)
//	{
//		q(HT, i - 1, &s1, &s2); //  ss(&HT,i-1,&s1,&s2);
//		(*HT)[s1].f = (*HT)[s2].f = i;
//		(*HT)[i].lc = s1, (*HT)[i].rc = s2;
//		(*HT)[i].w = (*HT)[s1].w + (*HT)[s2].w;
//		printf("%d(%d,%d),", (*HT)[i].w, (*HT)[s1].w, (*HT)[s2].w);
//	}
//	printf("\n");
//}
