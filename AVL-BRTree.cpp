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
	RBNode(const pair<K, V> kv)
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
private:
	//定义一个头结点
	Node* _header;

};




void test()
{

}

int mian()
{
	test();
	system("pause");
	return 0;
}