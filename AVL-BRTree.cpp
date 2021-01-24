#include<iostream>
#include<>
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

					//2.�޸���ɫ
					parent->_color = BLACK;
					grandfather->_color = RED;

					//����
					break;
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

private:
	//����һ��ͷ���
	Node* _header;

};




void test()
{
	BRTree<int, string> rbtree;
	BRTree<string, int> rbtree2;
	rbtree.insert(make_pair(1, "one"));
	rbtree.insert(make_pair(10, "ten"));
	rbtree.insert(make_pair(0, "zero"));
	rbtree.insert(make_pair(5, "five"));

	rbtree2.insert(make_pair("one"), 1);
	rbtree2.insert(make_pair("twe"), 2);
	rbtree2.insert(make_pair("three"), 1);

}

int mian()
{
	test();
	system("pause");
	return 0;
}