#include<vector>
#include<iostream>
using namespace std;
template < class T >
struct AVLTreeNode
{
	T _data;
	//���Һ��ӵ�ָ��
	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	//���ڵ��ָ��
	AVLTreeNode<T>* _parent;
	//ƽ������
	int _bf;

	AVLTreeNode(const T& val = T())
		: _data(val)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};

template < class T >
class AVLTree
{
public:
	typedef AVLTreeNode<T> Node;

	bool insert(const T& val)
	{
		//�������������ڵ�
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		//����
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_data == val)
				return false;
			else if (cur->_data > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(val);
		if (parent->_data > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		//����parentָ��
		cur->_parent = parent;
		//����ƽ�����ӣ���parent��ʼ
		// ���·�Χ:��parentһֱ��root����·���ϵ����Ƚڵ�
		while (parent)  //�ղ���ڵ��ֱ�Ӹ��ڵ㣬Ҳ����Ϊ���Ƚڵ�
		{
			if (parent->_left == cur)
				parent->_bf--;
			else
				parent->_bf++;
			if (parent->_bf == 0) //��-1��1�仯������
				//parent�ڵ�ĳһ�������룬parent�ĸ߶Ȳ�û�з����仯
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)  //��0�仯����
			{
				//��������
				cur = parent;
				parent = parent->_parent;
			}
			else
			{
				//���������������´ﵽƽ��״̬
				if (parent->_bf == -2 && cur->_bf == 1)
				{
					//��ߵ���߸ߣ�����
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					//�ұߵ��ұ߸ߣ�����
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					//����˫��
					RotateL(cur);
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					//����˫��
					RotateR(cur);
					RotateL(parent);
				}
				break;

			}
		}
		return true;
	}

	void RotateR(Node* parent)
	{
		//�������ĸ��ڵ�
		Node* subL = parent->_left;
		//���������������ĸ��ڵ�
		Node* subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		//���parentΪ���ڵ㣬����Ҫ���¸��ڵ�
		if (parent == _root)
		{
			_root = subL;
			//���ڵ�û�и��ڵ�
			subL->_parent = nullptr;
		}

		Node* pparent = parent->_parent;
		if (pparent->_left == parent)
			pparent->_left = subL;
		else
			pparent->_right = subL;
		subL->_parent = pparent;
		parent->_parent = subL;

		//����ƽ������
		parent->_bf = subL->_bf = 0;
	}
	void RotateL(Node* parent)
	{
		//�������ĸ��ڵ�
		Node* subR = parent->_right;
		//���������������ĸ��ڵ�
		Node* subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		//���parentΪ���ڵ㣬����Ҫ���¸��ڵ�
		if (parent == _root)
		{
			_root = subR;
			//���ڵ�û�и��ڵ�
			subR->_parent = nullptr;
		}

		Node* pparent = parent->_parent;
		if (pparent->_right == parent)
			pparent->_right = subR;
		else
			pparent->_left = subR;
		subR->_parent = pparent;
		parent->_parent = subR;

		//����ƽ������
		parent->_bf = subR->_bf = 0;
	}

	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}
	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_data << "_data" <<" ";
			_inorder(root->_right);
		}
	}

	int getHeight(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left = getHeight(root->_left);
		int right = getHeight(root->_right);
		return left > right ? left + 1 : right + 1;
	}

	bool isBalance()
	{
		return _isBalance(_root);
	}
	bool _isBalance(Node* root)
	{
		if (root == nullptr)
			return true;
		int rightHeight = getHeight(root->_right);
		int leftHeight = getHeight(root->_left);
		//�ж�ƽ�������Ƿ���ȷ��bf = right - left
		if (root->_bf != rightHeight - leftHeight)
		{
			//ƽ������������
			cout << "��ǰλ��" << root->_data << " bf: " << root->_bf <<"left:" << leftHeight << "right:" << rightHeight << endl;
			return false;
		}
		return abs(root->_bf) < 2 
			&& _isBalance(root->_left) 
			&& _isBalance(_root->_right);
	}
private:
	Node* _root = nullptr;
};

void test()
{
	AVLTree<int> avl;
	//avl.insert(60);
	//avl.insert(30);
	//avl.insert(65);
	//avl.insert(15);
	//avl.insert(50);
	//avl.insert(10); //����
	//avl.insert(60);
	//avl.insert(30);
	//avl.insert(65);
	//avl.insert(63);
	//avl.insert(70);
	//avl.insert(79 );//����
	//avl.insert(69);
	//avl.insert(60);
	//avl.insert(70);
	//avl.insert(30);
	//avl.insert(63);
	//avl.insert(62);//����˫��
	vector<int> vec = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (const auto& e : vec)
	{
		avl.insert(e);
	}
	avl.inorder();
	avl.isBalance();
}

int main()
{

	test();
	system("pause");
	return 0;
} 