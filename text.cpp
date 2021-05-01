#ifndef _RB_TREE_H_
#define _RB_TREE_H_
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

enum NodeColor
{
	RED,
	BLACK
};

template<class KEY, class VALUE>
class RB_Node	//�����
{
public:
	RB_Node()	//�ڵ��๹��
	{
		right = NULL;
		left = NULL;
		parent = NULL;
	}
	NodeColor RB_COLOR;	//��ɫ
	RB_Node<KEY, VALUE>* right;	//������
	RB_Node<KEY, VALUE>* left;	//������
	RB_Node<KEY, VALUE>* parent;	//�����
	KEY key;	//��
	VALUE val;	//ֵ
};

template<class KEY, class VALUE>
class RB_Tree
{
	//RB����
private:
	RB_Tree(const RB_Tree & input){}
	const RB_Tree& operator=(const RB_Tree& input){}
	void InOrderTraverse(RB_Node<KEY, VALUE>* node);	//�������
	void clear(RB_Node<KEY, VALUE>* node);	//���RB��
	//��Ա����
	RB_Node<KEY, VALUE>* m_nullNode;
	RB_Node<KEY, VALUE>* m_root;
	RB_Node<KEY, VALUE>* m_DBNode;
public:
	RB_Tree();	//���캯��
	bool Empty();	//�Ƿ�Ϊ����
	RB_Node<KEY, VALUE>* find(KEY key);	//���Ҽ�key��ֵ
	bool Insert(KEY key, VALUE val);	//����
	void InsertFixUp(RB_Node<KEY, VALUE>* node);	//������޸�
	bool RotateLeft(RB_Node<KEY, VALUE>* node);		//����
	bool RotateRight(RB_Node<KEY, VALUE>* node);	//����
	bool Delete(KEY key);	//ɾ��
	void DoubleBlackFixUp(RB_Node<KEY, VALUE>* node);	//˫���޸�
	RB_Node<KEY, VALUE>* FindMin(RB_Node<KEY, VALUE>* node);
	void InOrderTraverse()	//��������ⲿ�ӿ�
	{
		InOrderTraverse(m_root);
	}
	~RB_Tree()
	{
		clear(m_root);
		delete m_nullNode;
	}
};

template<class KEY, class VALUE>
RB_Tree<KEY, VALUE>::RB_Tree()		//���캯��
{
	this->m_nullNode = new RB_Node<KEY, VALUE>();
	this->m_root = m_nullNode;
	this->m_nullNode->right = this->m_root;
	this->m_nullNode->left = this->m_root;
	this->m_nullNode->parent = this->m_root;
	this->m_nullNode->RB_COLOR = BLACK;
	this->m_DBNode = new RB_Node<KEY, VALUE>();
	this->m_DBNode->RB_COLOR = BLACK;
	this->m_DBNode->left = m_nullNode;
	this->m_DBNode->right = m_nullNode;
};

