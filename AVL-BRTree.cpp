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


	RBTree() //���캯��
		:_header(new Node)
	{
		//��ͷ�Ŀյĺ����
		_header->_left = _header->_right = _header;
	}
private:
	//����һ��ͷ���
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