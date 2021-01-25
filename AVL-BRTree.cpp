#include<iostream>
#include<utility>
#include<iostream>
using namespace std;
enum COLOR  //枚举类型
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
	//数据为key-value键值对
	pair < K, V > _kv;
	//节点的颜色
	//bool _color; //STL的实现
	COLOR _color;

	//节点颜色默认为红色
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


	RBTree() //构造函数
		:_header(new Node)
	{
		//带头的空的红黑树
		_header->_left = _header->_right = _header;
	}

	bool insert(const pair<K, V>& kv)
	{
		//搜索树的插入
		//a.空树
		if (_header->_parent == nullptr)
		{
			//创建根节点
			Node* root = new Node(kv);
			//根节点颜色为黑
			root->_color = BLACK;
			_header->_parent = root;
			root->_parent = _header;

			_header->_left = _header->_right = root;
			return true;
		}
		//非空树
		Node* parent = nullptr;
		//从根节点开始搜索
		Node* cur = _header->_parent;
		while (cur)
		{
			parent = cur;
			//通过键值比较
			if (cur->_kv.first > kv.first)
			{
				cur = cur->_left;
			}
			else if(cur->kv.first < kv.first)
			{
				cur = cur->_right;
			}
			else
				//键值重复，插入失败
				return false;
		}
		//新插入节点的颜色为红色
		cur = new Node(kv);
		if (parent->_kv.first>cur->_kv.first)
		{
			parent->_left = cur;
		}
		else
			parent->_right = cur;
		cur->_parent = parent;

		//2.调整颜色/旋转
		while (cur != _header->_parent &&cur->_parent->color == RED)
		{
			Node* parent = cur->_parent;
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;

				//uncle 存在 且为红
				if (uncle && uncle->_color == RED)
				{
					//修改parent，uncle颜色
					parent->_color = uncle->_color = BLACK;
					//修改grandfather
					grandfather->_color = RED;
					//继续更新
					cur = grandfather;
				}
				else
				{
					//uncle不存在，或者uncle存在为黑色
					//1.旋转
					RotateR(grandfather);
					//判断是否为双旋
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(cur, parent);
						//退化到单旋
					}
					//cur,parent都在左边右单选
					RotateL(grandfather);
					//2.修改颜色

					parent->_color = BLACK;
					grandfather->_color = RED;

					//结束
					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_left;
				//uncle存在且为红
				if (uncle && uncle->_color == RED)
				{
					//修改parent，uncle颜色
					parent->_color = uncle->_color = BLACK;
					//修改grandfather
					grandfather->_color = RED;
					//继续更新
					cur = grandfather;
				}

				//uncle不存在 或者 存在且为黑
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
		//根节点始终是黑色
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
			//subL作为新的根节点
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
			//subR作为新的根节点
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

	//红黑树
	//1.红色不能连续
	//2.

	bool isRBtree()
	{
		Node* root = _header->_parent;
		if (root == nullptr)
			return true
			//根是黑色
		if (root->_color == RED)
		{
			cout << "跟不是黑色" << endl;
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
		//每条路径黑色节点树是否相同
		if (root == nullptr)
		{
			if (k == blackCount)
				return true;
			cout << "黑色个数不同" << endl;
			return false;
		}
		//查看当前节点是否为黑色
		if (root->_color == BLACK)
			++k;
		//红色是否连续
		if (root->_parent && root->_color == RED && root->_parent->_color == RED)
		{
			cout << "红色连续" << endl;
			return false;
		}
		return  _isRBtree(root->_left, k, blackCount) && _isRBtree(root->_right, k, blackCount);
	}

private:
	//定义一个头结点
	Node* _header;

};

//红黑树迭代器：非原生指针，封装节点
template<class K,class V>
struct _RBTreeIterator
{
	typedef RBNode<K, V> Node;
	typedef _RBNode<k, v> Self;

	//封装
	Node* _node;
	_RBTreeIterator(Node* node)
		:_node(node)
	{ }
	pair<K, V>& operator*()
	{
		//获取节点中的数据
		return _node->_kv;
	}
	pair<K, V>& operator->()
	{
		//获取节点中数据的指针
		return &_node->_kv;
	}
	bool operator !=(const Self& it)
	{
		return _node != it._node;
	}
	Self& operator++()
	{
		//判断是否有右子树
		if (node->_right)
		{
			//下一个要访问的节点：右子树的最左节点
			_node = _node->right;
			while (_node->_left)
				_node = _node->_left;
		}
		else
		{
			//右子树不存在
			//下一个访问节点：父节点-->次父节点的孩子节点不是它的右节点
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