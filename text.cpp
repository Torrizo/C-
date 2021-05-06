#include<iostream>
using namespace std;

//定义二叉树结点
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

//中序
void inOrder(BiTreeNode *root){
	preOrder(root->left);
	cout << root->data;
	preOrder(root->right);
}

//后序
void postOrder(BiTreeNode *root){
	preOrder(root->left);
	preOrder(root->right);
	cout << root->data;
}