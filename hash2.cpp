#include<vector>
#include<iostream>
using namespace std;
//开散列
//哈希表中存放节点指针
//每一个哈希表的位置都是一个单链表
//所有产生相同哈希位置的数据都会存入同一个单链表

template <class K>
struct KeyOfValue
{
	const K& operator(const);
};

template <class V>
struct HashNode
{
	V _data;
	HashNode<V>* _next;

	HashNode(const V& data)
		:_data(data)
		,_next(nullptr)
	{ }
};

template < class V ,class K, class KeyOfValue>
struct _HashIterator
{
	typedef HashNode<V> Node;
	tyoedef _HashIterator<V> Self;
	typedef HashTable<K, V, KeyOfValue> hTable
	//封装节点
	Node* _node;
	_HashIterator(Node* node)
		:_node(node)
	{ }

	v& operator()
	{
		return _node->data;
	}
	v* operator->()
	{
		return &_node->_data;
	}
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}
	Self& operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			//需要找到下一个非空单链表头结点
			//首先计算当前节点所在的哈希表的位置
			KeyOfValue kov;
			int idx = kov(_node->_data) % _pht->_ht.size();
			++idx;
			for (; idx < _pht->_ht.size(); ++idx)
			{
				_node = _pht->_ht[idx];
				break;

			}
			//判断是否找到一个非空的头结点
			if (idx >= _pht->_ht.size())
				_node = nullptr;
		}
		return *this;
	}
};

//哈希表
template <class K, class V, class keyOfValue>
class HashTable
{
public:
	typedef HashNode<V> Node;

	typedef _HashIterator<K, V, KeyOfValue> iterator
	HashTable(size_t n = 10)
	{
		_ht.resize(n);
	}

	iterator begin()
	{
		//第一个非空链表的头节点
		for (this i = 0; i < _ht.size(); ++i)
		{
			if (_ht[i])
				return iterator(_ht[i], this);
		}
		return iterator(nullptr, this;)
	}

	bool insert(const V& data)
	{
		//检查容量
		 checkCapacity();

		KeyOfValue kov;
		//计算哈希位置
		int idx = kov(data) % _ht.size();

		//判断当前哈希冲突是否存在key重复的元素
		Node* cur = _ht[idx];

		while (cur)
		{
			Node* next = cur->_next;
			if (kov(cur->_data) == kov(data))
				return false;
			cur = cur->_next;
		}

		//单链表的头插
		cur = new Node(data);
		cur->_next = ht[idx];
		_ht[idx] = cur;
		++_size;
		return true;
	}

	//void checkCapacity()
	//{
	//	if (size == _ht.size())
	//	{
	//		//负载因子为1,增容
	//		int newC = _ht.size() == 0 ? 10 : 2 * _ht.size();

	//		//创建新的哈希表
	//		HashTable<K, V, KeyOfValye> newHt(newC);
	//		//遍历旧表
	//		for (int i = 0; i < _ht.size(); ++i)
	//		{
	//			Node* next = cur;
	//			while (cur)
	//			{
	//				Node* next = cur;
	//				//在新表中创建节点，释放旧表中的节点，效率低
	//				newHt.insert(cur->_data); //new 节点
	//				//释放当前节点
	//				delete cur;
	//				cur = next;
	//			}
	//			_ht[i] = nullptr;
	//		}

	//		//旧表进行交换
	//		swap(_ht, newHt._ht);
	//	}
	//}
	int checkCapacity()
	{
		if (size == _ht.size())
		{
			//负载因子为1,增容
			int newC = _ht.size() == 0 ? 10 : 2 * _ht.size();

			//创建新的哈希表
			vector<Node*>newHt;
			newHt.resize(newC);
			KeyOfValue kov;
			//遍历旧表
			for (int i = 0; i < _ht.size(); ++i)
			{
				Node* cur = _ht[i];
				while (cur)
				{
					Node* next = cur->_next;
					//遍历当前哈希桶中的媒体个元素
					int idx = kov(cur->_data) % newHt.size();

					//头插
					cur->_next = newHt[idx];
					newHt[idx] = cur;

					cur = next;
				}
				_ht[i] = nullptr;
			}

			//旧表进行交换
			swap(_ht, newHt._ht);
		}
	}
	Node* find(const K& key)
	{
		int idx = key % _ht.size();
		Key
		Node* cur = _ht[idx];

		while (cur)
		{
			if (kov(cur->data) == key)
				return cur;
			cur = cur->_next;
		}
		return nullptr;
	}

	bool erase(const K& key)
	{
		//本质单链表删除
		int idx = key % _ht.size();
		KeyOfValue kov;
		Node* prev = nullptr;
		Node* cur = _ht[idx];
		while (cur)
		{
			if (kov(cur->_data) == key)
			{
				//删除
				//判断是否为头结点
				if (prev)
					prev->_next = cur->_next;
				else
					_ht[idx] = cur->_next;
				delete cur;
				return true;
			}
			else
			{
				prev = cur;
				cur = cur->_next;
			}
		}
	}

private:
	vector<Node*> _ht;
	size_t _size = 0;
};

void test()
{
	HashTable<int, int, KeyOfValue<int>> ht;
	ht.insert(100);
	ht.insert(20);
	ht.insert(20);
	ht.insert(20);
	ht.insert(20);
	ht.insert(20);
	ht.insert(20);
	ht.insert(20);
	ht.insert(20);
	ht.insert(20);
	ht.insert(20);
}
int main()
{
	test();
	system("pause");
	return 0;
}























