#include<iostream>
#include<vector>
using namespace std;

//开散列
//哈希表中存放节点指针
//每一个哈希表的位置都是一个单链表
//所有产生相同哈希位置的数据会放到同一个链表中


template <class V>
struct HashNode
{
	V _data;
	HashNode<V>* _next;
};


//哈希表
template<class K,class V class KeyOfValue>
class HashTable
{
public:
	typedef HashNode<V> Node;
private:
	vector<Node*> _ht;
	size_t _size = 0;
};