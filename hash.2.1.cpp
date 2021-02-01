#include <vector>
using namespace std;

template<class K>
struct keyOfValue1
{
	const K& operator()(const K& data)
	{
		return data;
	}
};

//开散列
//哈希表中存放节点指针
//每一个哈希表的位置都是一个单链表
//所有产生相同哈希位置的数据都会存入同一个单链表中

template <class V>
struct HashNode
{
	V _data;
	HashNode<V>* _next;

	HashNode(const V& data)
		:_data(data)
		, _next(nullptr)
	{}
};

template <class K, class V, class keyOfValue>
struct _HashIterator
{
	typedef HashNode<V> Node;
	typedef _HashIterator<V> Self;
	typedef HashTable<K, V, keyOfValue> hTable;
	//封装节点
	Node* _node;
	//哈希表指针
	hTable _ht;

	_HashIterator(Node* node, hTable* pht)
		:_node(node)
		, _pht(pht)
	{}

	//*, ->
	V& operator*()
	{
		return _node->_data;
	}

	V* operator->()
	{
		return &_node->_data;
	}
	//!=
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}
	//++
	Self& operator++()
	{
		//判断next是否为空
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			//需要找到下一个非空单链表的头结点
			//首先计算当前节点在哈希表中的位置
			keyOfValue kov;
			int idx = kov(_node->_data) % _pht->_ht.size();
			++idx;
			for (; idx < _pht->_ht.size(); ++idx)
			{
				//找到第一个非空链表的头结点
				if (_pht->_ht[idx])
				{
					_node = _pht->_ht[idx];
					break;
				}
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

	typedef _HashIterator<K, V, keyOfValue> iterator;

	HashTable(size_t n = 10)
	{
		_ht.resize(n);
	}

	iterator begin()
	{
		//第一个非空链表的头结点
		for (int i = 0; i < _ht.size(); ++i)
		{
			if (_ht[i])
				return iterator(_ht[i], this);
		}
		return iterator(nullptr, this);
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	bool insert(const V& data)
	{
		//检查容量
		checkCapacity();

		keyOfValue kov;
		//计算哈希位置
		int idx = kov(data) % _ht.size();

		//判断当前哈希桶中是否存在key重复的元素
		Node* cur = _ht[idx];

		while (cur)
		{
			if (kov(cur->_data) == kov(data))
				return false;
			cur = cur->_next;
		}

		//单链表的头插
		cur = new Node(data);
		cur->_next = _ht[idx];
		_ht[idx] = cur;

		++_size;
		return true;
	}

	void checkCapacity()
	{
		if (_size == _ht.size())
		{
			//负载因子为1, 增容
			int newC = _ht.size() == 0 ? 10 : 2 * _ht.size();

			//创建新的哈希表
			vector<Node*> newHt;
			newHt.resize(newC);

			keyOfValue kov;
			//遍历旧表
			for (int i = 0; i < _ht.size(); ++i)
			{
				//遍历当前哈希桶中的每一个元素
				Node* cur = _ht[i];
				while (cur)
				{
					Node* next = cur->_next;
					//计算当前节点的数据在新表中的位置
					int idx = kov(cur->_data) % newHt.size();

					//头插
					cur->_next = newHt[idx];
					newHt[idx] = cur;

					cur = next;
				}
				_ht[i] = nullptr;
			}

			//旧表新表进行交换
			swap(_ht, newHt);
		}
	}

	Node* find(const K& key)
	{
		//计算位置
		int idx = key % _ht.size();
		Node* cur = _ht[idx];
		KeyOfValue kov;
		while (cur)
		{
			//按照key值进行比较
			if (kov(cur->_data) == key)
				return cur;
			cur = cur->_next;
		}
		return nullptr;
	}

	bool erase(const K& key)
	{
		//本质：单链表删除
		int idx = key % _ht.size();
		keyOfValue kov;
		Node* cur = _ht[idx];
		Node* prev = nullptr;
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
		return false;

	}

	//void checkCapacity()
	//{
	//	if (_size == _ht.size())
	//	{
	//		//负载因子为1, 增容
	//		int newC = _ht.size() == 0 ? 10 : 2 * _ht.size();

	//		//创建新的哈希表
	//		HashTable<K, V, keyOfValue> newHt(newC);
	//		//遍历旧表
	//		for (int i = 0; i < _ht.size(); ++i)
	//		{
	//			//遍历当前哈希桶中的每一个元素
	//			Node* cur = _ht[i];
	//			while (cur)
	//			{
	//				Node* next = cur->_next;
	//				//在新表中创建节点，释放旧表中的节点，效率低
	//				newHt.insert(cur->_data);  //new 节点
	//				//释放当前节点
	//				delete cur;
	//				cur = next;
	//			}
	//			_ht[i] = nullptr;
	//		}

	//		//旧表新表进行交换
	//		swap(_ht, newHt._ht);
	//	}
	//}

private:
	vector<Node*> _ht;
	size_t _size = 0;
};

void test()
{
	HashTable<int, int, keyOfValue1<int>> ht;
	ht.insert(10);
	ht.insert(5);
	ht.insert(1);
	ht.insert(2);
	ht.insert(15);
	ht.insert(21);
	ht.insert(0);
	ht.insert(11);
	ht.insert(12);
	ht.insert(7);
	ht.insert(17);
	ht.insert(36);

	ht.erase(1);
	ht.erase(21);
	ht.erase(7);
}

int main()
{
	test();
	return 0;
}