template<class KEY, class VALUE>
bool RB_Tree<KEY, VALUE>::Empty()
{
	if (this->m_root == this->m_nullNode)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class KEY, class VALUE>
RB_Node<KEY, VALUE>* RB_Tree<KEY, VALUE>::find(KEY key)	//���ң��˴��ɵݹ飬�ο���һƪ���������
{
	RB_Node<KEY, VALUE>* index = m_root;
	while (index != m_nullNode)
	{
		if (key<index->key)
		{
			index = index->left;
		}
		else if (key>index->key)
		{
			index = index->right;
		}
		else
		{
			break;
		}
	}
	return index;
}

/*
����������һ��ָ��lower_rightָ����ת����Һ��ӡ�
lower_right�ĸ����Ϊ��ת��ĸ����,��ת����Һ���Ϊlower_right�����ӣ�������Ӳ�Ϊ�գ���Ҫ�������ӵĸ���Ϊ��ת�㣩��
�ж���ת���Ƿ�Ϊ���ڵ㡣�ǵĻ�����m_root��ֵ�����������ת��ĸ�������� or �Һ��ӵ�ָ��
������ת�㸸���Ϊlower_right��lower_right������Ϊ��ת��
*/
template<class KEY, class VALUE>
bool RB_Tree<KEY, VALUE>::RotateLeft(RB_Node<KEY, VALUE>* node)
{
	if (node == m_nullNode || node->right == m_nullNode)
	{
		return false;	//������ת
	}
	RB_Node<KEY, VALUE>* lower_right = node->right;
	lower_right->parent = node->parent;
	node->right = lower_right->left;
	if (lower_right->left != m_nullNode)
	{
		lower_right->left->parent = node;
	}
	if (node->parent == m_nullNode)
	{
		m_root = lower_right;
		m_nullNode->right = m_root;
		m_nullNode->left = m_root;
	}
	else
	{
		if (node == node->parent->left)
		{
			node->parent->left = lower_right;
		}
		else
		{
			node->parent->right = lower_right;
		}
	}
	node->parent = lower_right;
	lower_right->left = node;
}
template<class KEY, class VALUE>
bool RB_Tree<KEY, VALUE>::RotateRight(RB_Node<KEY, VALUE>* node)	//������ԭ��ͬ����,left��right�����Ϳ���
{
	if (node == m_nullNode || node->left == m_nullNode)
	{
		return false;//can't rotate    
	}
	RB_Node<KEY, VALUE>* lower_left = node->left;
	node->left = lower_left->right;
	lower_left->parent = node->parent;
	if (lower_left->right != m_nullNode)
	{
		lower_left->right->parent = node;
	}
	if (node->parent == m_nullNode) //node is root    
	{
		m_root = lower_left;
		m_nullNode->left = m_root;
		m_nullNode->right = m_root;
		//m_nullNode->parent = m_root;    
	}
	else
	{
		if (node == node->parent->right)
		{
			node->parent->right = lower_left;
		}
		else
		{
			node->parent->left = lower_left;
		}
	}
	node->parent = lower_left;
	lower_left->right = node;
}

/*
���룬whileѭ����insert_pointָ��Ҫ����ĵ�
���������Ѿ����ڣ�����false������������һ�ſ�����ֱ�Ӹ�ֵ�����ڵ㡣�����ڲ���㸳ֵ
*/
template<class KEY, class VALUE>
bool RB_Tree<KEY, VALUE>::Insert(KEY key, VALUE val)
{
	RB_Node<KEY, VALUE>* insert_point = m_nullNode;
	RB_Node<KEY, VALUE>* index = m_root;
	while (index != m_nullNode)
	{
		insert_point = index;
		if (key<index->key)
		{
			index = index->left;
		}
		else if (key > index->key)
		{
			index = index->right;
		}
		else
		{
			return false;
		}
	}	//��ʱinsert_pointָ��Ҫ����ĵ�
	RB_Node<KEY, VALUE>* insert_node = new RB_Node<KEY, VALUE>();	//�������Ľ��
	insert_node->key = key;
	insert_node->val = val;
	insert_node->RB_COLOR = RED;
	insert_node->right = m_nullNode;
	insert_node->left = m_nullNode;
	if (insert_point == m_nullNode)		//�����һ�ſ���
	{
		m_root = insert_node;
		m_root->parent = m_nullNode;
		m_nullNode->left = m_root;
		m_nullNode->right = m_root;
		m_nullNode->parent = m_root;
	}
	else
	{
		if (key < insert_point->key)
		{
			insert_point->left = insert_node;
		}
		else
		{
			insert_point->right = insert_node;
		}
		insert_node->parent = insert_point;
	}
	InsertFixUp(insert_node);	//����InsertFixUp�޸����������
}

/*
A	���׽ڵ�Ϊ��ɫʱ���޸�
�����޸�����Ϊ�����ĸ�������游�������ӻ����Һ���
B	���ӵĻ���
C		����һ��uncle���ָ������ڵ㣨�������ֵܣ���
D		1�����������Ϊ��ɫ���������������ڣ��游�ڵ�������Ϊ��ǰ���
E		2������ڵ�Ϊ��ɫ���������ڵ��Ǹ��ڵ���Һ��ӣ��������Ϊ��ǰ�ڵ�Ȼ��������ת��Ϊ�������������
F		3������ڵ�Ϊ��ɫ������ڵ�Ϊ���ӣ�������ڣ��游��죬�游���Ϊ֧������
G	�Һ��ӵĻ���
*/
template<class KEY, class VALUE>
void RB_Tree<KEY, VALUE>::InsertFixUp(RB_Node<KEY, VALUE>* node)
{
	while (node->parent->RB_COLOR == RED)		//A
	{
		if (node->parent == node->parent->parent->left)	//B
		{
			RB_Node<KEY, VALUE>* uncle = node->parent->parent->right;	//C
			if (uncle->RB_COLOR == RED)	//D
			{
				node->parent->RB_COLOR = BLACK;
				uncle->RB_COLOR = BLACK;
				node->parent->parent->RB_COLOR = RED;
				node = node->parent->parent;
			}
			else if (uncle->RB_COLOR == BLACK)
			{
				if (node == node->parent->right)	//E
				{
					node = node->parent;
					RotateLeft(node);
				}
				//F
				node->parent->RB_COLOR = BLACK;
				node->parent->parent->RB_COLOR = RED;
				RotateRight(node->parent->parent);
			}
		}
		else    //G
		{
			RB_Node<KEY, VALUE>* uncle = node->parent->parent->left;
			if (uncle->RB_COLOR == RED)
			{
				node->parent->RB_COLOR = BLACK;
				uncle->RB_COLOR = BLACK;
				uncle->parent->RB_COLOR = RED;
				node = node->parent->parent;
			}
			else if (uncle->RB_COLOR == BLACK)
			{
				if (node == node->parent->left)
				{
					node = node->parent;
					RotateRight(node);
				}

				node->parent->RB_COLOR = BLACK;
				node->parent->parent->RB_COLOR = RED;
				RotateLeft(node->parent->parent);
			}
		}
	}
	m_root->RB_COLOR = BLACK;	//�޸����ڵ���ɫ����ֹ����Ϊ��ɫ
}

/*
ɾ��һ����㣺

*/
template<class KEY, class VALUE>
bool RB_Tree<KEY, VALUE>::Delete(KEY key)
{

	RB_Node<KEY, VALUE>* delete_point = find(key);	//�ҵ�Ҫɾ���ĵ�
	if (delete_point == m_nullNode)
	{
		return false;
	}
	if (delete_point->left != m_nullNode && delete_point->right != m_nullNode)	//�������ӽ��
	{
		RB_Node<KEY, VALUE>* replace_node = FindMin(delete_point->right);
		//ɾ������滻���ֵ�����������ɫ����
		KEY tmpkey = delete_point->key;
		VALUE tmpval = delete_point->val;
		delete_point->key = replace_node->key;
		delete_point->val = replace_node->val;
		replace_node->key = tmpkey;
		replace_node->val = tmpval;
		delete_point = replace_node;
	}
	RB_Node<KEY, VALUE>* delete_point_child;
	if (delete_point->RB_COLOR == RED)	//���ýڵ�Ϊ��ɫ
	{
		if (delete_point == delete_point->parent->left)	//���������
		{
			delete_point->parent->left = m_nullNode;
		}
		else   //������Һ���
		{
			delete_point->parent->right = m_nullNode;
		}
		delete delete_point;
	}

	else if (delete_point->right != m_nullNode)	//����ҽ�㲻Ϊ��,��ʱҪɾ���Ľ��϶�Ϊ��ɫ�����ҽ��϶�Ϊ��ɫ
	{
		if (delete_point == delete_point->parent->left)	//Ҫɾ���ĵ�������
		{
			delete_point->parent->left = delete_point->right;
			delete_point->right->parent = delete_point->parent;
		}
		else
		{
			delete_point->parent->right = delete_point->right;
			delete_point->right->parent = delete_point->parent;
		}
		delete_point->right->RB_COLOR = BLACK;	//�ҽ����ɫ��Ϊ��ɫ
		delete delete_point;
	}
	else if (delete_point->left != m_nullNode)	//������㲻Ϊ�գ�δ�����滻�������ҽڵ㲻Ϊ�ղ���һ��
	{
		if (delete_point == delete_point->parent->left)	//Ҫɾ���ĵ�������
		{
			delete_point->parent->left = delete_point->left;
			delete_point->left->parent = delete_point->parent;
		}
		else
		{
			delete_point->parent->right = delete_point->left;
			delete_point->left->parent = delete_point->parent;
		}
		delete_point->left->RB_COLOR = BLACK;	//�ҽ����ɫ��Ϊ��ɫ
		delete delete_point;
	}
	else    //���ӽڵ�����
	{
		//��ʱΨһʣ�����Ϊ��Ҫɾ�����Ϊ��ɫ�����ӽ��
		if (delete_point->parent == m_nullNode)	//���Ҫɾ�����Ǹ��ڵ�
		{
			m_root = m_nullNode;
			m_nullNode->parent = m_root;
			m_nullNode->left = m_root;
			m_nullNode->left = m_root;
			delete delete_point;
		}
		else
		{


			RB_Node<KEY, VALUE>* tmp = delete_point->parent;
			if (delete_point == delete_point->parent->left)	//���Ҫɾ�����Ϊ��ڵ�
			{

				delete delete_point;
				tmp->left = m_DBNode;
				m_DBNode->parent = tmp;
				DoubleBlackFixUp(m_DBNode);
				tmp->left = m_nullNode;
			}
			else	//���Ҫɾ�����Ϊ�ҽڵ�
			{

				delete delete_point;
				tmp->right = m_DBNode;
				m_DBNode->parent = tmp;
				DoubleBlackFixUp(m_DBNode);
				tmp->right = m_nullNode;
			}
		}
	}
}

/*
˫���޸�
*/
template<class KEY, class VALUE>
void RB_Tree<KEY, VALUE>::DoubleBlackFixUp(RB_Node<KEY, VALUE>* node)	//�������Ĳ�������˫�ڽ��
{

	if (node == node->parent->left)	//����˽��������
	{

		RB_Node<KEY, VALUE>* brother = node->parent->right;
		//���3
		if (brother->RB_COLOR == RED)
		{
			node->parent->RB_COLOR = RED;
			brother->RB_COLOR = BLACK;
			RotateLeft(node->parent);
			//֮��ת�����1��2
		}
		//���1
		if (brother->RB_COLOR == BLACK && (brother->left->RB_COLOR == RED || brother->right->RB_COLOR == RED))
		{


			if (brother->right->RB_COLOR == RED)	//A
			{
				brother->RB_COLOR = node->parent->RB_COLOR;
				brother->right->RB_COLOR == BLACK;
				node->parent->RB_COLOR = BLACK;
				RotateLeft(node->parent);
			}
			else   //B
			{
				RotateRight(brother);
				node->parent->right->RB_COLOR = node->parent->RB_COLOR;
				node->parent->RB_COLOR = BLACK;
				RotateLeft(node->parent);
			}
		}
		//���2
		else if (brother->RB_COLOR == BLACK && (brother->left->RB_COLOR == BLACK && brother->right->RB_COLOR == BLACK))
		{
			while (node->parent != m_nullNode)	//��node���Ǹ��ڵ��ʱ��
			{
				brother->RB_COLOR = RED;
				if (node->parent->RB_COLOR == RED)	//�����ԭ��Ϊ��ɫ
				{
					node->parent->RB_COLOR = BLACK;
					break;
				}
				else  //����㱾�����Ǻ�ɫ
				{
					node = node->parent;
				}
			}
		}

	}
	else    //����˽ڵ����ҽ�㣬��������� left��right�����Ϳ���
	{
		RB_Node<KEY, VALUE>* brother = node->parent->left;
		//���3
		if (brother->RB_COLOR == RED)
		{
			node->parent->RB_COLOR = RED;
			brother->RB_COLOR = BLACK;
			RotateRight(node->parent);
			//֮��ת�����1��2
		}
		//���1
		if (brother->RB_COLOR == BLACK && (brother->right->RB_COLOR == RED || brother->left->RB_COLOR == RED))
		{
			if (brother->left->RB_COLOR == RED)	//A,Զֶ��
			{
				brother->RB_COLOR = node->parent->RB_COLOR;
				brother->left->RB_COLOR = BLACK;
				node->parent->RB_COLOR = BLACK;
				RotateRight(node->parent);
			}
			else   //B
			{
				RotateLeft(brother);
				node->parent->left->RB_COLOR = node->parent->RB_COLOR;
				node->parent->RB_COLOR = BLACK;
				RotateRight(node->parent);
			}
		}
		//���2
		else if (brother->RB_COLOR == BLACK && (brother->right->RB_COLOR == BLACK && brother->left->RB_COLOR == BLACK))
		{
			while (node->parent != m_nullNode)	//��node���Ǹ��ڵ��ʱ��
			{
				brother->RB_COLOR = RED;
				if (node->parent->RB_COLOR == RED)	//�����ԭ��Ϊ��ɫ
				{
					node->parent->RB_COLOR = BLACK;
					break;
				}
				else  //����㱾�����Ǻ�ɫ
				{
					node = node->parent;
				}
			}
		}
	}
}

template<class KEY, class VALUE>
RB_Node<KEY, VALUE>* RB_Tree<KEY, VALUE>::FindMin(RB_Node<KEY, VALUE>* node)
{
	if (node->left == m_nullNode)
		return node;
	return FindMin(node->left);
}

template<class KEY, class VALUE>	//�������
void RB_Tree<KEY, VALUE>::InOrderTraverse(RB_Node<KEY, VALUE>* node)
{
	if (node == m_nullNode)
	{
		return;
	}
	else
	{
		InOrderTraverse(node->left);
		cout << node->key << endl;
		InOrderTraverse(node->right);
	}
}

template<class KEY, class VALUE>
void RB_Tree<KEY, VALUE>::clear(RB_Node<KEY, VALUE>* node)
{
	if (node == m_nullNode)
	{
		return;
	}
	else
	{
		clear(node->left);
		clear(node->right);
		delete node;
	}
};

