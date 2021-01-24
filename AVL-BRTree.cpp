#include<iostream>
#include<>
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

					//2.修改颜色
					parent->_color = BLACK;
					grandfather->_color = RED;

					//结束
					break;
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

private:
	//定义一个头结点
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