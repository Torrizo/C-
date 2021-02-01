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

//��ɢ��
//��ϣ���д�Žڵ�ָ��
//ÿһ����ϣ���λ�ö���һ��������
//���в�����ͬ��ϣλ�õ����ݶ������ͬһ����������

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
	//��װ�ڵ�
	Node* _node;
	//��ϣ��ָ��
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
		//�ж�next�Ƿ�Ϊ��
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			//��Ҫ�ҵ���һ���ǿյ������ͷ���
			//���ȼ��㵱ǰ�ڵ��ڹ�ϣ���е�λ��
			keyOfValue kov;
			int idx = kov(_node->_data) % _pht->_ht.size();
			++idx;
			for (; idx < _pht->_ht.size(); ++idx)
			{
				//�ҵ���һ���ǿ������ͷ���
				if (_pht->_ht[idx])
				{
					_node = _pht->_ht[idx];
					break;
				}
			}
			//�ж��Ƿ��ҵ�һ���ǿյ�ͷ���
			if (idx >= _pht->_ht.size())
				_node = nullptr;
		}
		return *this;
	}
};

//��ϣ��
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
		//��һ���ǿ������ͷ���
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
		//�������
		checkCapacity();

		keyOfValue kov;
		//�����ϣλ��
		int idx = kov(data) % _ht.size();

		//�жϵ�ǰ��ϣͰ���Ƿ����key�ظ���Ԫ��
		Node* cur = _ht[idx];

		while (cur)
		{
			if (kov(cur->_data) == kov(data))
				return false;
			cur = cur->_next;
		}

		//�������ͷ��
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
			//��������Ϊ1, ����
			int newC = _ht.size() == 0 ? 10 : 2 * _ht.size();

			//�����µĹ�ϣ��
			vector<Node*> newHt;
			newHt.resize(newC);

			keyOfValue kov;
			//�����ɱ�
			for (int i = 0; i < _ht.size(); ++i)
			{
				//������ǰ��ϣͰ�е�ÿһ��Ԫ��
				Node* cur = _ht[i];
				while (cur)
				{
					Node* next = cur->_next;
					//���㵱ǰ�ڵ���������±��е�λ��
					int idx = kov(cur->_data) % newHt.size();

					//ͷ��
					cur->_next = newHt[idx];
					newHt[idx] = cur;

					cur = next;
				}
				_ht[i] = nullptr;
			}

			//�ɱ��±���н���
			swap(_ht, newHt);
		}
	}

	Node* find(const K& key)
	{
		//����λ��
		int idx = key % _ht.size();
		Node* cur = _ht[idx];
		KeyOfValue kov;
		while (cur)
		{
			//����keyֵ���бȽ�
			if (kov(cur->_data) == key)
				return cur;
			cur = cur->_next;
		}
		return nullptr;
	}

	bool erase(const K& key)
	{
		//���ʣ�������ɾ��
		int idx = key % _ht.size();
		keyOfValue kov;
		Node* cur = _ht[idx];
		Node* prev = nullptr;
		while (cur)
		{
			if (kov(cur->_data) == key)
			{
				//ɾ��
				//�ж��Ƿ�Ϊͷ���
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
	//		//��������Ϊ1, ����
	//		int newC = _ht.size() == 0 ? 10 : 2 * _ht.size();

	//		//�����µĹ�ϣ��
	//		HashTable<K, V, keyOfValue> newHt(newC);
	//		//�����ɱ�
	//		for (int i = 0; i < _ht.size(); ++i)
	//		{
	//			//������ǰ��ϣͰ�е�ÿһ��Ԫ��
	//			Node* cur = _ht[i];
	//			while (cur)
	//			{
	//				Node* next = cur->_next;
	//				//���±��д����ڵ㣬�ͷžɱ��еĽڵ㣬Ч�ʵ�
	//				newHt.insert(cur->_data);  //new �ڵ�
	//				//�ͷŵ�ǰ�ڵ�
	//				delete cur;
	//				cur = next;
	//			}
	//			_ht[i] = nullptr;
	//		}

	//		//�ɱ��±���н���
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
