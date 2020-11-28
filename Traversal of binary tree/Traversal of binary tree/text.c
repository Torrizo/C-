#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//����������ڵ�
typedef struct BTNode {
	char data;
	struct BTNode *rchild, *lchild;
}BTNode, *BTtree;

BTtree createBTNode(BTtree ptr, char value, char child) {
	//�����ӽڵ�
	BTtree ptemp = (BTtree)malloc(sizeof(BTNode));
	if (NULL == ptemp) {
		puts("�����ӽڵ�ʧ��!");
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
	//���ȴ������ڵ�
	BTtree root = (BTtree)malloc(sizeof(BTNode));
	if (root == NULL) {
		puts("���ڵ㴴��ʧ��");
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
//�Զ����������������

void preorder(BTtree p) {
	if (p != NULL) {
		printf("%c ", p->data);
		preorder(p->lchild);    //�������������
		preorder(p->rchild);	//�������������
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
	printf("�������:\n");
	preorder(btroot);
	printf("\n�������:\n");
	inorder(btroot);
	printf("\n�������:\n");
	postorder(btroot);
	system("pause");
	return 0;
}