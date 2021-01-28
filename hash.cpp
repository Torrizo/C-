#include<utility>
#include<vector>
using namespace std;
//��ɢ�У�����̽��

enum State
{
	EMPTY,
	EXIST,
	DELETE
};

template<class K, class V>
struct HashNode
{
	pair<K, V> _kv = pair<K, V>();
	State _state;

	
};

template<class K, class V>
class HashTable
{
public:
	typedef HashNode<K, V> Node;
	HashTable(size_t n = 5)
		:_size(0)
	{
		_ht.resize(n);
	}
	//����
	bool insert(const pair<K, V>& kv)
	{
		//�������
		checkCapcity();
		//ͨ����������λ��
		int idx = kv.first % _ht.size();
		//�жϵ�ǰ�Ƿ�Ϊ��
		//�����Ϊ�գ��������
		while (_ht[idx]._state != EMPTY)
		{
			//�жϼ�ֵ�Ƿ����
			//�����ǰ״̬��EXITS����ʾ������Ч���鿴��ǰ���ݵļ�ֵ�Ƿ����
			if (_ht[idx]._state == EXIST && _ht[idx].kv.frist == kv.first)
				return false;

			++idx;
			if (idx == _ht.size())
				idx = 0;
		}
		//���Ϊ�գ�ֱ�Ӳ���
		_ht[idx]._kv = kv;
		_ht[idx]._state = EXIST;
		++_size;
		return true;
	}
	void checkCapacity()
	{
		//�������ӣ�Ԫ�ظ��� / �ռ��С
		//����̽�⣬��������һ��С��1��Խ�ӽ�1����ϣ��ͻ��Լ��
		//һ��С��0.7
		if (_size * 10 / _ht.size() >= 7)
		{
			//����
			int newC = _ht.size() == 0 ? 5 : 2 * _ht.size();
			HashTable<K, V>newHT(newC);
			//���²��룺�ռ�ı�֮������λ�ÿ��ܻᷢ���ı�
			//�����ɱ��е�Ԫ�أ�����ЧԪ�ش����±�

			for (int i = 0; i < _ht.size(); ++i)
			{
				if (_ht[i]._state == EXIST)
					newHT.insert(_ht[i]._kv);
			}
			swap(_ht, newHT._ht);
		}
	}

	//����
	Node* find(const K& key)
	{
		//����λ��
		int idx = key & _ht.size();
		while (_ht[idx].state != EMPTY)
		{
			if (_ht[idx]._state == EXIST && _ht[idx].kv.first == key)
				return &_ht[idx];
			++idx;
			if (idx == _ht.size())
				idx = 0;
		}
		return nullptr;
	}


	//ɾ��
	bool erase(const K& key)
	{
		Node* node = find(key);
		if (node)
		{
			//��ɾ�� ֻ�޸�״̬
			node->_state = DELETE;
			--_size;
			cout << key << "delete success" << endl;
			return true;
		}
		cout << key << "delete failed" << endl;
		return false;
	}


private:
	vector<Node> _ht;
	size_t _size;  //��ʾʵ��Ԫ�صĸ���
};