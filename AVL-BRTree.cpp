#include<iostream>
#include<utility>
#include<iostream>
using namespace std;
enum COLOR  //ö������
{
	BLACK,
	RED
};
template < class K,class V > 

struct BRTreeNode
{
	RBNode<K, V>* _parent;
	RBNode<K, V>* _left;
	RBNode<K, V>* _right;
	//����Ϊkey-value��ֵ��
	pair < K, V > _kv;
	//�ڵ����ɫ
	//bool _color; //STL��ʵ��
	COLOR _color;

	//�ڵ���ɫĬ��Ϊ��ɫ
	RBNode(const pair<K, V> kv = pair<K,V> kv)
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _kv(kv)
		, _color(RED)
	{}
};

template<class K,class V>
class BRTree
{
public:
	typedef RBNode<K, V> Node;
	//typedef _RBTreeIterator<K, V> iterator;


	RBTree() //���캯��
		:_header(new Node)
	{
		//��ͷ�Ŀյĺ����
		_header->_left = _header->_right = _header;
	}

	bool insert(const pair<K, V>& kv)
	{
		//�������Ĳ���
		//a.����
		if (_header->_parent == nullptr)
		{
			//�������ڵ�
			Node* root = new Node(kv);
			//���ڵ���ɫΪ��
			root->_color = BLACK;
			_header->_parent = root;
			root->_parent = _header;

			_header->_left = _header->_right = root;
			return true;
		}
		//�ǿ���
		Node* parent = nullptr;
		//�Ӹ��ڵ㿪ʼ����
		Node* cur = _header->_parent;
		while (cur)
		{
			parent = cur;
			//ͨ����ֵ�Ƚ�
			if (cur->_kv.first > kv.first)
			{
				cur = cur->_left;
			}
			else if(cur->kv.first < kv.first)
			{
				cur = cur->_right;
			}
			else
				//��ֵ�ظ�������ʧ��
				return false;
		}
		//�²���ڵ����ɫΪ��ɫ
		cur = new Node(kv);
		if (parent->_kv.first>cur->_kv.first)
		{
			parent->_left = cur;
		}
		else
			parent->_right = cur;
		cur->_parent = parent;

		//2.������ɫ/��ת
		while (cur != _header->_parent &&cur->_parent->color == RED)
		{
			Node* parent = cur->_parent;
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;

				//uncle ���� ��Ϊ��
				if (uncle && uncle->_color == RED)
				{
					//�޸�parent��uncle��ɫ
					parent->_color = uncle->_color = BLACK;
					//�޸�grandfather
					grandfather->_color = RED;
					//��������
					cur = grandfather;
				}
				else
				{
					//uncle�����ڣ�����uncle����Ϊ��ɫ
					//1.��ת
					RotateR(grandfather);
					//�ж��Ƿ�Ϊ˫��
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(cur, parent);
						//�˻�������
					}
					//cur,parent��������ҵ�ѡ
					RotateL(grandfather);
					//2.�޸���ɫ

					parent->_color = BLACK;
					grandfather->_color = RED;

					//����
					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_left;
				//uncle������Ϊ��
				if (uncle && uncle->_color == RED)
				{
					//�޸�parent��uncle��ɫ
					parent->_color = uncle->_color = BLACK;
					//�޸�grandfather
					grandfather->_color = RED;
					//��������
					cur = grandfather;
				}

				//uncle������ ���� ������Ϊ��
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(cur, parent);
					}
					RotateL(grandfather);
					parent->_color = BLACK;
					grandfather->_color = RED;
					break;
				}
				else
				{
					Node* uncle = grandfather->_left;

					//uncle
					if (uncle && uncle->_color == RED)
					{
						parent->_color = uncle->_color = BLACK;
						grandfather->_color = RED;
						cur = grandfather;
					}
					else
					{
						if (cur == parent->_left)
						{
							RotateR(parent);
							swap(cur, parent);
						}
						RotateL(grandfather);
						parent->_color = BLACK;
						grandfather->_color = RED;
						break;
					}
				}
			}
		}
		//���ڵ�ʼ���Ǻ�ɫ
		_header->_parent->_color = BLACK;
		_header->_left = leftMost();
		_header->_right = rightMost();
		return true;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		subL->_right = parent;
		parent->_reft = subLR;
		if (subLR)
			subLR->parent = parent;

		if (parent == _header->_parent)
		{
			//subL��Ϊ�µĸ��ڵ�
			_header->_parent = subL;
			subL->_parent = _header;
		}
		else
		{
			Node* g = parent->_parent;
			if (g->_left == parent)
				g->_left = subL;
			else
				g->_right = subL;
			subL->_parent = g;
		}
		parent->_parent = subL;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subL->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
			subRL->parent = parent;

		if (parent == _header->_parent)
		{
			//subR��Ϊ�µĸ��ڵ�
			_header->_parent = subR;
			subR->_parent = _header;
		}
		else
		{
			Node* g = parent->_parent;
			if (g->_left == parent)
				g->_left = subR;
			else
				g->_right = subR;
			subR->_parent = g;
		}
		parent->_parent = subR;
	}
	Node* leftMost()
	{
		Node* cur = _header->_parent;
		while (cur && cur->_left)
			cur = cur->_left;
		return cur;
	}
	Node* rightMost()
	{
		Node* cur = _header->_parent;
		while (cur && cur->_right)
			cur = cur->_right;
		return cur;
	}
	void inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_kv.first << " ";
			_inorder(root->_right);
		}
	}
	void inorder()
	{
		_inorder(_header->_parent);
		cout << endl;
	}

	//�����
	//1.��ɫ��������
	//2.

	bool isRBtree()
	{
		Node* root = _header->_parent;
		if (root == nullptr)
			return true
			//���Ǻ�ɫ
		if (root->_color == RED)
		{
			cout << "�����Ǻ�ɫ" << endl;
			return false;
		}
		Node* cur = root;
		int blackCount = 0;
		while (cur)
		{
			if (cur->_color == BLACK)
				++blackCount;
			cur = cur->_left;
		}
		int k = 0;
		return _isRBtree(root, int k, int blackCount);
	}

	bool _isRBtree(Node* root, int k, int balckCount)
	{
		//ÿ��·����ɫ�ڵ����Ƿ���ͬ
		if (root == nullptr)
		{
			if (k == blackCount)
				return true;
			cout << "��ɫ������ͬ" << endl;
			return false;
		}
		//�鿴��ǰ�ڵ��Ƿ�Ϊ��ɫ
		if (root->_color == BLACK)
			++k;
		//��ɫ�Ƿ�����
		if (root->_parent && root->_color == RED && root->_parent->_color == RED)
		{
			cout << "��ɫ����" << endl;
			return false;
		}
		return  _isRBtree(root->_left, k, blackCount) && _isRBtree(root->_right, k, blackCount);
	}

