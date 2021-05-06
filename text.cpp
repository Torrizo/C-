#include<iostream>
using namespace std;

//������������
struct BiTreeNode
{
	int data;
	BiTreeNode* left;
	BiTreeNode* right;
};
void preOrder(BiTreeNode *root){
	cout << root->data;
	preOrder(root->left);
	preOrder(root->right);
}

//����
void inOrder(BiTreeNode *root){
	preOrder(root->left);
	cout << root->data;
	preOrder(root->right);
}

//����
void postOrder(BiTreeNode *root){
	preOrder(root->left);
	preOrder(root->right);
	cout << root->data;
}