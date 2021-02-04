#include<vector>
#include<iostream>
using namespace std;
//��ɢ��
//��ϣ���д�Žڵ�ָ��
//ÿһ����ϣ���λ�ö���һ��������
//���в�����ͬ��ϣλ�õ����ݶ������ͬһ��������

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
	//��װ�ڵ�
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
			//��Ҫ�ҵ���һ���ǿյ�����ͷ���
			//���ȼ��㵱ǰ�ڵ����ڵĹ�ϣ���λ��
			KeyOfValue kov;
			int idx = kov(_node->_data) % _pht->_ht.size();
			++idx;
			for (; idx < _pht->_ht.size(); ++idx)
			{
				_node = _pht->_ht[idx];
				break;

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

	typedef _HashIterator<K, V, KeyOfValue> iterator
	HashTable(size_t n = 10)
	{
		_ht.resize(n);
	}

	iterator begin()
	{
		//��һ���ǿ������ͷ�ڵ�
		for (this i = 0; i < _ht.size(); ++i)
		{
			if (_ht[i])
				return iterator(_ht[i], this);
		}
		return iterator(nullptr, this;)
	}

	bool insert(const V& data)
	{
		//�������
		 checkCapacity();

		KeyOfValue kov;
		//�����ϣλ��
		int idx = kov(data) % _ht.size();

		//�жϵ�ǰ��ϣ��ͻ�Ƿ����key�ظ���Ԫ��
		Node* cur = _ht[idx];

		while (cur)
		{
			Node* next = cur->_next;
			if (kov(cur->_data) == kov(data))
				return false;
			cur = cur->_next;
		}

		//�������ͷ��
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
	//		//��������Ϊ1,����
	//		int newC = _ht.size() == 0 ? 10 : 2 * _ht.size();

	//		//�����µĹ�ϣ��
	//		HashTable<K, V, KeyOfValye> newHt(newC);
	//		//�����ɱ�
	//		for (int i = 0; i < _ht.size(); ++i)
	//		{
	//			Node* next = cur;
	//			while (cur)
	//			{
	//				Node* next = cur;
	//				//���±��д����ڵ㣬�ͷžɱ��еĽڵ㣬Ч�ʵ�
	//				newHt.insert(cur->_data); //new �ڵ�
	//				//�ͷŵ�ǰ�ڵ�
	//				delete cur;
	//				cur = next;
	//			}
	//			_ht[i] = nullptr;
	//		}

	//		//�ɱ���н���
	//		swap(_ht, newHt._ht);
	//	}
	//}
	int checkCapacity()
	{
		if (size == _ht.size())
		{
			//��������Ϊ1,����
			int newC = _ht.size() == 0 ? 10 : 2 * _ht.size();

			//�����µĹ�ϣ��
			vector<Node*>newHt;
			newHt.resize(newC);
			KeyOfValue kov;
			//�����ɱ�
			for (int i = 0; i < _ht.size(); ++i)
			{
				Node* cur = _ht[i];
				while (cur)
				{
					Node* next = cur->_next;
					//������ǰ��ϣͰ�е�ý���Ԫ��
					int idx = kov(cur->_data) % newHt.size();

					//ͷ��
					cur->_next = newHt[idx];
					newHt[idx] = cur;

					cur = next;
				}
				_ht[i] = nullptr;
			}

			//�ɱ���н���
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
		//���ʵ�����ɾ��
		int idx = key % _ht.size();
		KeyOfValue kov;
		Node* prev = nullptr;
		Node* cur = _ht[idx];
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























