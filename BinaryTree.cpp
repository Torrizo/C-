#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct BinaryTreeNode
{
	int m_value;
	struct BinaryTreeNode* m_left;
	struct BinaryTreeNode* m_right;
};

struct BinaryTreeNode* CreateBinaryNode(int value)
{
	struct BinaryTreeNode*pNode = new BinaryTreeNode();
	pNode->m_value = value;
	pNode->m_left = nullptr;
	pNode->m_right = nullptr;

	return pNode;
}

void ConnectBinaryNode(struct BinaryTreeNode*Parent, struct BinaryTreeNode* lchild, struct BinaryTreeNode* rchild)
{
	if (Parent != NULL)
	{
		Parent->m_left = lchild;
		Parent->m_right = rchild;
	}
}

void PrintBinaryNode(const struct BinaryTreeNode*node)
{
	if (node != nullptr)
	{
		printf("node value is[%d]\n", node->m_value);
	}
	else
	{
		printf("this node is nullptr\n");
	}
}

void PreorderTraverseTreeNonRec(BinaryTreeNode* pRoot)
{
	std::stack<struct BinaryTreeNode*> stacknode;
	if (pRoot != nullptr)
	{
		stacknode.push(pRoot);
		while (!stacknode.empty())
		{
			BinaryTreeNode* tmp = stacknode.top();
			//´òÓ¡Öµ
			printf("value is[%d]\n", tmp->m_value);
			stacknode.pop();
			if (tmp->m_right)
			{
				stacknode.push(tmp->m_right);
			}
			if (tmp->m_left)
			{
				stacknode.push(tmp->m_left);
			}
		}
	}
}



void DestroyBinary(struct BinaryTreeNode*node)
{
	if (node != nullptr)
	{
		struct BinaryTreeNode*pleft = node->m_left;
		struct BinaryTreeNode*pright = node->m_right;

		delete node;
		node = nullptr;

		if (pleft != nullptr)
		{
			DestroyBinary(pleft);
		}

		if (pright != nullptr)
		{
			DestroyBinary(pright);
		}


	}
}

int main(int argc, char*argv[])
{
	struct BinaryTreeNode* node1 = CreateBinaryNode(10);
	struct BinaryTreeNode* node2 = CreateBinaryNode(6);
	struct BinaryTreeNode* node3 = CreateBinaryNode(14);
	struct BinaryTreeNode* node4 = CreateBinaryNode(4);
	struct BinaryTreeNode* node5 = CreateBinaryNode(8);
	struct BinaryTreeNode* node6 = CreateBinaryNode(12);
	struct BinaryTreeNode* node7 = CreateBinaryNode(16);
	ConnectBinaryNode(node1, node2, node3);
	ConnectBinaryNode(node2, node4, node5);
	ConnectBinaryNode(node3, node6, node7);
	printf("preorder no rec start\n");
	PreorderTraverseTreeNonRec(node1);
	system("pause");
	return 0;
}
