#include <stdio.h>
#include <stdlib.h>
typedef int BTDataTypa;
//struct TreeNode                                  //���鶨�����
//{
//	int val;                                     //�ڵ��ֵ��
//	//struct TreeNode* parent;                   //�������ĸ��׽ڵ㣬����ֻ�ܴӺ��������ײ��ܴӸ��������ӡ�
//	int parentindex;                             //���������׵��±꣬����ֻ�ܴӺ��ӱ������ף�����ͨ��������Ա�����������
//};
//struct TreeNode
//{
//	int vol;
//	struct TreeNode* * subs;                     //ָ�����飬�����Ķ���ָ�롣
//	size_t size;
//	size_t capacity;
//};
                                                 //��õ����Ķ��巽ʽ
//struct TreeNode
//{
//	struct Node* _firstChile1;                   //����ĵ�һ�����ӵĵ�ַ
//	struct Node* _pnextBrother;                  //�������һ���ֵܵĵ�ַ
//	DatdType _data;
//};
                                                 //������  ������
struct TreeNode
{
	struct BinTreeNode* _pLift;                  //���������ӵĽڵ�
	struct BinTreeNode* _pRight;                 //�������Һ��ӵĽڵ�
	BTDataTypa _data;
};
                                                 //������  ������
struct TreeNode
{
	struct BinTreeNode* _pLift;                  //���������ӵĽڵ�
	struct BinTreeNode* _pRight;                 //�������Һ��ӵĽڵ�
	struct BinTreeNode* _pParent;                //��������ĸ�ڵ�
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