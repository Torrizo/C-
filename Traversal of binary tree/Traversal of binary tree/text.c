#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//定义二叉树节点
typedef struct BTNode {
	char data;
	struct BTNode *rchild, *lchild;
}BTNode, *BTtree;

BTtree createBTNode(BTtree ptr, char value, char child) {
	//创建子节点
	BTtree ptemp = (BTtree)malloc(sizeof(BTNode));
	if (NULL == ptemp) {
		puts("创建子节点失败!");
		exit(1);
	}
	ptemp->data = value;
	ptemp->rchild = NULL;
	ptemp->lchild = NULL;
	if (child == 'R') {
		ptr->rchild = ptemp;
	}
	else if (child == 'L') {
		ptr->lchild = ptemp;
	}
	return ptemp;

}

BTtree initBTree() {
	//首先创建根节点
	BTtree root = (BTtree)malloc(sizeof(BTNode));
	if (root == NULL) {
		puts("根节点创建失败");
		exit(1);
	}
	root->data = 'A';
	root->rchild = NULL;
	root->lchild = NULL;
	BTtree pb = createBTNode(root, 'B', 'L');
	BTtree pc = createBTNode(root, 'C', 'R');
	BTtree pd = createBTNode(pb, 'D', 'L');
	BTtree pe = createBTNode(pb, 'E', 'R');
	BTtree pf = createBTNode(pc, 'F', 'L');
	BTtree pg = createBTNode(pc, 'G', 'R');
	return root;
}
//对二叉树进行先序遍历

void preorder(BTtree p) {
	if (p != NULL) {
		printf("%c ", p->data);
		preorder(p->lchild);    //先序遍历左子树
		preorder(p->rchild);	//先序遍历右子树
	}
}
void inorder(BTtree p) {
	if (p != NULL) {
		inorder(p->lchild);
		printf("%c ", p->data);
		inorder(p->rchild);
	}
}
void postorder(BTtree p) {
	if (p != NULL) {
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%c ", p->data);
	}
}
int main() {
	BTtree btroot = initBTree();
	//printf("%c\n",btroot->data);
	printf("先序遍历:\n");
	preorder(btroot);
	printf("\n中序遍历:\n");
	inorder(btroot);
	printf("\n后序遍历:\n");
	postorder(btroot);
	system("pause");
	return 0;
}