private:
	//����һ��ͷ���
	Node* _header;

};

//���������������ԭ��ָ�룬��װ�ڵ�
template<class K,class V>
struct _RBTreeIterator
{
	typedef RBNode<K, V> Node;
	typedef _RBNode<k, v> Self;

	//��װ
	Node* _node;
	_RBTreeIterator(Node* node)
		:_node(node)
	{ }
	pair<K, V>& operator*()
	{
		//��ȡ�ڵ��е�����
		return _node->_kv;
	}
	pair<K, V>& operator->()
	{
		//��ȡ�ڵ������ݵ�ָ��
		return &_node->_kv;
	}
	bool operator !=(const Self& it)
	{
		return _node != it._node;
	}
	Self& operator++()
	{
		//�ж��Ƿ���������
		if (node->_right)
		{
			//��һ��Ҫ���ʵĽڵ㣺������������ڵ�
			_node = _node->right;
			while (_node->_left)
				_node = _node->_left;
		}
		else
		{
			//������������
			//��һ�����ʽڵ㣺���ڵ�-->�θ��ڵ�ĺ��ӽڵ㲻�������ҽڵ�
			Node* parent = _node->_parent;
			while (_node == parent->_right)
			{
				_node = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}
		return *this;
	}
	Self& operator--()
	{
		return *this;
	}
};



void test()
{
	BRTree<int, string> brtree;
	BRTree<string, int> brtree2;
	brtree.insert(make_pair(1, "one"));
	brtree.insert(make_pair(10, "ten"));
	brtree.insert(make_pair(0, "zero"));
	brtree.insert(make_pair(5, "five"));

	brtree2.insert(make_pair("one"), 1);
	brtree2.insert(make_pair("twe"), 2);
	brtree2.insert(make_pair("three"), 1);

}

int mian()
{
	test();
	system("pause");
	return 0;
}