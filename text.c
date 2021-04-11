#include <stdio.h>
#include <stdlib.h>
typedef int BTDataTypa;
//struct TreeNode                                  //数组定义的树
//{
//	int val;                                     //节点的值。
//	//struct TreeNode* parent;                   //存入他的父亲节点，但是只能从孩子走向父亲不能从父亲走向孩子。
//	int parentindex;                             //存着他父亲的下标，还是只能从孩子遍历父亲，但是通过数组可以遍历整个树。
//};
//struct TreeNode
//{
//	int vol;
//	struct TreeNode* * subs;                     //指针数组，里面存的都是指针。
//	size_t size;
//	size_t capacity;
//};
                                                 //最好的树的定义方式
//struct TreeNode
//{
//	struct Node* _firstChile1;                   //存你的第一个孩子的地址
//	struct Node* _pnextBrother;                  //存你的下一个兄弟的地址
//	DatdType _data;
//};
                                                 //二叉树  二叉链
struct TreeNode
{
	struct BinTreeNode* _pLift;                  //定义他左孩子的节点
	struct BinTreeNode* _pRight;                 //定义他右孩子的节点
	BTDataTypa _data;
};
                                                 //二叉树  三叉链
struct TreeNode
{
	struct BinTreeNode* _pLift;                  //定义他左孩子的节点
	struct BinTreeNode* _pRight;                 //定义他右孩子的节点
	struct BinTreeNode* _pParent;                //定义他父母节点
	BTDataTypa _data;
};


void ReversedOrder(int num)
{
	int Newnum = 0;
	int num0 = num / 100;
	int num1 = (num / 10) % 10;
	int num2 = num %10;
	Newnum = (10 * num1) + num + (100 * num0);
	return Newnum;
}

int main()
{
	int a = 321;
	printf("%d",ReversedOrder(int a));
	return 0;
}